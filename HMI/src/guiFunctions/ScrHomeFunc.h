
void updateTime()
{
    lv_label_set_text_fmt(ui_timeLab, "%s", rtc.getTime("%I:%M"));
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
    }
    else if (ventFanTimer > millis())
    {
        if (ventFantState == "off")
        {
            ventFanOn(true);
        }

        int secRemain = (ventFanTimer - millis()) / 1000;
        lv_label_set_text_fmt(ui_ventTimerLab, "%d", secRemain);
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