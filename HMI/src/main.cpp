#include <Arduino.h>
#include <lv_conf.h>
#include <lvgl.h>

#include "ui/ui.h"
#include "guiFunctions/gui.h"

#include "guiFunctions/ScrHomeFunc.h"

void setup()
{
    gui_start();
}

void loop()
{
    lv_timer_handler();
    delay(5);
}