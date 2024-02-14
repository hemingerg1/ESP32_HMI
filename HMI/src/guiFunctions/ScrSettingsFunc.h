
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