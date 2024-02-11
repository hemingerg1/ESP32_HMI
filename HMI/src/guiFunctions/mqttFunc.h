
void mqttConnect()
{
    Serial.print("connecting to mqtt broker...");
    while (!mqtt.connect("espHMI", MQTT_USER, MQTT_PASSWORD))
    {
        Serial.print(".");
        delay(500);
    }
    Serial.println("mqtt connected!");
    logAdd(true, "Successfully connected to MQTT broker.");
    mqtt.subscribe("Garage/Air/Temp");
    mqtt.subscribe("Garage/Air/Humidity");
    mqtt.subscribe("Garage/Air/PM25");
    mqtt.subscribe("Garage/Air/AQ");
    mqtt.subscribe("Garage/Doors/LargeGarageDoor");
    mqtt.subscribe("Garage/Doors/SmallGarageDoor");
    mqtt.subscribe("Garage/Doors/OutsideDoor");
    mqtt.subscribe("Garage/Doors/ShopDoor");
    mqtt.subscribe("Garage/Mech/VentFan");
}

void mqttCallback(String &topic, String &payload)
{
    // Serial.println("incoming: " + topic + " - " + payload);
    if (topic == "Garage/Air/Temp")
    {
        lv_label_set_text_fmt(ui_tempLab, "%s", payload);
    }
    else if (topic == "Garage/Air/Humidity")
    {
        lv_label_set_text_fmt(ui_humLab, "%s", payload);
    }
    else if (topic == "Garage/Air/PM25")
    {
        lv_label_set_text_fmt(ui_pmLab, "%s", payload);
    }
    else if (topic == "Garage/Air/AQ")
    {
        lv_label_set_text_fmt(ui_aqLab, "%s", payload);
    }
    else if (topic == "Garage/Doors/LargeGarageDoor")
    {
        String state = payload;
        lv_label_set_text_fmt(ui_doubleGdoorLab, "%s", state);
        if (state == "open")
        {
            lv_obj_clear_state(ui_doubleGdoorLab, LV_STATE_CHECKED);
        }
        else if (state == "closed")
        {
            lv_obj_add_state(ui_doubleGdoorLab, LV_STATE_CHECKED);
        }
    }
    else if (topic == "Garage/Doors/SmallGarageDoor")
    {
        String state = payload;
        lv_label_set_text_fmt(ui_singleGdoorLab, "%s", state);
        if (state == "open")
        {
            lv_obj_clear_state(ui_singleGdoorLab, LV_STATE_CHECKED);
        }
        else if (state == "closed")
        {
            lv_obj_add_state(ui_singleGdoorLab, LV_STATE_CHECKED);
        }
    }
    else if (topic == "Garage/Doors/OutsideDoor")
    {
        String state = payload;
        lv_label_set_text_fmt(ui_outsidePdoorLab, "%s", state);
        if (state == "open")
        {
            lv_obj_clear_state(ui_outsidePdoorLab, LV_STATE_CHECKED);
        }
        else if (state == "closed")
        {
            lv_obj_add_state(ui_outsidePdoorLab, LV_STATE_CHECKED);
        }
    }
    else if (topic == "Garage/Doors/ShopDoor")
    {
        String state = payload;
        lv_label_set_text_fmt(ui_ShopPdoorLab, "%s", state);
        if (state == "open")
        {
            lv_obj_clear_state(ui_ShopPdoorLab, LV_STATE_CHECKED);
        }
        else if (state == "closed")
        {
            lv_obj_add_state(ui_ShopPdoorLab, LV_STATE_CHECKED);
        }
    }
    else if (topic == "Garage/Mech/VentFan")
    {
        ventFantState = payload;
        lv_label_set_text_fmt(ui_ventStatLab, "%s", ventFantState);
        if (ventFantState == "off")
        {
            lv_obj_clear_state(ui_ventStatCont, LV_STATE_CHECKED);
        }
        else if (ventFantState == "on")
        {
            lv_obj_add_state(ui_ventStatCont, LV_STATE_CHECKED);
        }
    }
}