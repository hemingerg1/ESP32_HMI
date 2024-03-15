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

// Thermistor specs
#define THERMISTORNOMINAL 10000
#define TEMPERATURENOMINAL 25
#define B 3977
#define SERIESRESISTOR 3830

unsigned long kaTimer = 0;
unsigned int kaCount = 0;
unsigned long coolDownTimer = 0;
short int ii = 0;
short int temp = 0;

bool heatOn = false;
bool lostHMI = false;
bool heaterStatus = false;
bool fanStatus = false;
bool coolDown = false;

#include "connectionFunc.hpp"
void turnHeaterOn();
void turnHeaterOff();
void heaterCoolDown();
void getStatus();
void getTemp();

void setup()
{
  Serial.begin(115200);

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

  /*************** MQTT Functions ***************/
  // check if MQTT is still connected
  if (!mqtt.connected())
  {
    mqttCon();
  }
  // send and receive MQTT messages
  mqtt.loop();

  /*************** Main Control Functions ***************/
  // mqtt requested heater off
  if (heatOn and kaCount == 0 and !coolDown)
  {
    turnHeaterOff();
  }
  // keep alive timer has expired without refresh so turn heater off
  else if (heatOn and (millis() - kaTimer > 75000) and !coolDown)
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
  else if (!heatOn and kaCount > 0 and !lostHMI and !coolDown)
  {
    turnHeaterOn();
  }

  /*************** Get Current Status Functions ***************/
  if (ii >= 20)
  {
    getTemp();
    if (coolDown)
    {
      heaterCoolDown();
    }
    getStatus();
    ii = 0;
  }

  delay(250);
}

void turnHeaterOn()
{
  Serial.println("Turning heater on");
  digitalWrite(HEATERPIN, HIGH);
  delay(500);
  digitalWrite(FANPIN, HIGH);
  heatOn = true;
}

void turnHeaterOff()
{
  Serial.println("Turning heater off");
  digitalWrite(HEATERPIN, LOW);
  Serial.println("Fan cool down delay");
  coolDown = true;
  coolDownTimer = millis();
}

void heaterCoolDown()
{
  if (temp < 100)
  {
    digitalWrite(FANPIN, LOW);
    Serial.println("Fan off: temp cooled down");
    coolDown = false;
    heatOn = false;
  }
  else if (millis() - coolDownTimer > 90000 and !heaterStatus)
  {
    digitalWrite(FANPIN, LOW);
    Serial.println("Fan off: cooldown timer expired");
    coolDown = false;
    heatOn = false;
  }
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

  /*************** Send status to MQTT ***************/
  if (heaterStatus and fanStatus and heatOn and temp > 100)
  {
    digitalWrite(STATUSPIN, HIGH);
    mqtt.publish("Garage/Mech/Heater/Status", "ON");
  }
  else if (heaterStatus and fanStatus and heatOn)
  {
    mqtt.publish("Garage/Mech/Heater/Status", "Starting");
  }
  else if (fanStatus)
  {
    mqtt.publish("Garage/Mech/Heater/Status", "FanOn");
  }
  else
  {
    digitalWrite(STATUSPIN, LOW);
    mqtt.publish("Garage/Mech/Heater/Status", "OFF");
  }
}

void getTemp()
{
  float r = 0;
  float adc = 0.0;

  // take 5 readings and average them
  for (int i = 0; i < 5; i++)
  {
    adc += analogRead(THERMPIN);
    delay(10);
  }
  adc = adc / 5.0;

  // get resistance of thermistor
  r = (5405.4 / adc) - 1.0;
  r = SERIESRESISTOR / r;

  // calculate temperature
  float steinhart;
  steinhart = r / THERMISTORNOMINAL;                // (R/Ro)
  steinhart = log(steinhart);                       // ln(R/Ro)
  steinhart /= B;                                   // 1/B * ln(R/Ro)
  steinhart += 1.0 / (TEMPERATURENOMINAL + 273.15); // + (1/To)
  steinhart = 1.0 / steinhart;                      // Invert
  steinhart -= 273.15;                              // convert absolute temp to C
  temp = (steinhart * 1.8) + 32;                    // convert to F

  // Serial.print("T: " + String(temp));
  mqtt.publish("Garage/Mech/Heater/Temp", String(temp));
}