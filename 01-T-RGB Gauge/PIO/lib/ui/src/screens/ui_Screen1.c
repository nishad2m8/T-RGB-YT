// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.11
// Project name: T-RGB Gauge

#include "../ui.h"

void ui_Screen1_screen_init(void)
{
ui_Screen1 = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Screen1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Screen1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_gauge_main = lv_obj_create(ui_Screen1);
lv_obj_remove_style_all(ui_gauge_main);
lv_obj_set_width( ui_gauge_main, 480);
lv_obj_set_height( ui_gauge_main, 480);
lv_obj_set_align( ui_gauge_main, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_gauge_main, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_img_Gauge = lv_img_create(ui_gauge_main);
lv_img_set_src(ui_img_Gauge, &ui_img_images_gauge_png);
lv_obj_set_width( ui_img_Gauge, LV_SIZE_CONTENT);  /// 480
lv_obj_set_height( ui_img_Gauge, LV_SIZE_CONTENT);   /// 480
lv_obj_set_align( ui_img_Gauge, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_img_Gauge, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_img_Gauge, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_img_Lettering = lv_img_create(ui_gauge_main);
lv_img_set_src(ui_img_Lettering, &ui_img_images_lettering_png);
lv_obj_set_width( ui_img_Lettering, LV_SIZE_CONTENT);  /// 342
lv_obj_set_height( ui_img_Lettering, LV_SIZE_CONTENT);   /// 425
lv_obj_set_x( ui_img_Lettering, 30 );
lv_obj_set_y( ui_img_Lettering, 25 );
lv_obj_add_flag( ui_img_Lettering, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_img_Lettering, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Container_temp = lv_obj_create(ui_Screen1);
lv_obj_remove_style_all(ui_Container_temp);
lv_obj_set_width( ui_Container_temp, 480);
lv_obj_set_height( ui_Container_temp, 480);
lv_obj_set_align( ui_Container_temp, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Container_temp, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_gauge_dial = lv_obj_create(ui_Screen1);
lv_obj_remove_style_all(ui_gauge_dial);
lv_obj_set_width( ui_gauge_dial, 480);
lv_obj_set_height( ui_gauge_dial, 480);
lv_obj_set_align( ui_gauge_dial, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_gauge_dial, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_img_needle = lv_img_create(ui_gauge_dial);
lv_img_set_src(ui_img_needle, &ui_img_images_needle_png);
lv_obj_set_width( ui_img_needle, LV_SIZE_CONTENT);  /// 504
lv_obj_set_height( ui_img_needle, LV_SIZE_CONTENT);   /// 504
lv_obj_set_x( ui_img_needle, 236 );
lv_obj_set_y( ui_img_needle, 235 );
lv_obj_add_flag( ui_img_needle, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_img_needle, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_pivot(ui_img_needle,3,2);
lv_img_set_angle(ui_img_needle,1400);

ui_Conainer_label = lv_obj_create(ui_Screen1);
lv_obj_remove_style_all(ui_Conainer_label);
lv_obj_set_width( ui_Conainer_label, 480);
lv_obj_set_height( ui_Conainer_label, 480);
lv_obj_set_align( ui_Conainer_label, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Conainer_label, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_label_speed = lv_label_create(ui_Conainer_label);
lv_obj_set_width( ui_label_speed, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_label_speed, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_label_speed, 2 );
lv_obj_set_y( ui_label_speed, -4 );
lv_obj_set_align( ui_label_speed, LV_ALIGN_CENTER );
lv_label_set_text(ui_label_speed,"240");
lv_obj_set_style_text_color(ui_label_speed, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_label_speed, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_label_speed, &ui_font_Int80, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Right_Button = lv_imgbtn_create(ui_Screen1);
lv_imgbtn_set_src(ui_Right_Button, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_images_right_png, NULL);
lv_imgbtn_set_src(ui_Right_Button, LV_IMGBTN_STATE_PRESSED, NULL, &ui_img_images_right_pressed_png, NULL);
lv_obj_set_width( ui_Right_Button, 140);
lv_obj_set_height( ui_Right_Button, 164);
lv_obj_set_align( ui_Right_Button, LV_ALIGN_RIGHT_MID );

lv_obj_add_event_cb(ui_Right_Button, ui_event_Right_Button, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Screen1, ui_event_Screen1, LV_EVENT_ALL, NULL);

}
