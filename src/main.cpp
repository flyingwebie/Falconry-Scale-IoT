#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <lvgl.h>
#include "ui.h"
#include "touch.h"
#include "display.h"
#include "HX711.h"

// HX711 initialization
const int LOADCELL_DOUT_PIN = 37;
const int LOADCELL_SCK_PIN = 38;
HX711 scale;

float calibration_factor = 2280.0; // Replace with your actual calibration factor

LGFX tft; // Declare the LGFX tft object

static lv_disp_draw_buf_t draw_buf;
static lv_color_t disp_draw_buf1[screenWidth * screenHeight / 8];
static lv_color_t disp_draw_buf2[screenWidth * screenHeight / 8];
static lv_disp_drv_t disp_drv;

/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    tft.pushImageDMA(area->x1, area->y1, w, h, (lgfx::rgb565_t*)&color_p->full);

    lv_disp_flush_ready(disp);
}

void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data) {
    uint16_t touchX, touchY;
    bool touched = tft.getTouch(&touchX, &touchY);
    if (!touched) {
        data->state = LV_INDEV_STATE_REL;
    } else {
        data->state = LV_INDEV_STATE_PR;
        data->point.x = touchX;
        data->point.y = touchY;
    }
}

void setup() {
    Serial.begin(115200);
    Serial.println("Start");

    // HX711 initialization
    scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
    scale.set_scale(calibration_factor);
    scale.tare(); // Reset the scale to 0

    Serial.println("Initializing TFT...");
    tft.begin();
    tft.fillScreen(TFT_BLACK);
    tft.setTextSize(2);
    delay(200);

    Serial.println("Initializing LVGL...");
    lv_init();
    delay(100);

    Serial.println("Initializing LVGL display buffer...");
    lv_disp_draw_buf_init(&draw_buf, disp_draw_buf1, disp_draw_buf2, screenWidth * screenHeight / 8);
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.full_refresh = 1;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    Serial.println("Initializing LVGL input device...");
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register(&indev_drv);

    Serial.println("Clearing screen...");
    tft.fillScreen(TFT_BLACK);

    Serial.println("Initializing UI...");
    ui_init();
    Serial.println("Setup done");
}

void loop() {
    lv_timer_handler(); // Handle LVGL tasks
    delay(1);

    // Log the weight in grams+
    if (scale.is_ready()) {
        float weight = scale.get_units(10); // Get the average of 10 readings
        Serial.print("Weight: ");
        Serial.print(weight);
        Serial.println(" grams");
    } else {
        Serial.println("HX711 not found.");
    }

    delay(1000); // Log weight every second
}
