void homeInit()
{
    lv_label_set_text(ui_heatTempLab, String(manHeatTemp).c_str());
}

void updateTime()
{
    if (rtc.getMinute() != lMin)
    {
        lMin = rtc.getMinute();
        if (!screenSleep)
        {
            lv_label_set_text_fmt(ui_timeLab, "%d:%02d", rtc.getHour(), lMin);
        }
        else
        {
            lv_label_set_text_fmt(ui_sleepTimeLab, "%d:%02d", rtc.getHour(), lMin);
        }
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

    if (start)
    {
        if (!prefs.putBool("ventFanEnabled", ventFanEnabled))
        {
            logAdd(true, F("Failed to save vent fan disable into nvs on startup"));
        }
    }
    else if (prefs.begin("settings", false))
    {
        if (!prefs.putBool("ventFanEnabled", ventFanEnabled))
        {
            logAdd(true, F("Failed to save vent fan disable into nvs"));
        }
        prefs.end();
    }
    else
    {
        logAdd(true, F("Failed to open nvs for vent fan disable"));
    }
}

void enableVentFan(lv_event_t *e)
{
    ventFanEnabled = true;
    logAdd(true, F("Vent fan enabled"));

    if (start)
    {
        if (!prefs.putBool("ventFanEnabled", ventFanEnabled))
        {
            logAdd(true, F("Failed to save vent fan enable into nvs on startup"));
        }
    }
    else if (prefs.begin("settings", false))
    {
        if (!prefs.putBool("ventFanEnabled", ventFanEnabled))
        {
            logAdd(true, F("Failed to save vent fan enable into nvs"));
        }
        prefs.end();
    }
    else
    {
        logAdd(true, F("Failed to open nvs for vent fan enable"));
    }
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

    if (start)
    {
        if (!prefs.putBool("heaterEnabled", heaterEnabled))
        {
            logAdd(true, F("Failed to save heater disable into nvs on startup"));
        }
    }
    else if (prefs.begin("settings", false))
    {
        if (!prefs.putBool("heaterEnabled", heaterEnabled))
        {
            logAdd(true, F("Failed to save heater disable into nvs"));
        }
        prefs.end();
    }
    else
    {
        logAdd(true, F("Failed to open nvs for heater disable"));
    }
}

void enableHeater(lv_event_t *e)
{
    heaterEnabled = true;
    logAdd(true, F("Heater enabled"));

    if (start)
    {
        if (!prefs.putBool("heaterEnabled", heaterEnabled))
        {
            logAdd(true, F("Failed to save heater disable into nvs on startup"));
        }
    }
    else if (prefs.begin("settings", false))
    {
        if (!prefs.putBool("heaterEnabled", heaterEnabled))
        {
            logAdd(true, F("Failed to save heater enable into nvs"));
        }
        prefs.end();
    }
    else
    {
        logAdd(true, F("Failed to open nvs for heater enable"));
    }
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
