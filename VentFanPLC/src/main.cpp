#include <Arduino.h>
#include <WiFi.h>
#include <ESP32Servo.h>
#include <MQTT.h>
#include <esp_task_wdt.h>
#include <secrets.h>

WiFiClient wifiClient;
MQTTClient mqtt;

Servo damper1;
Servo damper2;

#define WDT_TIMEOUT 30 // seconds
#define FANPIN 16
#define DAMPER1PIN 26
#define DAMPER2PIN 33
#define DAMPEROPEN 68
#define DAMPERCLOSED 0

unsigned long kaTimer = 0;
unsigned int kaCount = 0;
bool kaStatus = false;
unsigned long now = 0;
bool fanOn = false;
bool fanStatus = false;
bool lostHMI = false;
short int ii = 0;

#include "connectionFunc.hpp"
void turnFanOn();
void turnFanOff();
void getKaStatus();
void getStatus();

void setup()
{
  Serial.begin(115200);

  esp_task_wdt_init(WDT_TIMEOUT, true); // enable panic so ESP32 restarts
  esp_task_wdt_add(NULL);               // add current thread to WDT watch

  pinMode(FANPIN, OUTPUT);
  pinMode(DAMPER1PIN, OUTPUT);
  pinMode(DAMPER2PIN, OUTPUT);

  turnFanOff();

  wificon();
  mqttCon();
  esp_task_wdt_reset();
}

void loop()
{
  ii++;

  /*************** MQTT Functions ***************/
  // check if MQTT is still connected
  if (!mqtt.connected())
  {
    mqttCon();
  }
  // send and receive MQTT messages
  mqtt.loop();
  delay(10); // <- fixes some issues with WiFi stability
  /*************** Main Control Functions ***************/
  getKaStatus();
  // mqtt requested fan off
  if (fanOn and kaCount == 0)
  {
    turnFanOff();
    mqtt.publish("Garage/Mech/VentFan/Log", "Main control: request off");
  }
  // keep alive timer has expired without refresh so turn fan off
  else if (fanOn and !kaStatus)
  {
    Serial.println("Keep alive timer expired without refresh. Lost HMI control.");
    mqtt.publish("Garage/Mech/VentFan/Log", "Main control: KaTimer expired");
    turnFanOff();
    lostHMI = true;
  }
  // HMI reconnected
  else if (lostHMI)
  {
    if (kaStatus or kaCount == 0)
    {
      Serial.println("HMI regained control.");
      mqtt.publish("Garage/Mech/VentFan/Log", "Main control: HMI back");
      lostHMI = false;
    }
  }
  // mqtt requested fan on
  else if (!fanOn and kaCount > 0 and !lostHMI and kaStatus)
  {
    turnFanOn();
    mqtt.publish("Garage/Mech/VentFan/Log", "Main control: request on");
  }

  /*************** Get Current Status Functions ***************/
  if (ii >= 20)
  {
    getStatus();
    ii = 0;
  }

  esp_task_wdt_reset();
  vTaskDelay(250);
}

void turnFanOn()
{
  Serial.println("Turning fan on");
  // open damper1
  damper1.attach(DAMPER1PIN);
  for (int i = DAMPERCLOSED; i <= DAMPEROPEN; i += 1)
  {
    damper1.write(i);
    delay(10);
  }
  damper1.detach();
  delay(50);

  // open damper2
  damper2.attach(DAMPER2PIN);
  for (int i = DAMPERCLOSED; i <= DAMPEROPEN; i += 1)
  {
    damper2.write(i);
    delay(10);
  }
  damper2.detach();
  delay(100);

  // turn on fan
  digitalWrite(FANPIN, HIGH);
  fanOn = true;
}

void turnFanOff()
{
  Serial.println("Turning fan off");
  // turn off fan
  digitalWrite(FANPIN, LOW);
  delay(2000);
  // close dampers
  damper1.attach(DAMPER1PIN);
  for (int i = DAMPEROPEN; i >= DAMPERCLOSED; i -= 1)
  {
    damper1.write(i);
    delay(10);
  }
  damper1.detach();
  delay(50);
  damper2.attach(DAMPER2PIN);
  for (int i = DAMPEROPEN; i >= DAMPERCLOSED; i -= 1)
  {
    damper2.write(i);
    delay(10);
  }
  damper2.detach();
  fanOn = false;
}

// check the keap alive timer
void getKaStatus()
{
  now = millis();

  if (now < kaTimer) // millis() has rolled over
  {
    kaTimer = now;
  }

  if (now - kaTimer > 75000) // keep alive timer has expired
  {
    kaStatus = false;
  }
  else if (now - kaTimer < 60000) // keep alive timer has not expired
  {
    kaStatus = true;
  }
}

void getStatus()
{
  if (digitalRead(FANPIN) == HIGH)
  {
    fanStatus = true;
  }
  else
  {
    fanStatus = false;
  }

  if (fanStatus and fanOn)
  {
    mqtt.publish("Garage/Mech/VentFan/Status", "ON");
  }
  else if (!fanStatus and !fanOn)
  {
    mqtt.publish("Garage/Mech/VentFan/Status", "OFF");
  }
  else
  {
    mqtt.publish("Garage/Mech/VentFan/Status", "ERROR");
  }
}