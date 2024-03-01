#include <Arduino.h>
#include <WiFi.h>
#include <MQTT.h>
#include <secrets.h>

WiFiClient wifiClient;
MQTTClient mqtt;

#define HEATERPIN 7
#define FANPIN 9
#define STATUSPIN 15

unsigned long kaTimer = 0;
unsigned int kaCount = 0;
bool heatOn = false;
bool lostHMI = false;
short int ii = 0;

bool heaterStatus = false;
bool fanStatus = false;

#include "connectionFunc.hpp"
void turnHeaterOn();
void turnHeaterOff();
void getStatus();

void setup()
{
  Serial.begin(115200);
  delay(2000);
  Serial.println("****** Initializing PLC ******");

  pinMode(HEATERPIN, OUTPUT);
  pinMode(FANPIN, OUTPUT);
  pinMode(STATUSPIN, OUTPUT);
  digitalWrite(HEATERPIN, LOW);
  digitalWrite(FANPIN, LOW);
  digitalWrite(STATUSPIN, LOW);

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

  // mqtt requested heater off
  if (heatOn and kaCount == 0)
  {
    turnHeaterOff();
  }
  // keep alive timer has expired without refresh so turn heater off
  else if (heatOn and (millis() - kaTimer > 75000))
  {
    Serial.println("Keep alive timer expired without refresh. Lost HMI control.");
    turnHeaterOff();
    lostHMI = true;
  }
  // HMI reconnected
  else if (lostHMI and kaCount == 0)
  {
    Serial.println("HMI regained control.");
    lostHMI = false;
  }
  // mqtt requested heater on
  else if (!heatOn and kaCount > 0 and !lostHMI)
  {
    turnHeaterOn();
  }

  if (ii >= 20)
  {
    getStatus();
    ii = 0;
  }
  delay(250);
}

void turnHeaterOn()
{
  Serial.println("Turning heater on");
  digitalWrite(HEATERPIN, HIGH);
  delay(1000);
  digitalWrite(FANPIN, HIGH);
  heatOn = true;
}

void turnHeaterOff()
{
  Serial.println("Turning heater off");
  // turn off heating element off
  digitalWrite(HEATERPIN, LOW);
  // leave fan on too cool heater down befor turning off
  Serial.println("Fan cool down delay");
  delay(30000);
  digitalWrite(FANPIN, LOW);
  Serial.println("Fan off");
  heatOn = false;
}

void getStatus()
{
  // Serial.println("Getting status");
  if (digitalRead(HEATERPIN) == HIGH)
  {
    heaterStatus = true;
  }
  else
  {
    heaterStatus = false;
  }

  if (digitalRead(FANPIN) == HIGH)
  {
    fanStatus = true;
  }
  else
  {
    fanStatus = false;
  }

  if (heaterStatus and fanStatus and heatOn)
  {
    digitalWrite(STATUSPIN, HIGH);
    mqtt.publish("Garage/Mech/Heater/Status", "ON");
  }
  else if (fanStatus)
  {
    mqtt.publish("Garage/Mech/Heater/Status", "FAN ON");
  }
  else
  {
    digitalWrite(STATUSPIN, LOW);
    mqtt.publish("Garage/Mech/Heater/Status", "OFF");
  }
}