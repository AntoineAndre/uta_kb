#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x3141
#define DEVICE_VER		0x0001
#define MANUFACTURER    Antoine Andre
#define PRODUCT         uta

/* key matrix size */
#define MATRIX_ROWS 1
#define MATRIX_COLS 4

/* key matrix pins */
#define DIRECT_PINS { \
    { D7, C6, D4 } \
}

#define ENCODERS_PAD_A { F7 }
#define ENCODERS_PAD_B { F6 }
#define ENCODER_RESOLUTION 4

#define UNUSED_PINS

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5