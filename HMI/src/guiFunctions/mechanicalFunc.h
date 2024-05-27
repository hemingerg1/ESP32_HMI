/********************* Switch Fan/Heater ON/OFF *********************/
void ventFanOn(bool req, String reason)
{
    if (req)
    {
        if (ventFanEnabled)
        {
            ventFanKeepAlive = 1;
            if (mqtt.publish("Garage/Mech/VentFan/KA", String(ventFanKeepAlive)))
            {
                ventFanKATimer = millis() + 60000;
                reqVentFan = true;
                logAdd(true, "vent fan ON (" + reason + ")");
                lv_label_set_text(ui_ventReqLab, "ON");
                lv_obj_add_state(ui_ventReqCont, LV_STATE_CHECKED);
            }
            else
            {
                logAdd(true, "MQTT FAILED: vent fan ON (" + reason + ")");
                lv_label_set_text(ui_ventReqLab, "ERR");
            }
        }
    }
    else
    {
        ventFanKeepAlive = 0;
        if (mqtt.publish("Garage/Mech/VentFan/KA", String(ventFanKeepAlive)))
        {
            ventFanKATimer = 0;
            reqVentFan = false;
            logAdd(true, "vent fan OFF (" + reason + ")");
            lv_label_set_text(ui_ventReqLab, "OFF");
            lv_obj_clear_state(ui_ventReqCont, LV_STATE_CHECKED);
        }
        else
        {
            logAdd(true, "MQTT FAILED: vent fan OFF (" + reason + ")");
            lv_label_set_text(ui_ventReqLab, "ERR");
        }
    }
}
void heaterOn(bool req, String reason)
{
    if (req)
    {
        if (heaterEnabled)
        {
            heatKeepAlive = 1;
            if (mqtt.publish("Garage/Mech/Heater/KA", String(heatKeepAlive)))
            {
                heatKATimer = millis() + 60000;
                reqHeat = true;
                logAdd(true, "heater ON (" + reason + ")");
                lv_label_set_text(ui_heatReqLab, "ON");
                lv_obj_add_state(ui_heatReqCont, LV_STATE_CHECKED);
            }
            else
            {
                logAdd(true, "MQTT FAILED: heater ON (" + reason + ")");
                lv_label_set_text(ui_heatReqLab, "ERR");
            }
        }
    }
    else
    {
        heatKeepAlive = 0;
        if (mqtt.publish("Garage/Mech/Heater/KA", String(heatKeepAlive)))
        {
            heatKATimer = 0;
            reqHeat = false;
            logAdd(true, "heater OFF (" + reason + ")");
            lv_label_set_text(ui_heatReqLab, "OFF");
            lv_obj_clear_state(ui_heatReqCont, LV_STATE_CHECKED);
        }
        else
        {
            logAdd(true, "MQTT FAILED: heater OFF (" + reason + ")");
            lv_label_set_text(ui_heatReqLab, "ERR");
        }
    }
}

/********************* Manual Control Timers *********************/
void manVentFanTimerUpdate()
{

    if (manVentFanTimer < millis())
    {
        ventFanOn(false, F("Manual timer expired"));
        lv_label_set_text(ui_ventTimerLab, "--");
        lv_obj_clear_state(ui_ventTimerCont, LV_STATE_CHECKED);
        manVentFanCon = false;
        manVentFanTimer = 0;
    }
    else
    {
        if (!reqVentFan)
        {
            ventFanOn(true, F("Manual timer set"));
        }
        secR = (manVentFanTimer - millis()) / 1000;
        minR = secR / 60;
        secR = secR % 60;
        lv_label_set_text_fmt(ui_ventTimerLab, "%d:%02d", minR, secR);
    }
}
void manHeatTimerUpdate()
{
    if (manHeatTimer < millis())
    {
        heaterOn(false, F("Manual timer expired"));
        lv_label_set_text(ui_heatTimerLab, "--");
        lv_obj_clear_state(ui_heatTimerCont, LV_STATE_CHECKED);
        manHeatCon = false;
        manHeatTimer = 0;
    }
    else
    {
        if (!reqHeat and insideTemp < manHeatTemp - 1)
        {
            heaterOn(true, F("Manual mode. Temp below setpoint"));
        }
        else if (reqHeat and insideTemp > manHeatTemp + 2)
        {
            heaterOn(false, F("Manual mode. Temp above setpoint"));
        }
        secR = (manHeatTimer - millis()) / 1000;
        minR = secR / 60;
        secR = secR % 60;
        lv_label_set_text_fmt(ui_heatTimerLab, "%d:%02d", minR, secR);
    }
}

