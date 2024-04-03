#include <Arduino.h>
#include <WiFi.h>
#include <ESP32Servo.h>
#include <MQTT.h>
#include <secrets.h>

WiFiClient wifiClient;
MQTTClient mqtt;

Servo damper1;
Servo damper2;

#define FANPIN 16
#define DAMPER1PIN 26
#define DAMPER2PIN 33
#define DAMPEROPEN 68
#define DAMPERCLOSED 0

unsigned long kaTimer = 0;
unsigned int kaCount = 0;
bool fanOn = false;
bool fanStatus = false;
bool lostHMI = false;
short int ii = 0;

#include "connectionFunc.hpp"
void turnFanOn();
void turnFanOff();
void getStatus();

void setup()
{
  Serial.begin(115200);

  pinMode(FANPIN, OUTPUT);

  turnFanOff();

  wificon();
  mqttCon();
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

  /*************** Main Control Functions ***************/
  // mqtt requested fan off
  if (fanOn and kaCount == 0)
  {
    turnFanOff();
  }
  // keep alive timer has expired without refresh so turn fan off
  else if (fanOn and (millis() - kaTimer > 75000))
  {
    Serial.println("Keep alive timer expired without refresh. Lost HMI control.");
    turnFanOff();
    lostHMI = true;
  }
  // HMI reconnected
  else if (lostHMI and kaCount == 0)
  {
    Serial.println("HMI regained control.");
    lostHMI = false;
  }
  // mqtt requested fan on
  else if (!fanOn and kaCount > 0 and !lostHMI)
  {
    turnFanOn();
  }

  /*************** Get Current Status Functions ***************/
  if (ii >= 20)
  {
    getStatus();
    ii = 0;
  }

  delay(250);
}

void turnFanOn()
{
  Serial.println("Turning fan on");
  // open dampers
  damper1.attach(DAMPER1PIN);
  damper2.attach(DAMPER2PIN);
  for (int i = DAMPERCLOSED; i <= DAMPEROPEN; i += 1)
  {
    damper1.write(i);
    damper2.write(i);
    delay(10);
  }
  delay(100);
  // turn on fan
  digitalWrite(FANPIN, HIGH);
  damper1.detach();
  damper2.detach();
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
  damper2.attach(DAMPER2PIN);
  for (int i = DAMPEROPEN; i >= DAMPERCLOSED; i -= 1)
  {
    damper1.write(i);
    damper2.write(i);
    delay(10);
  }
  damper1.detach();
  damper2.detach();
  fanOn = false;
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