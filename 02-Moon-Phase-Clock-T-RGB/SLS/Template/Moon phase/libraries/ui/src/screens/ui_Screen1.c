// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.11
// Project name: Moon phase

#include "../ui.h"

void ui_Screen1_screen_init(void)
{
ui_Screen1 = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Screen1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Img_bg = lv_img_create(ui_Screen1);
lv_img_set_src(ui_Img_bg, &ui_img_images_bg_png);
lv_obj_set_width( ui_Img_bg, LV_SIZE_CONTENT);  /// 480
lv_obj_set_height( ui_Img_bg, LV_SIZE_CONTENT);   /// 480
lv_obj_set_align( ui_Img_bg, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Img_bg, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Img_bg, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_img_recolor(ui_Img_bg, lv_color_hex(0x000000), LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_img_recolor_opa(ui_Img_bg, 2, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Container_time = lv_obj_create(ui_Screen1);
lv_obj_remove_style_all(ui_Container_time);
lv_obj_set_width( ui_Container_time, 360);
lv_obj_set_height( ui_Container_time, 120);
lv_obj_set_x( ui_Container_time, 5 );
lv_obj_set_y( ui_Container_time, 100 );
lv_obj_set_align( ui_Container_time, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Container_time, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Label_time = lv_label_create(ui_Container_time);
lv_obj_set_width( ui_Label_time, 234);
lv_obj_set_height( ui_Label_time, 113);
lv_obj_set_x( ui_Label_time, -34 );
lv_obj_set_y( ui_Label_time, -5 );
lv_obj_set_align( ui_Label_time, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label_time,"10:10");
lv_obj_set_style_text_align(ui_Label_time, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label_time, &ui_font_OW120, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label_ampm = lv_label_create(ui_Container_time);
lv_obj_set_width( ui_Label_ampm, 64);
lv_obj_set_height( ui_Label_ampm, 50);
lv_obj_set_x( ui_Label_ampm, 126 );
lv_obj_set_y( ui_Label_ampm, -26 );
lv_obj_set_align( ui_Label_ampm, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label_ampm,"AM");
lv_obj_set_style_text_align(ui_Label_ampm, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label_ampm, &ui_font_OW50, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label_sec = lv_label_create(ui_Container_time);
lv_obj_set_width( ui_Label_sec, 64);
lv_obj_set_height( ui_Label_sec, 50);
lv_obj_set_x( ui_Label_sec, 127 );
lv_obj_set_y( ui_Label_sec, 22 );
lv_obj_set_align( ui_Label_sec, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label_sec,"10");
lv_obj_set_style_text_align(ui_Label_sec, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label_sec, &ui_font_OW50, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Img_earth = lv_img_create(ui_Screen1);
lv_img_set_src(ui_Img_earth, &ui_img_images_earth_png);
lv_obj_set_width( ui_Img_earth, LV_SIZE_CONTENT);  /// 480
lv_obj_set_height( ui_Img_earth, LV_SIZE_CONTENT);   /// 156
lv_obj_set_x( ui_Img_earth, -1 );
lv_obj_set_y( ui_Img_earth, 199 );
lv_obj_set_align( ui_Img_earth, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Img_earth, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Img_earth, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Label_phase = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Label_phase, 197);
lv_obj_set_height( ui_Label_phase, 43);
lv_obj_set_x( ui_Label_phase, -112 );
lv_obj_set_y( ui_Label_phase, -14 );
lv_obj_set_align( ui_Label_phase, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label_phase,"NEW MOON");
lv_obj_set_style_text_align(ui_Label_phase, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label_phase, &ui_font_OW40, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label_date = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Label_date, 188);
lv_obj_set_height( ui_Label_date, 45);
lv_obj_set_x( ui_Label_date, 116 );
lv_obj_set_y( ui_Label_date, -14 );
lv_obj_set_align( ui_Label_date, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label_date,"22-JUL-24");
lv_obj_set_style_text_align(ui_Label_date, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label_date, &ui_font_OW40, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Img_moon = lv_img_create(ui_Screen1);
lv_img_set_src(ui_Img_moon, &ui_img_images_moon_moon_1_png);
lv_obj_set_width( ui_Img_moon, LV_SIZE_CONTENT);  /// 170
lv_obj_set_height( ui_Img_moon, LV_SIZE_CONTENT);   /// 170
lv_obj_set_x( ui_Img_moon, -33 );
lv_obj_set_y( ui_Img_moon, -108 );
lv_obj_set_align( ui_Img_moon, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Img_moon, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Img_moon, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Label1 = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Label1, 13);
lv_obj_set_height( ui_Label1, 43);
lv_obj_set_x( ui_Label1, 0 );
lv_obj_set_y( ui_Label1, -14 );
lv_obj_set_align( ui_Label1, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label1,"|");
lv_obj_set_style_text_align(ui_Label1, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label1, &ui_font_OW40, LV_PART_MAIN| LV_STATE_DEFAULT);

}