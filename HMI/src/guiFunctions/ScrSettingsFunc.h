void settingsInit()
{
    if (prefs.begin("settings", false))
    {
        lv_textarea_set_text(ui_targTempMinTA, String(prefs.getShort("tarMinTemp", tarMinTemp)).c_str());
        lv_textarea_set_text(ui_absTempMinTA, String(prefs.getShort("absMinTemp", absMinTemp)).c_str());
        lv_textarea_set_text(ui_fanOnTempTA, String(prefs.getShort("fanOnTempTime", fanOnTempTime)).c_str());
        lv_textarea_set_text(ui_fanOffTempTA, String(prefs.getShort("fanOffTempTime", fanOffTempTime)).c_str());
        lv_textarea_set_text(ui_aqMinTA, String(prefs.getShort("aqFanOnLevel", aqFanOnLevel)).c_str());
        lv_textarea_set_text(ui_fanOnAqTA, String(prefs.getShort("aqFanOnTime", aqFanOnTime)).c_str());
        lv_textarea_set_text(ui_fanOffAqTA, String(prefs.getShort("aqFanOffTime", aqFanOffTime)).c_str());

        short int s = prefs.getShort("screenTimeout", screenTimeout);
        if (s == 0)
        {
            lv_dropdown_set_selected(ui_screenTimeDrop, 0);
        }
        else if (s == 10)
        {
            lv_dropdown_set_selected(ui_screenTimeDrop, 1);
        }
        else if (s == 20)
        {
            lv_dropdown_set_selected(ui_screenTimeDrop, 2);
        }
        else if (s == 30)
        {
            lv_dropdown_set_selected(ui_screenTimeDrop, 3);
        }

        ventFanEnabled = prefs.getBool("ventFanEnabled", ventFanEnabled);
        Serial.print("ventFanEnabled type: " + String(prefs.getType("ventFanEnabled")));
        Serial.println(",  ventFanEnabled: " + String(ventFanEnabled));
        if (ventFanEnabled)
        {
            lv_obj_add_state(ui_venfFanSwitch, LV_STATE_CHECKED);
            enableVentFan(NULL);
        }
        else
        {
            lv_obj_clear_state(ui_venfFanSwitch, LV_STATE_CHECKED);
            lv_obj_clear_flag(ui_ventOffPanel, LV_OBJ_FLAG_HIDDEN);
            disableVentFan(NULL);
        }

        heaterEnabled = prefs.getBool("heaterEnabled", heaterEnabled);
        Serial.print("heaterEnabled type: " + String(prefs.getType("heaterEnabled")));
        Serial.println(",  heaterEnabled: " + String(heaterEnabled));
        if (heaterEnabled)
        {
            lv_obj_add_state(ui_heaterSwitch, LV_STATE_CHECKED);
            enableHeater(NULL);
        }
        else
        {
            lv_obj_clear_state(ui_heaterSwitch, LV_STATE_CHECKED);
            lv_obj_clear_flag(ui_heaterOffPanel, LV_OBJ_FLAG_HIDDEN);
            disableHeater(NULL);
        }

        prefs.end();
    }
    else
    {
        logAdd(F("Failed to open nvs for settings init"));
    }

    keyboardEnter(NULL);
    timeoutChange(NULL);
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

    if (prefs.begin("settings", false))
    {
        if (!prefs.putShort("screenTimeout", screenTimeout))
        {
            logAdd(F("Failed to save screenTimeout into nvs"));
        }
        prefs.end();
    }
    else
    {
        logAdd(F("Failed to open nvs for screenTimeout change"));
    }

    logAdd(true, "Screen timeout changed to " + String(screenTimeout) + " minutes.");
}

void reboot(lv_event_t *e)
{
    Serial.println(F("Rebooting..."));
    delay(500);
    ESP.restart();
}

void wificon(lv_event_t *e)
{
    logAdd(false, F("Reconnecting to WiFi..."));
    WiFi.disconnect(true);
    delay(1000);
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print(F("Connecting to WiFi..."));
    logAdd(false, F("WiFi connecting..."));
    delay(500);
    int t = 0;
    while (WiFi.status() != WL_CONNECTED)
    {
        t++;
        Serial.print(F('.'));
        delay(500);
        if (t > 20)
        {
            logAdd(false, F("Unable to connect to WiFi."));
            reboot(NULL);
        }
    }
    logAdd(false, "WiFi connected. IP: " + WiFi.localIP().toString());
}

void mqttCon(lv_event_t *e)
{
    Serial.println(F("Reconnecting to MQTT broker..."));
    logAdd(true, F("Reconnecting to MQTT broker..."));
    mqtt.disconnect();
    delay(200);
    if (WiFi.status() != WL_CONNECTED)
    {
        logAdd(true, F("WiFi not connected. Attempting to reconnect..."));
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

void keyboardEnter(lv_event_t *e)
{
    tarMinTemp = atoi(lv_textarea_get_text(ui_targTempMinTA));
    absMinTemp = atoi(lv_textarea_get_text(ui_absTempMinTA));
    fanOnTempTime = atoi(lv_textarea_get_text(ui_fanOnTempTA));
    fanOffTempTime = atoi(lv_textarea_get_text(ui_fanOffTempTA));
    aqFanOnLevel = atoi(lv_textarea_get_text(ui_aqMinTA));
    aqFanOnTime = atoi(lv_textarea_get_text(ui_fanOnAqTA));
    aqFanOffTime = atoi(lv_textarea_get_text(ui_fanOffAqTA));

    if (prefs.begin("settings", false))
    {
        prefs.putShort("tarMinTemp", tarMinTemp);
        prefs.putShort("absMinTemp", absMinTemp);
        prefs.putShort("fanOnTempTime", fanOnTempTime);
        prefs.putShort("fanOffTempTime", fanOffTempTime);
        prefs.putShort("aqFanOnLevel", aqFanOnLevel);
        prefs.putShort("aqFanOnTime", aqFanOnTime);
        prefs.putShort("aqFanOffTime", aqFanOffTime);
        prefs.end();
    }
    else
    {
        logAdd(F("Failed to open nvs for settings change"));
    }
}
