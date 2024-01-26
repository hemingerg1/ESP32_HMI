#include <Arduino.h>
#include <esp32_smartdisplay.h>

// put function declarations here:
int myFunction(int, int);

void setup()
{
  smartdisplay_init();

  auto disp = lv_disp_get_default();
}

void loop()
{
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y)
{
  return x + y;
}