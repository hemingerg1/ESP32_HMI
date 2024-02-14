
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

void ventFanOn(bool req)
{
    if (req)
    {
        logAdd(true, "Vent fan turned on.");
        // digitalWrite(VENT_FAN_PIN, HIGH);
    }
    else
    {
        logAdd(true, "Vent fan turned off.");
    }
}

void ventFanTimerAdd(int sec)
{
    if (ventFanTimer > millis())
    {
        ventFanTimer += sec * 1000;
    }
    else
    {
        ventFanTimer = millis() + (sec * 1000);
    }
    Serial.println("Vent fan timer set for " + String(ventFanTimer) + " ms");
}

void ventFanTimerCheck()
{

    if (ventFantState == "on" and ventFanTimer < millis())
    {
        ventFanOn(false);
        lv_label_set_text(ui_ventTimerLab, "--");
        lv_obj_clear_state(ui_ventTimerCont, LV_STATE_CHECKED);
    }
    else if (ventFanTimer > millis())
    {
        if (ventFantState == "off")
        {
            ventFanOn(true);
            lv_obj_add_state(ui_ventTimerCont, LV_STATE_CHECKED);
        }

        int secRemain = (ventFanTimer - millis()) / 1000;
        int minRemain = secRemain / 60;
        secRemain = secRemain % 60;
        lv_label_set_text_fmt(ui_ventTimerLab, "%d:%02d", minRemain, secRemain);
    }
}

void butVentFanOff(lv_event_t *e)
{
    ventFanOn(false);
}

void butVentFan5m(lv_event_t *e)
{
    ventFanTimerAdd(300);
}