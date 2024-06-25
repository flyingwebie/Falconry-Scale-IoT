// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "ui.h"

void ui_Loading_Screen_screen_init(void)
{
    ui_Loading_Screen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Loading_Screen,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_event_cb(ui_Loading_Screen, scr_unloaded_delete_cb, LV_EVENT_SCREEN_UNLOADED, &ui_Loading_Screen);

    ui_Loading_Screen_Wrapper = lv_obj_create(ui_Loading_Screen);
    lv_obj_remove_style_all(ui_Loading_Screen_Wrapper);
    lv_obj_set_width(ui_Loading_Screen_Wrapper, lv_pct(100));
    lv_obj_set_height(ui_Loading_Screen_Wrapper, lv_pct(100));
    lv_obj_set_align(ui_Loading_Screen_Wrapper, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Loading_Screen_Wrapper, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    ui_object_set_themeable_style_property(ui_Loading_Screen_Wrapper, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_COLOR,
                                           _ui_theme_color_Secondary);
    ui_object_set_themeable_style_property(ui_Loading_Screen_Wrapper, LV_PART_MAIN | LV_STATE_DEFAULT, LV_STYLE_BG_OPA,
                                           _ui_theme_alpha_Secondary);

    ui_Loading_Screen_Logo = lv_img_create(ui_Loading_Screen_Wrapper);
    lv_img_set_src(ui_Loading_Screen_Logo, &ui_img_logo_png);
    lv_obj_set_width(ui_Loading_Screen_Logo, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Loading_Screen_Logo, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Loading_Screen_Logo, 0);
    lv_obj_set_y(ui_Loading_Screen_Logo, -50);
    lv_obj_set_align(ui_Loading_Screen_Logo, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Loading_Screen_Logo, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Loading_Screen_Logo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Loading_Screen_Spinner = lv_spinner_create(ui_Loading_Screen_Wrapper, 1000, 90);
    lv_obj_set_width(ui_Loading_Screen_Spinner, 40);
    lv_obj_set_height(ui_Loading_Screen_Spinner, 40);
    lv_obj_set_x(ui_Loading_Screen_Spinner, 0);
    lv_obj_set_y(ui_Loading_Screen_Spinner, 50);
    lv_obj_set_align(ui_Loading_Screen_Spinner, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Loading_Screen_Spinner, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_arc_color(ui_Loading_Screen_Spinner, lv_color_hex(0xFA4100), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_Loading_Screen_Spinner, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_Loading_Screen_Spinner, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_object_set_themeable_style_property(ui_Loading_Screen_Spinner, LV_PART_INDICATOR | LV_STATE_DEFAULT,
                                           LV_STYLE_ARC_COLOR, _ui_theme_color_Primary);
    ui_object_set_themeable_style_property(ui_Loading_Screen_Spinner, LV_PART_INDICATOR | LV_STATE_DEFAULT,
                                           LV_STYLE_ARC_OPA, _ui_theme_alpha_Primary);
    lv_obj_set_style_arc_width(ui_Loading_Screen_Spinner, 5, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Loading_Screen, ui_event_Loading_Screen, LV_EVENT_ALL, NULL);

}
