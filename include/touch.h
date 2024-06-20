#ifndef TOUCH_H
#define TOUCH_H

#include <XPT2046_Touchscreen.h>
#include <SPI.h>
#include "display.h"

/* Uncomment for XPT2046 */
#define TOUCH_XPT2046
#define TOUCH_XPT2046_SCK 12
#define TOUCH_XPT2046_MISO 13
#define TOUCH_XPT2046_MOSI 11
#define TOUCH_XPT2046_CS 0
#define TOUCH_XPT2046_INT 36
#define TOUCH_XPT2046_ROTATION 0
#define TOUCH_MAP_X1 4000
#define TOUCH_MAP_X2 200
#define TOUCH_MAP_Y1 200
#define TOUCH_MAP_Y2 3600

int touch_last_x = 0, touch_last_y = 0;

#if defined(TOUCH_XPT2046)
#include <XPT2046_Touchscreen.h>
XPT2046_Touchscreen ts(TOUCH_XPT2046_CS, TOUCH_XPT2046_INT);
#endif

void touch_init() {
#if defined(TOUCH_XPT2046)
    SPI.begin(TOUCH_XPT2046_SCK, TOUCH_XPT2046_MISO, TOUCH_XPT2046_MOSI, TOUCH_XPT2046_CS);
    ts.begin();
    ts.setRotation(TOUCH_XPT2046_ROTATION);
#endif
}

bool touch_has_signal() {
#if defined(TOUCH_XPT2046)
    return ts.tirqTouched();
#else
    return false;
#endif
}

bool touch_touched() {
#if defined(TOUCH_XPT2046)
    if (ts.touched()) {
        TS_Point p = ts.getPoint();
#if defined(TOUCH_SWAP_XY)
        touch_last_x = map(p.y, TOUCH_MAP_X1, TOUCH_MAP_X2, 0, tft.width() - 1);
        touch_last_y = map(p.x, TOUCH_MAP_Y1, TOUCH_MAP_Y2, 0, tft.height() - 1);
#else
        touch_last_x = map(p.x, TOUCH_MAP_X1, TOUCH_MAP_X2, 0, tft.width() - 1);
        touch_last_y = map(p.y, TOUCH_MAP_Y1, TOUCH_MAP_Y2, 0, tft.height() - 1);
#endif
        return true;
    } else {
        return false;
    }
#else
    return false;
#endif
}

bool touch_released() {
#if defined(TOUCH_XPT2046)
    return true;
#else
    return false;
#endif
}

#endif // TOUCH_H
