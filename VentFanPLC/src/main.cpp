#include <Arduino.h>
#include <WiFi.h>
#include <Servo.h>
#include <MQTT.h>
#include <secrets.h>

WiFiClient wifiClient;
MQTTClient mqtt;

#include "connectionFunc.hpp"

Servo damper1;
Servo damper2;

#define FANPIN 10
#define DAMPER1PIN 12
#define DAMPER2PIN 13
#define DAMPEROPEN 100
#define DAMPERCLOSED 90

unsigned long kaTimer = 0;
unsigned int kaCount = 0;
bool fanOn = false;
short int ii = 0;

String fanStatus = "off";
String damper1Status = "closed";
String damper2Status = "closed";

void turnFanOn();
void turnFanOff();
void getStatus();

void setup()
{
  Serial.begin(115200);
  Serial.println(F("****** Initializing PLC ******"));

  pinMode(FANPIN, OUTPUT);
  damper1.attach(DAMPER1PIN);
  damper2.attach(DAMPER2PIN);

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
  for (int i = 0; i <= DAMPEROPEN; i += 2)
  {
    damper1.write(i);
    damper2.write(i);
    delay(10);
  }
  delay(1000);
  // turn on fan
  digitalWrite(FANPIN, HIGH);

  fanOn = true;
}

void turnFanOff()
{
  Serial.println("Turning fan off");
  // turn off fan
  digitalWrite(FANPIN, LOW);
  delay(1000);
  // close dampers
  for (int i = 0; i >= DAMPERCLOSED; i -= 2)
  {
    damper1.write(i);
    damper2.write(i);
    delay(10);
  }

  fanOn = false;
}

void getStatus()
{
  Serial.println("Getting statuses");

  if (digitalRead(FANPIN) == HIGH)
  {
    fanStatus = "on";
  }
  else
  {
    fanStatus = "off";
  }

  if (damper1.read() > DAMPEROPEN - 5)
  {
    damper1Status = "open";
  }
  else if (damper1.read() < DAMPERCLOSED + 5)
  {
    damper1Status = "closed";
  }
  else
  {
    damper1Status = "ERROR";
  }

  if (damper2.read() > DAMPEROPEN - 5)
  {
    damper2Status = "open";
  }
  else if (damper2.read() < DAMPERCLOSED + 5)
  {
    damper2Status = "closed";
  }
  else
  {
    damper2Status = "ERROR";
  }

  Serial.println("  Fan status: " + fanStatus);
  Serial.println("  Damper 1 status: " + damper1Status);
  Serial.println("  Damper 2 status: " + damper2Status);

  if (fanStatus == "on" and damper1Status == "open" and damper2Status == "open")
  {
    mqtt.publish("Garage/Mech/VentFan/Status", "ON");
  }
  else if (fanStatus == "off" and damper1Status == "closed" and damper2Status == "closed")
  {
    mqtt.publish("Garage/Mech/VentFan/Status", "OFF");
  }
  else
  {
    mqtt.publish("Garage/Mech/VentFan/Status", "ERROR");
  }
}