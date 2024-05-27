#include <Arduino.h>
#include <WiFi.h>
#include <MQTT.h>
#include <Preferences.h>
#include <InfluxDbClient.h>
#include <algorithm>
#include <ESP32Time.h>
#include "LGFX_sunton_ESP32_8048S070C.h"

#include <lv_conf.h>
#include <lvgl.h>
#include <secrets.h>

Preferences prefs;
LGFX gfx;
WiFiClient wifiClient;
MQTTClient mqtt;
ESP32Time rtc(0);

String mylog;
bool start = true;

// Chart variables
short int chartLen = 6;
String meas = F("Temperature");
short int soft_min = 40;
short int soft_max = 75;
lv_coord_t data_array[1000];

// screen timeout variables
short int lMin = 0;
short int screenTimeout = 10;
bool screenSleep = false;

// Vent fan variables
unsigned long manVentFanTimer;
unsigned long autoVentFanOnTimer = 0;
unsigned long autoVentFanOffTimer = 0;
bool ventFanEnabled = true;
bool manVentFanCon = false;
bool reqVentFan = false;
short int ventFanKeepAlive = 0;
unsigned long ventFanKATimer = 0;
short int aq = 100;
String ventFanState = F("--");
short int tarMaxTemp = 75;
short int tarMinTemp = 55;
short int absMinTemp = 40;
short int fanOnTempTime = 5;
short int fanOffTempTime = 30;
short int aqFanOnLevel = 50;
short int aqFanOnTime = 5;
short int aqFanOffTime = 30;

// temperature variables
short int insideTemp = 100;
short int outsideTemp = 0;
short int tempControl = 0; // 0 = off, 1 = vent fan, 2 = electric heater
unsigned long manHeatTimer;
short int manHeatTemp = 60;
bool heaterEnabled = true;
bool manHeatCon = false;
bool reqHeat = false;
String heaterState = F("--");
short int heatKeepAlive = 0;
unsigned long heatKATimer = 0;

// timer variables
short int secR;
short int minR;

#include "ui/ui.h"
#include "guiFunctions/gui.h"

#include "guiFunctions/logFunc.h"
#include "guiFunctions/InfluxFunc.h"
#include "guiFunctions/mqttFunc.h"
#include "guiFunctions/mechanicalFunc.h"
#include "guiFunctions/ScrHomeFunc.h"
#include "guiFunctions/ScrChartFunc.h"
#include "guiFunctions/ScrSettingsFunc.h"

#define TZ_INFO "EST+5EDT,M3.2.0/2,M11.1.0/2"

void setup()
{
    Serial.begin(115200);
    Serial.println(F("****** Initializing HMI ******"));

    // start the LVGL gui
    gui_start();
    lv_obj_clear_flag(ui_StartLog, LV_OBJ_FLAG_HIDDEN); // Show the start log screen
    logAdd(true, F("GUI started."));

    // Setup wifi (from ScrSettingsFunc.h)
    wificon(NULL);

    // sync time with ntp server
    logAdd(true, F("Syncing time..."));
    timeSync(TZ_INFO, "time1.google.com", "time2.google.com");
    logAdd(true, "Time synced to: " + rtc.getDateTime());

    // check connection to influxdb
    logAdd(true, F("Checking InfluxDB connection..."));
    influxConnect();

    // connect to mqtt broker (from ScrSettingsFunc.h)
    mqttCon(NULL);
    // initialize the chart data (from ScrChartFunc.h)
    chartDataInt();
    // initialize the values on the settings screens (from ScrSettingsFunc.h)
    settingsInit();
    // initialize the values on the home screen (from ScrHomeFunc.h)
    homeInit();
    // initialize the mechaincals (from mechanicalFunc.h)
    mechInit();

    // delay then hide the start log screen
    delay(1000);
    lv_obj_add_flag(ui_StartLog, LV_OBJ_FLAG_HIDDEN);

    // set sleep screen time to custom font
    lv_obj_set_style_text_font(ui_sleepTimeLab, &montserrat_250, LV_PART_MAIN | LV_STATE_DEFAULT);

    start = false;
    logAdd(true, F("********* HMI Initialization complete *********"));
    /*
    Serial.printf("Total heap: %d \n", ESP.getHeapSize());
    Serial.printf("Free heap: %d \n", ESP.getFreeHeap());
    Serial.printf("Total PSRAM: %d \n", ESP.getPsramSize());
    Serial.printf("Free PSRAM: %d \n", ESP.getFreePsram());
    */
}

void loop()
{
    lv_timer_handler();

    // update the time on screen (from ScrHomeFunc.h)
    updateTime();

    // check if MQTT is still connected
    if (!mqtt.connected())
    {
        mqttCon(NULL);
    }
    // send and receive MQTT messages
    mqtt.loop();

    // check mechaicals (fan, heater) for on/off
    mechLoop();

    // check for inactivity
    displaySleep();

    if (screenSleep)
    {
        delay(200);
    }
    else
    {
        delay(20);
    }
}