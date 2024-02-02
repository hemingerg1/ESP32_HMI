#include <Arduino.h>
#include <algorithm>

#include <lv_conf.h>
#include <lvgl.h>
#include <secrets.h>

#include "ui/ui.h"
#include "guiFunctions/gui.h"

#include "guiFunctions/ScrHomeFunc.h"
#include "guiFunctions/ScrChartFunc.h"

void setup()
{
    gui_start();
    chartDataInt();

    Serial.begin(115200);
    Serial.println("******Started******");
}

void loop()
{
    lv_timer_handler();
    delay(5);
}