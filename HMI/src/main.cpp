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

#include "ui/ui.h"
#include "guiFunctions/gui.h"

#include "guiFunctions/logFunc.h"
#include "guiFunctions/InfluxFunc.h"
#include "guiFunctions/mqttFunc.h"
#include "guiFunctions/ScrHomeFunc.h"
#include "guiFunctions/ScrChartFunc.h"

#define TZ_INFO "EST+5EDT,M3.2.0/2,M11.1.0/2"

void setup()
{
    Serial.begin(115200);
    Serial.println("****** Initializing HMI ******");

    gui_start();
    logAdd(false, "GUI started.");

    // Setup wifi
    WiFi.disconnect(true);
    delay(500);
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to WiFi...");
    logAdd(false, "WiFi connecting...");
    delay(500);
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print('.');
        delay(500);
    }
    Serial.print("\nWiFi connected. IP: ");
    Serial.println(WiFi.localIP());
    logAdd(false, "WiFi connected. IP: " + WiFi.localIP().toString());

    // sync time with ntp server
    logAdd(false, "Syncing time...");
    timeSync(TZ_INFO, "pool.ntp.org", "time.nis.gov");
    logAdd(false, "Time synced to: " + rtc.getDateTime());

    // check connection to influxdb
    logAdd(true, "Checking InfluxDB connection...");
    influxConnect();

    // connect to mqtt broker
    logAdd(true, "Connecting to MQTT broker...");
    mqtt.begin(MQTT_SERVER, MQTT_PORT, wifiClient);
    mqtt.onMessage(mqttCallback);
    mqttConnect();

    chartDataInt();

    delay(1000);
    lv_obj_add_flag(ui_StartLog, LV_OBJ_FLAG_HIDDEN);
}

void loop()
{
    lv_timer_handler();
    updateTime();
    mqtt.loop();

    // Serial.print("Current time: ");
    // Serial.println(rtc.getTime("%I:%M %p"));
    delay(15);
}

/* colors

#F2F2F2;

#A6A6A6;

#595959;

#262626;

#0D0D0D;

*/