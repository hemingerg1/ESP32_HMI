
void mqttConnect()
{
    Serial.print("connecting to mqtt broker...");
    while (!mqtt.connect("espHMI", MQTT_USER, MQTT_PASSWORD))
    {
        Serial.print(".");
        delay(500);
    }
    Serial.println("mqtt connected!");
    mqtt.subscribe("Garage/Air/Temp");
    mqtt.subscribe("Garage/Air/Humidity");
    mqtt.subscribe("Garage/Air/PM25");
    mqtt.subscribe("Garage/Air/AQ");
    mqtt.subscribe("Garage/Doors/LargeGarageDoor");
    mqtt.subscribe("Garage/Doors/SmallGarageDoor");
    mqtt.subscribe("Garage/Doors/OutsideDoor");
    mqtt.subscribe("Garage/Doors/ShopDoor");
}

void mqttCallback(String &topic, String &payload)
{
    Serial.println("incoming: " + topic + " - " + payload);

    // Note: Do not use the client in the callback to publish, subscribe or
    // unsubscribe as it may cause deadlocks when other things arrive while
    // sending and receiving acknowledgments. Instead, change a global variable,
    // or push to a queue and handle it in the loop after calling `client.loop()`.
}