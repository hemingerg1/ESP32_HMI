void tempStrategy()
{
    if (tarMinTemp > absMinTemp)
    {
        if (insideTemp > tarMinTemp)
        {
            // No temperature control (inside temp is warmer than target)
            tempControl = 0;
        }
        else if (insideTemp < tarMinTemp and outsideTemp > insideTemp + 2 and outsideTemp > absMinTemp)
        {
            // Use vent fan to bring in the warmer outside air
            tempControl = 1;
        }
        else if (insideTemp < absMinTemp)
        {
            // Use electric heater
            tempControl = 2;
        }
    }
    else
    {
        tempControl = 0;
        Serial.println("ERROR: 'Target min temp' must be higher than 'absolute min temp'");
    }
}