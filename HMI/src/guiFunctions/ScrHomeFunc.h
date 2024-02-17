void homeInit()
{
    lv_label_set_text(ui_heatTempLab, String(manHeatTemp).c_str());
}

void updateTime()
{
    if (!screenSleep)
    {
        lv_label_set_text_fmt(ui_timeLab, "%d:%02d", rtc.getHour(), rtc.getMinute());
    }
    else
    {
        lv_label_set_text_fmt(ui_sleepTimeLab, "%d:%02d", rtc.getHour(), rtc.getMinute());
    }
}

/************ Ventilation Panel ************/
void disableVentFan(lv_event_t *e)
{
    ventFanEnabled = false;
    ventFanOn(false, F("Vent fan disabled"));
    lv_label_set_text(ui_ventTimerLab, "--");
    lv_obj_clear_state(ui_ventTimerCont, LV_STATE_CHECKED);
    manVentFanCon = false;
    manVentFanTimer = 0;
    autoVentFanOffTimer = 0;
    autoVentFanOnTimer = 0;
}

void enableVentFan(lv_event_t *e)
{
    ventFanEnabled = true;
    logAdd(true, F("Vent fan enabled"));
}

void ventFanTimerAdd(int sec)
{
    if (manVentFanTimer > millis())
    {
        manVentFanTimer += sec * 1000;
    }
    else
    {
        manVentFanTimer = millis() + (sec * 1000);
    }
    // Serial.println("Vent fan timer set for " + String(manVentFanTimer) + " ms");
}

void butVentFanOff(lv_event_t *e)
{
    ventFanOn(false, F("Manual off button pressed"));
    lv_label_set_text(ui_ventTimerLab, "--");
    lv_obj_clear_state(ui_ventTimerCont, LV_STATE_CHECKED);
    manVentFanCon = false;
    manVentFanTimer = 0;
}

void butVentFan5m(lv_event_t *e)
{
    ventFanTimerAdd(300);
    manVentFanCon = true;
    lv_obj_add_state(ui_ventTimerCont, LV_STATE_CHECKED);
}

/************ Heater Panel ************/
void disableHeater(lv_event_t *e)
{
    heaterEnabled = false;
    heaterOn(false, F("Heater disabled"));
    lv_label_set_text(ui_heatTimerLab, "--");
    lv_obj_clear_state(ui_heatTimerCont, LV_STATE_CHECKED);
    manHeatCon = false;
    manHeatTimer = 0;
}

void enableHeater(lv_event_t *e)
{
    heaterEnabled = true;
    logAdd(true, F("Heater enabled"));
}

void butManHeatUp(lv_event_t *e)
{
    manHeatTemp++;
    lv_label_set_text(ui_heatTempLab, String(manHeatTemp).c_str());
}

void butManHeatDown(lv_event_t *e)
{
    manHeatTemp--;
    lv_label_set_text(ui_heatTempLab, String(manHeatTemp).c_str());
}

void manHeatTimerAdd(int sec)
{
    if (manHeatTimer > millis())
    {
        manHeatTimer += sec * 1000;
    }
    else
    {
        manHeatTimer = millis() + (sec * 1000);
    }
    // Serial.println("Heater manual control timer set for " + String(manHeatTimer) + " ms");
}

void butManHeat15m(lv_event_t *e)
{
    manHeatTimerAdd(900);
    manHeatCon = true;
    lv_obj_add_state(ui_heatTimerCont, LV_STATE_CHECKED);
}
