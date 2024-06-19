#include <Arduino.h>
#include <TFT_eSPI.h>
#include "LilyGo_RGBPanel.h"
#include "ui.h"
#include "RGBPanelInit.h"
#include "LV_Helper.h"

// Global instance for the RGB Panel
LilyGo_RGBPanel panel;

// UI Components
lv_obj_t *ui_img_needle;  // Image object for the needle in the speedometer
lv_obj_t *ui_label_speed; // Label object for displaying speed

// Constants
const int MaxSpeed = 240;       // Maximum speed to display
const int MinSpeed = 0;         // Minimum speed
const int SpeedIncrement = 1;   // Increment for speed changes
const int UpdateInterval = 100; // Update interval for speed changes in milliseconds
const int MinDuration = 100;    // Minimum duration for speedometer animation in milliseconds

/**
 * Maps speed value to an angle for the dial
 */
static int speed_to_angle(int speed)
{
    return (speed * 2400) / 240; // Each unit of speed scales to an angle range of 0 to 2400 degrees
}

/**
 * Sets the angle of the image representing the dial
 */
static void set_angle(void *img, int32_t angle)
{
    lv_img_set_angle((lv_obj_t *)img, angle);
}

/**
 * Creates and starts an animation for the speedometer needle
 */
void create_speedometer_animation(lv_obj_t *img, int start_speed, int end_speed, uint32_t duration)
{
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, img);
    lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)set_angle);
    lv_anim_set_time(&a, duration);
    lv_anim_set_values(&a, speed_to_angle(start_speed), speed_to_angle(end_speed));
    lv_anim_set_path_cb(&a, lv_anim_path_linear); // Can be changed to other easing functions like lv_anim_path_ease_in_out
    lv_anim_start(&a);
}

/**
 * Smoothly transitions the displayed speed on the dial
 */
void smooth_speed_transition(lv_obj_t *img, int target_speed)
{
    int current_angle = lv_img_get_angle(img);
    int current_speed = (current_angle * MaxSpeed) / 2400;
    int duration = abs(current_speed - target_speed) * 10;
    duration = max(duration, MinDuration);

    create_speedometer_animation(img, current_speed, target_speed, duration);

    char speed_text[10];
    sprintf(speed_text, "%d", target_speed);
    lv_label_set_text(ui_label_speed, speed_text);
}

/**
 * Simulates speed changes
 */
void simulate_speed(lv_obj_t *img)
{
    static int speed = MinSpeed;
    static bool increasing = true;
    unsigned long lastUpdate = millis();

    while (true)
    {
        unsigned long now = millis();
        if (now - lastUpdate >= UpdateInterval)
        {
            speed += increasing ? SpeedIncrement : -SpeedIncrement;
            if (speed >= MaxSpeed || speed <= MinSpeed)
            {
                increasing = !increasing;
            }
            smooth_speed_transition(img, speed);
            lastUpdate = now;
        }
        lv_task_handler(); // Process pending LVGL tasks
    }
}

void setup()
{
    Serial.begin(115200);
    if (!panel.begin())
    {
        Serial.println("Error: Failed to initialize the panel.");
        while (true)
            delay(1000); // Stall if panel cannot initialize
    }

    beginLvglHelper(panel);
    ui_init();               // Initialize UI components
    panel.setBrightness(16); // Set brightness level

    xTaskCreate(
        [](void *pvParameters)
        {
            simulate_speed(ui_img_needle);
        },
        "SpeedSimTask",
        4096,
        nullptr,
        1,
        nullptr);
}

void loop()
{
    lv_task_handler();
    delay(5); // Short delay to reduce CPU usage
}
