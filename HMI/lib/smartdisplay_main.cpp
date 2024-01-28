#include <Arduino.h>

#include <esp32_smartdisplay.h>
#include <ui/ui.h>

#define WIFI_SSID "<your ssid>"
#define WIFI_PASSWORD "<your ap password>"
#define RADIO_URL "http://www.wdr.de/wdrlive/media/einslive.m3u"

void setup()
{
  delay(250);
  Serial.begin(115200);
  Serial.setDebugOutput(true);

  log_i("CPU: %s rev%d, CPU Freq: %d Mhz, %d core(s)", ESP.getChipModel(), ESP.getChipRevision(), getCpuFrequencyMhz(), ESP.getChipCores());
  log_i("Free heap: %d bytes", ESP.getFreeHeap());
  log_i("Free PSRAM: %d bytes", ESP.getPsramSize());
  log_i("SDK version: %s", ESP.getSdkVersion());

  smartdisplay_init();
  ui_init();
}

void loop()
{
  lv_timer_handler();
  delay(5);
}