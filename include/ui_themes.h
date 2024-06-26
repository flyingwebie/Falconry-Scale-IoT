// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#ifndef _UI_THEMES_H
#define _UI_THEMES_H

#ifdef __cplusplus
extern "C" {
#endif

#define UI_THEME_COLOR_PRIMARY 0
#define UI_THEME_COLOR_SECONDARY 1
#define UI_THEME_COLOR_BASE 2
#define UI_THEME_COLOR_TEXT 3

#define UI_THEME_DEFAULT 0

#define UI_THEME_LIGHT 1

#define UI_THEME_DARK 2

extern const ui_theme_variable_t _ui_theme_color_Primary[3];
extern const ui_theme_variable_t _ui_theme_alpha_Primary[3];

extern const ui_theme_variable_t _ui_theme_color_Secondary[3];
extern const ui_theme_variable_t _ui_theme_alpha_Secondary[3];

extern const ui_theme_variable_t _ui_theme_color_Base[3];
extern const ui_theme_variable_t _ui_theme_alpha_Base[3];

extern const ui_theme_variable_t _ui_theme_color_Text[3];
extern const ui_theme_variable_t _ui_theme_alpha_Text[3];

extern const uint32_t * ui_theme_colors[3];
extern const uint8_t * ui_theme_alphas[3];
extern uint8_t ui_theme_idx;

void ui_theme_set(uint8_t theme_idx);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
