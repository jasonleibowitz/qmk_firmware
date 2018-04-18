#include "dz60.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

// Fillers to make layering clearer
#define _______ KC_TRNS

#define _DL 0     // DEFAULT LAYER
#define _UTIL 1   // Utility Layer
#define _LIGHTS 2 // LIGHTS LAYER

enum custom_keycodes
{
  DEFAULT_LAYER = SAFE_RANGE,
  ONE_PW,   // Trigger 1Password Helper
  SCRST,     // Take a Screenshot
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_DL] = KEYMAP_2_SHIFTS(
		       KC_ESC,    KC_1,    KC_2,     KC_3,  KC_4,     KC_5,  KC_6,    KC_7,    KC_8,    KC_9,     KC_0, KC_MINS,  KC_EQL, _______, KC_BSPC,
		       KC_TAB,             KC_Q,     KC_W,  KC_E,     KC_R,  KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
		LT(1, KC_ESC),             KC_A,     KC_S,  KC_D,     KC_F,  KC_G,    KC_H,    KC_J,    KC_K,     KC_L, KC_SCLN, KC_QUOT,  KC_ENT,
		      KC_LSFT, KC_TRNS,    KC_Z,     KC_X,  KC_C,     KC_V,  KC_B,    KC_N,    KC_M, KC_COMM,   KC_DOT, KC_SLSH, KC_RSFT, KC_RSFT, KC_RSFT,
		      KC_LCTL, KC_LALT, KC_LGUI, KC_SPACE, MO(2), KC_SPACE, MO(2), KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT),

	[_UTIL] = KEYMAP_2_SHIFTS(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______,  KC_DEL,
		_______,          _______, _______, _______, _______, _______, _______, _______,   KC_UP,  _______, _______, _______, _______,   RESET,
		_______,          KC_VOLD, KC_VOLU, KC_MPLY, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, KC_MPLY, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT),

	[_LIGHTS] = KEYMAP_2_SHIFTS(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______,           ONE_PW,   SCRST, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______,          RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
    case ONE_PW:
      if (record->event.pressed)
      {
        SEND_STRING(SS_LGUI("\\"));
      }
      return false;
      break;
    case SCRST:
      if (record->event.pressed)
      {
        SEND_STRING(SS_LGUI(SS_LSFT("4")));
      }
      return false;
      break;
    case DEFAULT_LAYER:
      if (record->event.pressed)
      {
        print("mode just switched to default layer\n");
        set_single_persistent_default_layer(_DL);
      }
      return false;
      break;
  }
  return true;
};
