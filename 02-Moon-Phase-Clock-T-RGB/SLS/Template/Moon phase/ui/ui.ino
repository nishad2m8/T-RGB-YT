#include <LilyGo_RGBPanel.h>
#include <lvgl.h>
#include <LV_Helper.h>
#include <ui.h>
#include <TFT_eSPI.h>

// https://www.youtube.com/nishad2m8
// https://buymeacoffee.com/nishad2m8

LilyGo_RGBPanel panel;

TFT_eSPI tft = TFT_eSPI(); 

void setup(void)
{
    Serial.begin(115200);

    // Initialize T-RGB, if the initialization fails, false will be returned.
    if (!panel.begin()) {
        while (1) {
            Serial.println("Error, failed to initialize T-RGB"); delay(1000);
        }
    }
    // Call lvgl initialization
    beginLvglHelper(panel);

    ui_init();

    lv_task_handler();

    panel.setBrightness(16);
}

void loop()
{
    lv_task_handler();
    delay(5);
}
