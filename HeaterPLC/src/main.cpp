#include <Arduino.h>
#include <WiFi.h>
#include <MQTT.h>
#include <secrets.h>

WiFiClient wifiClient;
MQTTClient mqtt;

#define HEATERPIN 35
#define FANPIN 18
#define STATUSPIN 15
#define THERMPIN 5

// coefficients for converstion of volts to temperature in F
#define C1 -24.7470
#define C2 130.0242
#define C3 -245.2369
#define C4 254.0483
#define C5 -32.2890

unsigned long kaTimer = 0;
unsigned int kaCount = 0;
bool heatOn = false;
bool lostHMI = false;
short int ii = 0;
short int temp = 0;

bool heaterStatus = false;
bool fanStatus = false;

#include "connectionFunc.hpp"
void turnHeaterOn();
void turnHeaterOff();
void getStatus();
void getTemp();

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

  analogReadResolution(12);
  pinMode(THERMPIN, INPUT);

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
    Serial.println(", RSSI: " + String(WiFi.RSSI()));
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

  getTemp();

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

void getTemp()
{
  float V = 0.0;
  float Vsum = 0.0;
  for (int i = 0; i < 5; i++)
  {
    Vsum += analogRead(THERMPIN);
  }
  Vsum = Vsum / 5.0;
  V = (Vsum * 2.5) / 4095.0;
  temp = round(V * (V * (V * (V * C1 + C2) + C3) + C4) + C5);

  Serial.print("T: " + String(temp));
  mqtt.publish("Garage/Mech/Heater/Temp", String(temp));
}