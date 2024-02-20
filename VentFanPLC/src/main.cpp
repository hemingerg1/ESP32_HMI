#include <Arduino.h>
#include <WiFi.h>
#include <ESP32Servo.h>
#include <MQTT.h>
#include <secrets.h>

WiFiClient wifiClient;
MQTTClient mqtt;

Servo damper1;
Servo damper2;

#define FANPIN 2
#define DAMPER1PIN 12
#define DAMPER2PIN 13
#define DAMPEROPEN 68
#define DAMPERCLOSED 0

unsigned long kaTimer = 0;
unsigned int kaCount = 0;
bool fanOn = false;
short int ii = 0;

String fanStatus = "off";
String damper1Status = "closed";
String damper2Status = "closed";

#include "connectionFunc.hpp"
void turnFanOn();
void turnFanOff();
void getStatus();

void setup()
{
  Serial.begin(115200);
  Serial.println(F("****** Initializing PLC ******"));

  pinMode(FANPIN, OUTPUT);

  turnFanOff();

  wificon();
  mqttCon();
}

void loop()
{
  ii++;

  // check if MQTT is still connected
  if (!mqtt.connected())
  {
    mqttCon();
  }
  // send and receive MQTT messages
  mqtt.loop();

  // keep alive timer has expired without refresh so turn fan off
  if (fanOn and (millis() - kaTimer > 75000))
  {
    turnFanOff();
  }
  // mqtt requested fan off
  else if (fanOn and kaCount == 0)
  {
    turnFanOff();
  }
  // mqtt requested fan on
  else if (!fanOn and kaCount > 0)
  {
    turnFanOn();
  }

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
  delay(500);
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
  delay(1000);
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
    fanStatus = "on";
  }
  else
  {
    fanStatus = "off";
  }

  if (fanStatus == "on" and fanOn)
  {
    mqtt.publish("Garage/Mech/VentFan/Status", "ON");
  }
  else if (fanStatus == "off" and !fanOn)
  {
    mqtt.publish("Garage/Mech/VentFan/Status", "OFF");
  }
  else
  {
    mqtt.publish("Garage/Mech/VentFan/Status", "ERROR");
  }
}