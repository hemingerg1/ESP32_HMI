#include <Arduino.h>
#include <WiFi.h>
#include <InfluxDbClient.h>
#include <algorithm>

#include <lv_conf.h>
#include <lvgl.h>
#include <secrets.h>

// Chart variables
int chartLen = 1;
String meas = "Temperature";
int soft_min = 40;
int soft_max = 75;
lv_coord_t data_array[1000];

#include "ui/ui.h"
#include "guiFunctions/gui.h"

#include "guiFunctions/InfluxFunc.h"
#include "guiFunctions/ScrHomeFunc.h"
#include "guiFunctions/ScrChartFunc.h"

#define TZ_INFO "EST5EDT"

void setup()
{
    gui_start();

    Serial.begin(115200);
    Serial.println("******Starting HMI******");

    // Setup wifi
    lv_obj_clear_flag(ui_wifiLab, LV_OBJ_FLAG_HIDDEN);
    lv_refr_now(NULL);
    WiFi.mode(WIFI_STA);
    delay(100);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to WiFi ..");
    delay(500);
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print('.');
        delay(500);
    }
    Serial.println(WiFi.localIP());
    lv_obj_clear_flag(ui_ipLab, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_timeLab, LV_OBJ_FLAG_HIDDEN);
    lv_refr_now(NULL);

    // sync time with ntp server
    timeSync(TZ_INFO, "pool.ntp.org", "time.nis.gov");

    // check connection to influxdb
    influxConnect();
    lv_obj_clear_flag(ui_influxLab, LV_OBJ_FLAG_HIDDEN);
    lv_refr_now(NULL);

    chartDataInt();

    delay(1000);
    lv_obj_add_flag(ui_StartLog, LV_OBJ_FLAG_HIDDEN);
}

void loop()
{
    lv_timer_handler();
    delay(5);
}