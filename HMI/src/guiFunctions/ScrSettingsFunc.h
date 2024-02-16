
void reboot(lv_event_t *e)
{
    Serial.println("Rebooting...");
    delay(500);
    ESP.restart();
}

void wificon(lv_event_t *e)
{
    logAdd(false, "Reconnecting to WiFi...");
    WiFi.disconnect(true);
    delay(1000);
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to WiFi...");
    logAdd(false, "WiFi connecting...");
    delay(500);
    int t = 0;
    while (WiFi.status() != WL_CONNECTED)
    {
        t++;
        Serial.print('.');
        delay(500);
        if (t > 20)
        {
            logAdd(false, "Unable to connect to WiFi.");
            reboot(NULL);
        }
    }
    logAdd(false, "WiFi connected. IP: " + WiFi.localIP().toString());
}

void mqttCon(lv_event_t *e)
{
    Serial.println("Reconnecting to MQTT broker...");
    logAdd(true, "Reconnecting to MQTT broker...");
    mqtt.disconnect();
    delay(200);
    if (WiFi.status() != WL_CONNECTED)
    {
        logAdd(true, "WiFi not connected. Attempting to reconnect...");
        wificon(NULL);
    }
    mqtt.begin(MQTT_SERVER, MQTT_PORT, wifiClient);
    mqtt.onMessage(mqttCallback);
    mqttConnect();
}

void displaySleep()
{
    if (screenTimeout != 0)
    {
        int inactMin = lv_disp_get_inactive_time(NULL) / 1000 / 60;
        if (!screenSleep and inactMin >= screenTimeout)
        {
            gfx.setBrightness(30);
            lv_scr_load(ui_ScrSleep);
            screenSleep = true;
        }
        else if (screenSleep and inactMin < screenTimeout)
        {
            gfx.setBrightness(127);
            lv_scr_load(ui_ScrHome);
            screenSleep = false;
        }
    }
}

void settingsInit()
{
    lv_textarea_set_text(ui_targTempMinTA, String(tarMinTemp).c_str());
    lv_textarea_set_text(ui_absTempMinTA, String(absMinTemp).c_str());
    lv_textarea_set_text(ui_fanOnTempTA, String(fanOnTempTime).c_str());
    lv_textarea_set_text(ui_fanOffTempTA, String(fanOffTempTime).c_str());
    lv_textarea_set_text(ui_aqMinTA, String(aqFanOnLevel).c_str());
    lv_textarea_set_text(ui_fanOnAqTA, String(aqFanOnTime).c_str());
    lv_textarea_set_text(ui_fanOffAqTA, String(aqFanOffTime).c_str());
    lv_dropdown_set_selected(ui_screenTimeDrop, 1);
}

void timeoutChange(lv_event_t *e)
{
    int sel = lv_dropdown_get_selected(ui_screenTimeDrop);
    if (sel == 0)
    {
        screenTimeout = 0;
    }
    else if (sel == 1)
    {
        screenTimeout = 10;
    }
    else if (sel == 2)
    {
        screenTimeout = 20;
    }
    else if (sel == 3)
    {
        screenTimeout = 30;
    }
    Serial.println("Screen timeout changed to " + String(screenTimeout) + " minutes.");
    logAdd(true, "Screen timeout changed to " + String(screenTimeout) + " minutes.");
}

void keyboardEnter(lv_event_t *e)
{
    tarMinTemp = atoi(lv_textarea_get_text(ui_targTempMinTA));
    absMinTemp = atoi(lv_textarea_get_text(ui_absTempMinTA));
    fanOnTempTime = atoi(lv_textarea_get_text(ui_fanOnTempTA));
    fanOffTempTime = atoi(lv_textarea_get_text(ui_fanOffTempTA));
    aqFanOnLevel = atoi(lv_textarea_get_text(ui_aqMinTA));
    aqFanOnTime = atoi(lv_textarea_get_text(ui_fanOnAqTA));
    aqFanOffTime = atoi(lv_textarea_get_text(ui_fanOffAqTA));

    tempStrategy();

    Serial.println("Target temp: " + String(tarMinTemp));
    Serial.println("Absolute temp: " + String(absMinTemp));
    Serial.println("Temp fan on time: " + String(fanOnTempTime));
    Serial.println("Temp fan off time: " + String(fanOffTempTime));
    Serial.println("AQ min level: " + String(aqFanOnLevel));
    Serial.println("AQ fan on time: " + String(aqFanOnTime));
    Serial.println("AQ fan off time: " + String(aqFanOffTime));
}
