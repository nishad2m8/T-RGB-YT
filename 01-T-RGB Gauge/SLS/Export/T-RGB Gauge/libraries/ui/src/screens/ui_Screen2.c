// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.11
// Project name: T-RGB Gauge

#include "../ui.h"

void ui_Screen2_screen_init(void)
{
ui_Screen2 = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Screen2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Screen2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Screen2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_ImgButton3 = lv_imgbtn_create(ui_Screen2);
lv_imgbtn_set_src(ui_ImgButton3, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_images_left_png, NULL);
lv_imgbtn_set_src(ui_ImgButton3, LV_IMGBTN_STATE_PRESSED, NULL, &ui_img_1557908308, NULL);
lv_obj_set_height( ui_ImgButton3, 154);
lv_obj_set_width( ui_ImgButton3, LV_SIZE_CONTENT);  /// 1
lv_obj_set_align( ui_ImgButton3, LV_ALIGN_LEFT_MID );

ui_car = lv_obj_create(ui_Screen2);
lv_obj_remove_style_all(ui_car);
lv_obj_set_width( ui_car, 480);
lv_obj_set_height( ui_car, 480);
lv_obj_set_align( ui_car, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_car, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_imgcar = lv_img_create(ui_car);
lv_img_set_src(ui_imgcar, &ui_img_1465642558);
lv_obj_set_width( ui_imgcar, LV_SIZE_CONTENT);  /// 194
lv_obj_set_height( ui_imgcar, LV_SIZE_CONTENT);   /// 392
lv_obj_set_x( ui_imgcar, 0 );
lv_obj_set_y( ui_imgcar, 2400 );
lv_obj_set_align( ui_imgcar, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_imgcar, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_imgcar, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

lv_obj_add_event_cb(ui_ImgButton3, ui_event_ImgButton3, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Screen2, ui_event_Screen2, LV_EVENT_ALL, NULL);

}
