#include <Arduino.h>
#include <WiFi.h>
#include <MQTT.h>
#include <InfluxDbClient.h>
#include <algorithm>
#include <ESP32Time.h>

#include <lv_conf.h>
#include <lvgl.h>
#include <secrets.h>

WiFiClient wifiClient;
MQTTClient mqtt;

String mylog;

// Chart variables
int chartLen = 6;
String meas = "Temperature";
int soft_min = 40;
int soft_max = 75;
lv_coord_t data_array[1000];

ESP32Time rtc(0);
unsigned long ventFanTimer;
String ventFantState = "--";

#include "ui/ui.h"
#include "guiFunctions/gui.h"

#include "guiFunctions/logFunc.h"
#include "guiFunctions/InfluxFunc.h"
#include "guiFunctions/mqttFunc.h"
#include "guiFunctions/ScrHomeFunc.h"
#include "guiFunctions/ScrChartFunc.h"
#include "guiFunctions/ScrSettingsFunc.h"

#define TZ_INFO "EST+5EDT,M3.2.0/2,M11.1.0/2"

void setup()
{
    Serial.begin(115200);
    Serial.println("****** Initializing HMI ******");

    // start the LVGL gui
    gui_start();
    logAdd(false, "GUI started.");

    // Setup wifi (from ScrSettingsFunc.h)
    wificon(NULL);

    // sync time with ntp server
    logAdd(false, "Syncing time...");
    timeSync(TZ_INFO, "pool.ntp.org", "time.nis.gov");
    logAdd(false, "Time synced to: " + rtc.getDateTime());

    // check connection to influxdb
    logAdd(true, "Checking InfluxDB connection...");
    influxConnect();

    // connect to mqtt broker (from ScrSettingsFunc.h)
    mqttCon(NULL);

    // initialize the chart data (from ScrChartFunc.h)
    chartDataInt();

    // delay then hide the start log screen
    delay(2000);
    lv_obj_add_flag(ui_StartLog, LV_OBJ_FLAG_HIDDEN);
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

    // check if the vent fan should be on or off
    ventFanTimerCheck();

    delay(20);
}

/* colors

#F2F2F2;

#A6A6A6;

#595959;

#262626;

#0D0D0D;

*/