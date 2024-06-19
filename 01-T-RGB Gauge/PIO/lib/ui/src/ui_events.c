// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.11
// Project name: T-RGB Gauge

#include "ui.h"

// Function to handle button right press event
void Button_Right_Pressed(lv_event_t * e)
{
    // Create a transition animation
    lv_scr_load_anim_t anim = LV_SCR_LOAD_ANIM_MOVE_LEFT; // Move LEFT to slide the new screen in from the right
    uint32_t time = 500; // Animation time in milliseconds
    uint32_t delay = 0; // Delay before the animation starts

    // Load ui_Screen2 with animation
    lv_scr_load_anim(ui_Screen2, anim, time, delay, false); // false indicates no wait for animation to complete
}

// Function to handle button left press event
void Button_Left_Pressed(lv_event_t * e)
{
    // Create a transition animation
    lv_scr_load_anim_t anim = LV_SCR_LOAD_ANIM_MOVE_RIGHT; // Move RIGHT to slide the new screen in from the right
    uint32_t time = 500; // Animation time in milliseconds
    uint32_t delay = 0; // Delay before the animation starts

    // Load ui_Screen1 with animation
    lv_scr_load_anim(ui_Screen1, anim, time, delay, false); // false indicates no wait for animation to complete
}


// Function to handle Screen2 loaded event
void Screen2_Loaded(lv_event_t * e)
{
   static bool is_animated = false;

    // Check if the animation has already been done
    if (is_animated) {
        return; // If yes, return immediately
    }

    is_animated = true;
    extern lv_obj_t * ui_imgcar;
    extern lv_obj_t * ui_Icon_1;
    extern lv_obj_t * ui_Icon_2;
    extern lv_obj_t * ui_Icon_3;
    extern lv_obj_t * ui_Icon_4;

    // Start the car animation
    carAnimation_Animation(ui_imgcar, 0); // Assuming 0 is the start value for the animation

    // Start icon animations and set callback to show the icons after animation
    iconAnimation_Animation(ui_Icon_1, 500);
    iconAnimation_Animation(ui_Icon_2, 600);
    iconAnimation_Animation(ui_Icon_3, 700);
    iconAnimation_Animation(ui_Icon_4, 800);
}
