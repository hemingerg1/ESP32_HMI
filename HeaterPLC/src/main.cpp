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
bool kaStatus = false;
unsigned long now = 0;
unsigned long coolDownTimer = 0;
short int ii = 0;
short int temp = 0;

bool heatOn = false;
bool lostHMI = false;
bool heaterStatus = false;
bool fanStatus = false;
bool coolDown = false;

// String mqttMes = "";

#include "connectionFunc.hpp"
void turnHeaterOn();
void turnHeaterOff();
void heaterCoolDown();
void getKaStatus();
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
  if (!mqtt.connected())
  {
    mqttCon();
  }
  // send and receive MQTT messages.
  mqtt.loop();
  delay(10); // <- fixes some issues with WiFi stability
  /*************** Main Control Functions ***************/
  getKaStatus();
  // mqtt requested heater off
  if (heatOn and kaCount == 0 and !coolDown)
  {
    turnHeaterOff();
    mqtt.publish("Garage/Mech/Heater/Log", "Main control: request off");
  }
  // keep alive timer has expired without refresh so turn heater off
  else if (heatOn and !kaStatus and !coolDown)
  {
    Serial.println("Keep alive timer expired without refresh. Lost HMI control.");
    mqtt.publish("Garage/Mech/Heater/Log", "Main control: KaTimer expired");
    turnHeaterOff();
    lostHMI = true;
  }
  // HMI reconnected
  else if (lostHMI)
  {
    if (kaStatus or kaCount == 0)
    {
      Serial.println("HMI regained control.");
      mqtt.publish("Garage/Mech/Heater/Log", "Main control: HMI back");
      lostHMI = false;
    }
  }
  // mqtt requested heater on
  else if (!heatOn and kaCount > 0 and !lostHMI and !coolDown and kaStatus)
  {
    turnHeaterOn();
    mqtt.publish("Garage/Mech/Heater/Log", "Main control: reuest on");
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
    // mqttMes = "kaCount: " + String(kaCount) + ", lostHMI: " + String(lostHMI) + ", heatOn: " + String(heatOn) + ", coolDown: " + String(coolDown);
    // mqtt.publish("Garage/Mech/Heater/Log", mqttMes);
    ii = 0;
  }

  vTaskDelay(250);
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
  if (temp < 80)
  {
    digitalWrite(FANPIN, LOW);
    Serial.println("Fan off: temp cooled down");
    mqtt.publish("Garage/Mech/Heater/Log", "Cool down: temp cooled down");
    coolDown = false;
    heatOn = false;
  }
  else if (millis() - coolDownTimer > 90000 and !heaterStatus)
  {
    digitalWrite(FANPIN, LOW);
    Serial.println("Fan off: cooldown timer expired");
    mqtt.publish("Garage/Mech/Heater/Log", "Cool down: timer expired");
    coolDown = false;
    heatOn = false;
  }
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
  if (heaterStatus and fanStatus and heatOn and temp > 90)
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
  adc = (adc * 2.5) / 4095.0;
  // Serial.print("V: " + String(adc));

  // get resistance of thermistor
  r = (3.3 / adc) - 1.0;
  r = SERIESRESISTOR * r;
  // Serial.print(",  R: " + String(r));

  // calculate temperature
  float steinhart;
  steinhart = r / THERMISTORNOMINAL;                // (R/Ro)
  steinhart = log(steinhart);                       // ln(R/Ro)
  steinhart /= B;                                   // 1/B * ln(R/Ro)
  steinhart += 1.0 / (TEMPERATURENOMINAL + 273.15); // + (1/To)
  steinhart = 1.0 / steinhart;                      // Invert
  steinhart -= 273.15;                              // convert absolute temp to C
  temp = (steinhart * 1.8) + 32 - 2;                // convert to F (-2 is correction factor my sensor)
  // Serial.println(",  T: " + String(temp));

  // Serial.print("T: " + String(temp));
  mqtt.publish("Garage/Mech/Heater/Temp", String(temp));
}