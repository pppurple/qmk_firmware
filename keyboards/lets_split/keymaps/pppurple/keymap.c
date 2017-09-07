#include "lets_split.h"
#include "rekeymap.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _UNDERGLOW 3
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  UNDERGLOW,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// for wim.
// Alt + `
#define WIN_IME LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty(Mac)
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Up   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | GUI  |  Fn  | Alt  | Eisu |Lower |Space |Space |Raise | Kana | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'

 * Qwerty(Win)
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl/|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | Enter|
 * | Tab  |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |      |      |      |      |      |      |      |      |      |      |      | /Up  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | MHEN |Lower |Space |Space |Raise | HENK | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
/*
// Mac
[_QWERTY] = KEYMAP( \
  KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_T(KC_UP), \
  KC_LGUI,  _______, KC_LALT, KC_LANG2,LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LANG1,KC_LEFT ,KC_DOWN, KC_RGHT \
),
*/

// Win(USキーボード)
/*
[_QWERTY] = KEYMAP( \
  KC_ESC,       KC_Q,    KC_W,    KC_E,     KC_R,   KC_T,    KC_Y,    KC_U,   KC_I,     KC_O,    KC_P,    KC_BSPC, \
  CTL_T(KC_TAB),KC_A,    KC_S,    KC_D,     KC_F,   KC_G,    KC_H,    KC_J,   KC_K,     KC_L,    KC_SCLN, KC_ENT, \
  KC_LSFT,      KC_Z,    KC_X,    KC_C,     KC_V,   KC_B,    KC_N,    KC_M,   KC_COMM,  KC_DOT,  KC_SLSH, SFT_T(KC_UP), \
  KC_LCTL,      KC_LGUI, KC_LALT, WIN_IME,  LOWER,  KC_SPC,  KC_SPC,  RAISE,  WIN_IME,  KC_LEFT ,KC_DOWN, KC_RGHT \
),
*/

// Win(JIS)
[_QWERTY] = KEYMAP( \
  KC_ESC,       KC_Q,    KC_W,    KC_E,     KC_R,   KC_T,    KC_Y,    KC_U,   KC_I,     KC_O,    KC_P,    KC_BSPC, \
  CTL_T(KC_TAB),KC_A,    KC_S,    KC_D,     KC_F,   KC_G,    KC_H,    KC_J,   KC_K,     KC_L,    KC_SCLN, KC_ENT, \
  KC_LSFT,      KC_Z,    KC_X,    KC_C,     KC_V,   KC_B,    KC_N,    KC_M,   KC_COMM,  KC_DOT,  KC_SLSH, SFT_T(KC_UP), \
  KC_LCTL,      KC_LGUI, KC_LALT, WIN_IME,  LOWER,  KC_SPC,  KC_SPC,  RAISE,  WIN_IME,  KC_LEFT ,KC_DOWN, KC_RGHT \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   !  |   "  |   #  |   $  |   %  |   &  |   '  |  (   |   )  |   =  |   |  |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |ISO # |ISO / |   `  |   ^  |      |   +  |  {   |   }  |   -  |   :  |  @   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |ISO ~ |ISO | |      |   ~  |      |   *  |  [   |   ]  |   _  |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = KEYMAP( \
  KC_EXLM,S(KC_QUOT),KC_HASH,   KC_DLR,  KC_PERC, KC_AMPR, KC_QUOT, KC_LPRN, KC_RPRN, KC_EQL,  KC_PIPE,  KC_DEL, \
  _______, KC_NUHS,  KC_NUBS,   KC_GRV,  KC_CIRC, _______, KC_PLUS, KC_LCBR, KC_RCBR, KC_MINS,S(KC_SCLN),KC_AT, \
  _______,S(KC_NUHS),S(KC_NUBS),_______, KC_TILD, _______, KC_ASTR, KC_LBRC, KC_RBRC, KC_UNDS, KC_BSLS,  _______, \
  _______, _______,  _______,   _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU,  KC_MPLY \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F11 |  F12 |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = KEYMAP( \
  KC_TAB,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL, \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  _______, KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |      |      |      |      |      |UNDER |
 * |      |      |      |      |             |      |      |      |      |      |GLOW  |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  KEYMAP( \
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TG(_UNDERGLOW) \
),

/*
RGB_TOG : RGBLED_TOGGLE: LED ON/OFF
RGB_MOD : RGBLED_STEP_MODE: 点滅モードの切替
RGB_HUI : RGBLED_INCREASE_HUE: 色調の変更(+)
RGB_HUD : RGBLED_DECREASE_HUE: 色調の変更(-)
RGB_SAI : RGBLED_INCREASE_SAT: 彩度の変更(+)
RGB_SAD : RGBLED_DECREASE_SAT: 彩度の変更(-)
RGB_VAI : RGBLED_INCREASE_VAL: 明るさの調整(+)
RGB_VAD : RGBLED_DECREASE_VAL: 明るさの調整(-)
*/
[_UNDERGLOW] = KEYMAP( \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
  _______,  _______,  RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______ \
)

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

qk_tap_dance_action_t tap_dance_actions[] = {
  // write tap dance if need
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
