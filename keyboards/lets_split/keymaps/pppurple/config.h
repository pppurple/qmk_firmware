#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../rev2/config.h"

#undef RGBLED_NUM

#define TAPPING_TERM 200
#define RGBLIGHT_ANIMATIONS
// LEDの合計数
#define RGBLED_NUM 10
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17

/*
#define RGBLIGHT_ANIMATIONS    // Underglow animations.
#define RGB_DI_PIN B0          // The pin your RGB strip is wired to
#define RGBLED_NUM 35          // Number of LEDs
#define RGBLIGHT_HUE_STEP 5    // How much each press of rgb_hue changes hue
#define RGBLIGHT_SAT_STEP 10   // How much each press of rgb_sat changes sat
#define RGBLIGHT_VAL_STEP 10   // How much each press of rgb_val changes val
*/

#define USE_SERIAL
#define EE_HANDS

#define randadd 53
#define randmul 181
#define randmod 167

// #define _______ KC_TRNS
// #define XXXXXXX KC_NO

#endif
