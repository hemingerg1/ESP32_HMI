
void mqttConnect()
{
    Serial.print(F("connecting to mqtt broker..."));
    while (!mqtt.connect("espHMI", MQTT_USER, MQTT_PASSWORD))
    {
        Serial.print(F("."));
        delay(500);
    }
    Serial.println(F("mqtt connected!"));
    logAdd(true, "Successfully connected to MQTT broker.");
    mqtt.subscribe(F("Garage/Air/Temp"));
    mqtt.subscribe(F("Garage/Air/OutTemp"));
    mqtt.subscribe(F("Garage/Air/Humidity"));
    mqtt.subscribe(F("Garage/Air/PM25"));
    mqtt.subscribe(F("Garage/Air/AQ"));
    mqtt.subscribe(F("Garage/Doors/LargeGarageDoor"));
    mqtt.subscribe(F("Garage/Doors/SmallGarageDoor"));
    mqtt.subscribe(F("Garage/Doors/OutsideDoor"));
    mqtt.subscribe(F("Garage/Doors/ShopDoor"));
    mqtt.subscribe(F("Garage/Mech/VentFan/Status"));
    mqtt.subscribe(F("Garage/Mech/Heater/Status"));
}

void mqttCallback(String &topic, String &payload)
{
    // Serial.println("incoming: " + topic + " - " + payload);
    if (topic == F("Garage/Air/Temp"))
    {
        lv_label_set_text_fmt(ui_tempLab, "%s", payload);
        insideTemp = payload.toInt();
    }
    else if (topic == F("Garage/Air/OutTemp"))
    {
        lv_label_set_text_fmt(ui_outTempLab, "%s", payload);
        outsideTemp = payload.toInt();
    }
    else if (topic == F("Garage/Air/Humidity"))
    {
        lv_label_set_text_fmt(ui_humLab, "%s", payload);
    }
    else if (topic == F("Garage/Air/PM25"))
    {
        lv_label_set_text_fmt(ui_pmLab, "%s", payload);
    }
    else if (topic == F("Garage/Air/AQ"))
    {
        lv_label_set_text_fmt(ui_aqLab, "%s", payload);
        aq = payload.toInt();
    }
    else if (topic == F("Garage/Doors/LargeGarageDoor"))
    {
        String state = payload;
        lv_label_set_text_fmt(ui_doubleGdoorLab, "%s", state);
        if (state == F("open"))
        {
            lv_obj_clear_state(ui_doubleGdoorLab, LV_STATE_CHECKED);
        }
        else if (state == F("closed"))
        {
            lv_obj_add_state(ui_doubleGdoorLab, LV_STATE_CHECKED);
        }
    }
    else if (topic == F("Garage/Doors/SmallGarageDoor"))
    {
        String state = payload;
        lv_label_set_text_fmt(ui_singleGdoorLab, "%s", state);
        if (state == F("open"))
        {
            lv_obj_clear_state(ui_singleGdoorLab, LV_STATE_CHECKED);
        }
        else if (state == F("closed"))
        {
            lv_obj_add_state(ui_singleGdoorLab, LV_STATE_CHECKED);
        }
    }
    else if (topic == F("Garage/Doors/OutsideDoor"))
    {
        String state = payload;
        lv_label_set_text_fmt(ui_outsidePdoorLab, "%s", state);
        if (state == F("open"))
        {
            lv_obj_clear_state(ui_outsidePdoorLab, LV_STATE_CHECKED);
        }
        else if (state == F("closed"))
        {
            lv_obj_add_state(ui_outsidePdoorLab, LV_STATE_CHECKED);
        }
    }
    else if (topic == F("Garage/Doors/ShopDoor"))
    {
        String state = payload;
        lv_label_set_text_fmt(ui_ShopPdoorLab, "%s", state);
        if (state == F("open"))
        {
            lv_obj_clear_state(ui_ShopPdoorLab, LV_STATE_CHECKED);
        }
        else if (state == F("closed"))
        {
            lv_obj_add_state(ui_ShopPdoorLab, LV_STATE_CHECKED);
        }
    }
    else if (topic == F("Garage/Mech/VentFan/Status"))
    {
        ventFanState = payload;
        lv_label_set_text_fmt(ui_ventStatLab, "%s", ventFanState);
        if (ventFanState == F("OFF"))
        {
            lv_obj_clear_state(ui_ventStatCont, LV_STATE_CHECKED);
        }
        else if (ventFanState == F("ON"))
        {
            lv_obj_add_state(ui_ventStatCont, LV_STATE_CHECKED);
        }
    }
    else if (topic == F("Garage/Mech/Heater/Status"))
    {
        heaterState = payload;
        lv_label_set_text_fmt(ui_heatStatLab, "%s", heaterState);
        if (heaterState == F("OFF"))
        {
            lv_obj_clear_state(ui_heatStatLab, LV_STATE_CHECKED);
        }
        else if (heaterState == F("ON"))
        {
            lv_obj_add_state(ui_heatStatLab, LV_STATE_CHECKED);
        }
    }
}