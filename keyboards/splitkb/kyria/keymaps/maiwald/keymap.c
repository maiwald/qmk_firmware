#include QMK_KEYBOARD_H
#include "keymap_german_mac_iso.h"
#include "achordion.h"

enum layers {
  _COLEMAK = 0,
  _EXTEND,
  _SYMBOLS,
  _GERMAN,
  _MEDIA,
};

enum custom_keycodes {
  MY_SLSH = SAFE_RANGE,
};

// home row mods
#define MY_A LCTL_T(DE_A)
#define MY_R LSFT_T(DE_R)
#define MY_I RSFT_T(DE_I)
#define MY_O RCTL_T(DE_O)

// home row mods (extend)
#define MY_4    LSFT_T(DE_4)
#define MY_5    LALT_T(DE_5)
#define MY_6    LGUI_T(DE_6)

#define VIM_ALT C(DE_6)
#define KC_EUR  S(A(KC_2))
#define MY_ALT  TD(TD_GER_ALT)
#define APP_TAB G(DE_GRV)
#define MY_SCSH G(S(KC_4))

#define EXT_SPC  LT(_EXTEND, KC_SPC)
#define SFT_ZERO MT(MOD_LSFT, DE_0)

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EXT_SPC:
      return 0;
    default:
      return QUICK_TAP_TERM;
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT(
      KC_TAB,  DE_Q, DE_W, DE_F,    DE_P,    DE_B,                                                          DE_J,    DE_L,         DE_U,    DE_Y,   KC_DEL,  KC_BSPC,
      KC_ESC,  MY_A, MY_R, DE_S,    DE_T,    DE_G,                                                          DE_M,    DE_N,         DE_E,    MY_I,   MY_O,    KC_ENT,
      KC_LSFT, DE_Z, DE_X, DE_C,    DE_D,    DE_V,          KC_BSPC,       XXXXXXX, XXXXXXX, KC_ENT,        DE_K,    DE_H,         DE_COMM, DE_DOT, MY_SLSH, KC_RSFT,
                           KC_LALT, KC_LGUI, OSM(MOD_LSFT), OSL(_SYMBOLS), KC_LSFT, KC_RSFT, OSL(_SYMBOLS), EXT_SPC, OSL(_GERMAN), MO(_MEDIA)
      ),

  [_EXTEND] = LAYOUT(
      APP_TAB, XXXXXXX, DE_7,   DE_8,    DE_9,    DE_PLUS,                                      XXXXXXX, XXXXXXX, VIM_ALT, XXXXXXX, MY_SLSH, _______,
      _______, XXXXXXX, MY_4,   MY_5,    MY_6,    DE_MINS,                                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, _______,
      _______, XXXXXXX, DE_1,   DE_2,    DE_3,    XXXXXXX,  _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, DE_COMM, DE_DOT,  DE_SLSH, XXXXXXX,
                                _______, _______, SFT_ZERO, KC_LALT, XXXXXXX, XXXXXXX, _______, _______, _______, _______
      ),

  [_SYMBOLS] = LAYOUT(
      XXXXXXX, DE_BSLS, DE_LABK, DE_DQUO, DE_RABK, DE_PLUS,                                     DE_CIRC, DE_LBRC, DE_UNDS, DE_RBRC, DE_EURO, _______,
      XXXXXXX, DE_EXLM, DE_LPRN, DE_QUOT, DE_RPRN, DE_MINS,                                     DE_PERC, DE_LCBR, DE_EQL,  DE_RCBR, DE_PIPE, _______,
      XXXXXXX, XXXXXXX, DE_HASH, DE_AT,   DE_DLR,  DE_TILD, _______, XXXXXXX, XXXXXXX, _______, DE_GRV,  DE_AMPR, DE_ASTR, DE_COLN, DE_QUES, XXXXXXX,
                                 _______, _______, KC_SPC,  _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______
      ),

  [_GERMAN] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, DE_UDIA, _______, _______, _______,
      _______, DE_ADIA, _______, DE_SS,   _______, _______,                                     _______, _______, _______, _______, DE_ODIA, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      ),

  [_MEDIA] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY, KC_VOLU,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
      ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_achordion(keycode, record)) { return false; }

  uint16_t one_shot_mod_state = get_oneshot_mods();

  switch (keycode) {
    case KC_TRNS:
    case KC_NO:
      /* Always cancel one-shot layer when another key gets pressed */
      if (record->event.pressed && is_oneshot_layer_active())
      clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
      return true;
    case MY_SLSH:
      if (record->event.pressed) {
        if ((get_mods() | one_shot_mod_state) & MOD_MASK_SHIFT) {
          tap_code16(DE_QUES);
        } else {
          tap_code16(DE_SLSH);
        }
      }
      return false;
    case KC_ESC:
      if (one_shot_mod_state) {
        clear_oneshot_mods();
        return false;
      } else {
        return true;
      }
    default:
      return true;
  }
}

/**
 * Optional callback to customize which key chords are considered "held".
 *
 * This callback is called if while `tap_hold_keycode` is pressed,
 * `other_keycode` is pressed. Return true if the tap-hold key should be
 * considered held, or false to consider it tapped.
 *
 * @param tap_hold_keycode Keycode of the tap-hold key.
 * @param tap_hold_record keyrecord_t from the tap-hold press event.
 * @param other_keycode Keycode of the other key.
 * @param other_record keyrecord_t from the other key's press event.
 * @return True if the tap-hold key should be considered held.
 */
bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  if (MY_A == tap_hold_keycode) { return true; }
  if (tap_hold_record->event.key.row % (MATRIX_ROWS / 2) == 4) { return true; }
  return achordion_opposite_hands(tap_hold_record, other_record);
}

/**
 * Optional callback to define a timeout duration per keycode.
 *
 * The callback determines Achordion's timeout duration for `tap_hold_keycode`
 * in units of milliseconds. The timeout be in the range 0 to 32767 ms (upper
 * bound is due to 16-bit timer limitations). Use a timeout of 0 to bypass
 * Achordion.
 *
 * @param tap_hold_keycode Keycode of the tap-hold key.
 * @return Timeout duration in milliseconds in the range 0 to 32767.
 */
uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
    case MY_4:
    case MY_5:
    case MY_6:
    case EXT_SPC:
      return 0;  // Bypass Achordion for these keys.
  }

  return 800;  // Otherwise use a timeout of 800 ms.
}

void matrix_scan_user(void) {
  achordion_task();
}
