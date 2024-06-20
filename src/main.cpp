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
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
   uint32_t w = ( area->x2 - area->x1 + 1 );
   uint32_t h = ( area->y2 - area->y1 + 1 );

   tft.pushImageDMA(area->x1, area->y1, w, h,(lgfx::rgb565_t*)&color_p->full);

   lv_disp_flush_ready( disp );

}

void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data) {
    Serial.println("my_touchpad_read called");
    uint16_t touchX, touchY;
    bool touched = tft.getTouch(&touchX, &touchY);
    if (!touched) {
        Serial.println("Something Wrong with the LCD");
        data->state = LV_INDEV_STATE_REL;
    } else {
        Serial.println("Touch detected");
        data->state = LV_INDEV_STATE_PR;
        data->point.x = touchX;
        data->point.y = touchY;

        Serial.print("Data x: ");
        Serial.println(touchX);
        Serial.print("Data y: ");
        Serial.println(touchY);
    }
}


void setup()
{
  Serial.begin(115200);
  Serial.println("Start");

  // HX711 initialization
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(calibration_factor);
  scale.tare(); // Reset the scale to 0

  //Display Prepare
  tft.begin();
  tft.fillScreen(TFT_BLACK);
  tft.setTextSize(2);
  delay(200);

  lv_init();

  delay(100);

  lv_disp_draw_buf_init(&draw_buf, disp_draw_buf1, disp_draw_buf2, screenWidth * screenHeight/8);
  /* Initialize the display */
  lv_disp_drv_init(&disp_drv);
  /* Change the following line to your display resolution */
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.full_refresh = 1;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register(&disp_drv);

  /* Initialize the (dummy) input device driver */
  Serial.println("Initializing LVGL input device...");
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_drv_register(&indev_drv);

  tft.fillScreen(TFT_BLACK);

  //please do not use LVGL Demo and UI export from Squareline Studio in the same time.
  // lv_demo_widgets();    // LVGL demo
  ui_init();               // UI function that comes from ui.c

  Serial.println( "Setup done" );

}

void loop()
{
    lv_timer_handler();
    delay(1);

    // Log the weight in grams
    if (scale.is_ready()) {
        float weight = scale.get_units(10); // Get the average of 10 readings
        Serial.print("Weight: ");
        Serial.print(weight);
        Serial.println(" grams");

        // Update the weight label
        char weight_str[10];
        snprintf(weight_str, sizeof(weight_str), "%.2f g", weight);
        lv_label_set_text(ui_weight_screen_label_value, weight_str);
    } else {
        Serial.println("HX711 not found.");
    }

    delay(1000); // Log weight every second
}
