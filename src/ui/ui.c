// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.11
// Project name: FalconryScale-IoT

#include <stdio.h>
#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////


// SCREEN: ui_loading_screen
void ui_loading_screen_screen_init(void);
void ui_event_loading_screen(lv_event_t * e);
lv_obj_t * ui_loading_screen;
lv_obj_t * ui_loading_screen_container_main_wrapper;
lv_obj_t * ui_loading_screen_image_logo;
lv_obj_t * ui_loading_screen_spinner_spinner;


// SCREEN: ui_weight_screen
void ui_weight_screen_screen_init(void);
lv_obj_t * ui_weight_screen;
lv_obj_t * ui_weight_screen_container_main_wrapper;
lv_obj_t * ui_weight_screen_tabview_tabview1;
lv_obj_t * ui_weight_screen_tabpage_weight;
lv_obj_t * ui_weight_screen_container_container3;
lv_obj_t * ui_weight_screen_label_value;
lv_obj_t * ui_weight_screen_label_grams;
void ui_event_weight_screen_button_button1(lv_event_t * e);
lv_obj_t * ui_weight_screen_button_button1;
lv_obj_t * ui_weight_screen_label_label2;
lv_obj_t * ui_weight_screen_tabpage_settings;
void ui_event_weight_screen_button_button2(lv_event_t * e);
lv_obj_t * ui_weight_screen_button_button2;
lv_obj_t * ui_weight_screen_label_go_back;
lv_obj_t * ui_startevents____initial_actions0;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_loading_screen(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        _ui_screen_change(&ui_weight_screen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 1000, &ui_weight_screen_screen_init);
        //printf("Screen change initiated\n");
    }
}
void ui_event_weight_screen_button_button1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_RELEASED) {
        function_tare(e);
    }
}
void ui_event_weight_screen_button_button2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_RELEASED) {
        _ui_screen_change(&ui_loading_screen, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 500, 0, &ui_loading_screen_screen_init);
    }
}

///////////////////// SCREENS ////////////////////

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp,
                                               lv_palette_main(LV_PALETTE_BLUE),
                                               lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_loading_screen_screen_init();
    ui_weight_screen_screen_init();
    ui_startevents____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_loading_screen);
}