/********************* Select Automatic Control Strategy *********************/
void tempAutoStrategy()
{
    if (tarMinTemp > absMinTemp and tarMaxTemp > tarMinTemp)
    {
        if (insideTemp > tarMaxTemp and outsideTemp < insideTemp + 3)
        {
            // Use vent fan to blow out the hotter inside air
            tempControl = 1;
        }
        else if (insideTemp > tarMinTemp and insideTemp < tarMaxTemp)
        {
            // No temperature control (inside temp is within the target range)
            tempControl = 0;
        }
        else if (insideTemp < tarMinTemp and outsideTemp > insideTemp + 3 and outsideTemp > absMinTemp)
        {
            // Use vent fan to bring in the warmer outside air
            tempControl = 1;
        }
        else if (outsideTemp < absMinTemp)
        {
            // Use electric heater
            tempControl = 2;
        }
        else
        {
            // No temperature control
            tempControl = 0;
        }
    }
    else
    {
        tempControl = 0;
        Serial.println(F("ERROR: 'Target min temp' must be higher than 'absolute min temp'"));
    }
}

/********************* Mechanicals Initialization *********************/
void mechInit()
{
    heaterOn(false, F("Init"));
    ventFanOn(false, F("Init"));
}

/********************* Main Mechanicals Control Loop *********************/
void mechLoop()
{
    if (manHeatCon and heaterEnabled) // manual heater control
    {
        manHeatTimerUpdate();
    }
    else // automatic heater control
    {
        tempAutoStrategy();
        if (reqHeat and tempControl == 0)
        {
            heaterOn(false, F("Auto mode 0. Temp above min target"));
        }
        else if (tempControl == 1)
        {
            if (reqHeat)
            {
                heaterOn(false, F("Auto temp mode 1. Temp above abs min target"));
            }
            if (!reqVentFan and autoVentFanOffTimer < millis() and ventFanEnabled)
            {
                ventFanOn(true, F("Auto temp mode 1. Using vent fan for temp control"));
                autoVentFanOnTimer = millis() + (fanOnTempTime * 60000);
                autoVentFanOffTimer = fanOffTempTime * 60000;
            }
        }
        else if (tempControl == 2 and heaterEnabled)
        {
            if (!reqHeat and insideTemp < absMinTemp - 1)
            {
                heaterOn(true, F("Auto mode 2. Temp below abs min target"));
            }
            else if (reqHeat and insideTemp > absMinTemp + 2)
            {
                heaterOn(false, F("Auto mode 2. Temp above abs min target"));
            }
        }
    }

    if (manVentFanCon and ventFanEnabled) // manual vent fan control
    {
        manVentFanTimerUpdate();
    }
    else if (!reqVentFan and autoVentFanOffTimer < millis() and aq < aqFanOnLevel and ventFanEnabled) // automatic vent fan control for air quality
    {
        ventFanOn(true, F("Auto mode. Air quality below threshold"));
        autoVentFanOnTimer = millis() + (aqFanOnTime * 60000);
        autoVentFanOffTimer = aqFanOffTime * 60000;
    }

    // If vent fan is on and all timers have expired, turn it off
    if (reqVentFan and autoVentFanOnTimer < millis() and manVentFanTimer < millis())
    {
        autoVentFanOffTimer += millis();
        ventFanOn(false, F("Auto timer expired"));
        autoVentFanOnTimer = 0;
    }

    // update keep alive counters on MQTT broker every minute so that PLCs know the HMI is still alive
    if (reqVentFan and ventFanKeepAlive > 0 and ventFanKATimer < millis())
    {
        ventFanKeepAlive++;
        ventFanKATimer = millis() + 60000;
        mqtt.publish("Garage/Mech/VentFan/KA", String(ventFanKeepAlive));
    }
    if (reqHeat and heatKeepAlive > 0 and heatKATimer < millis())
    {
        heatKeepAlive++;
        heatKATimer = millis() + 60000;
        mqtt.publish("Garage/Mech/Heater/KA", String(heatKeepAlive));
    }
}