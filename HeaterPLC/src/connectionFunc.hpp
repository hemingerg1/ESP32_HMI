void wificon()
{
    WiFi.disconnect(true);
    delay(1000);

    WiFi.setHostname("heaterPLC");
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    Serial.print("Connecting to WiFi...");
    delay(500);
    int t = 0;
    while (WiFi.status() != WL_CONNECTED)
    {
        t++;
        Serial.print('.');
        delay(500);
        if (t > 20)
        {
            Serial.print("\nUnable to connect to WiFi. Rebooting...");
            ESP.restart();
        }
    }
    Serial.println("\nWiFi connected. IP: " + WiFi.localIP().toString());
}

void mqttCallback(String &topic, String &payload)
{
    if (topic == "Garage/Mech/Heater/KA")
    {
        if (payload.toInt() > kaCount)
        {
            kaTimer = millis();
        }
        else if (payload.toInt() == 0)
        {
            kaTimer = 0;
        }
        kaCount = payload.toInt();
        Serial.print("MQTT received: ");
        Serial.print("kaCount = " + String(kaCount));
        Serial.println(", kaTimer = " + String(kaTimer));
    }
}

void mqttCon()
{
    //mqtt.disconnect();
    delay(200);

    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("WiFi not connected. Attempting to reconnect...");
        wificon();
    }

    mqtt.begin(MQTT_SERVER, MQTT_PORT, wifiClient);
    mqtt.onMessage(mqttCallback);

    Serial.print("Connecting to mqtt broker...");
    while (!mqtt.connect("espVentFanPLC", MQTT_USER, MQTT_PASSWORD))
    {
        Serial.print(F("."));
        delay(500);
    }
    Serial.println("mqtt connected!");

    mqtt.subscribe("Garage/Mech/Heater/KA");
}