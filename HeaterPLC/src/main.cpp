#include <Arduino.h>
#include <WiFi.h>
#include <MQTT.h>
#include <secrets.h>

WiFiClient wifiClient;
MQTTClient mqtt;

#define HEATERPIN 2
#define FANPIN 12

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
  Serial.println(F("****** Initializing PLC ******"));

  pinMode(HEATERPIN, OUTPUT);
  pinMode(FANPIN, OUTPUT);
  digitalWrite(HEATERPIN, LOW);
  digitalWrite(FANPIN, LOW);

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
  delay(30000);
  digitalWrite(FANPIN, LOW);
  heatOn = false;
}

void getStatus()
{
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
    mqtt.publish("Garage/Mech/VentFan/Status", "ON");
  }
  else if (fanStatus)
  {
    mqtt.publish("Garage/Mech/VentFan/Status", "FAN ON");
  }
  else
  {
    mqtt.publish("Garage/Mech/VentFan/Status", "OFF");
  }
}