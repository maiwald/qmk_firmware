#include QMK_KEYBOARD_H
#include "keymap_german_mac_iso.h"
#include "achordion.h"

enum layers {
  _COLEMAK = 0,
  _COLEMAK_GERMAN,
  _PUQ,
  _PUQ_GERMAN,
  _EXTEND,
  _SYMBOLS,
  _MEDIA
};

enum custom_keycodes {
  MY_SLSH = SAFE_RANGE,
};

// COLEMAK KEYS
#define COL_SET   DF(_COLEMAK)
#define COL_A     LCTL_T(DE_A)
#define COL_R     LSFT_T(DE_R)
#define COL_I     RSFT_T(DE_I)
#define COL_O     RCTL_T(DE_O)
#define COL_GER   OSL(_COLEMAK_GERMAN)

// PUQ KEYS
#define PUQ_SET   DF(_PUQ)
#define PUQ_H     LCTL_T(DE_H)
#define PUQ_I     LSFT_T(DE_I)
#define PUQ_N     RSFT_T(DE_N)
#define PUQ_S     RCTL_T(DE_S)
#define PUQ_GER   OSL(_PUQ_GERMAN)

#define EXT_SPC   LT(_EXTEND, KC_SPC)
#define HOME_4    MT(MOD_LSFT, DE_4)
#define HOME_5    MT(MOD_LALT, DE_5)
#define HOME_6    MT(MOD_LGUI, DE_6)
#define MEDIA     MO(_MEDIA)
#define SYMBOLS   MO(_SYMBOLS)
#define OSM_SFT   OSM(MOD_LSFT)
#define SFT_ZERO  MT(MOD_LSFT, DE_0)
#define SYM_BSPC  LT(_SYMBOLS, KC_BSPC)
#define SYM_ENT   LT(_SYMBOLS, KC_ENT)

#define VIM_ALT   C(DE_6)
#define APP_TAB   G(DE_GRV)
#define MY_SCSH   G(S(KC_4))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT_ortho_4x12(
      KC_TAB,  DE_Q,    DE_W,    DE_F,    DE_P,    DE_B,    DE_J,    DE_L,    DE_U,    DE_Y,   KC_DEL,  KC_BSPC,
      KC_ESC,  COL_A,   COL_R,   DE_S,    DE_T,    DE_G,    DE_M,    DE_N,    DE_E,    COL_I,  COL_O,   KC_ENT,
      KC_LSFT, DE_Z,    DE_X,    DE_C,    DE_D,    DE_V,    DE_K,    DE_H,    DE_COMM, DE_DOT, MY_SLSH, KC_RSFT,
      KC_LCTL, XXXXXXX, KC_LALT, KC_LGUI, OSM_SFT, SYMBOLS, SYMBOLS, EXT_SPC, COL_GER, MEDIA,  XXXXXXX, XXXXXXX
      ),

  [_PUQ] = LAYOUT_ortho_4x12(
      _______, DE_P,    DE_U,    PUQ_GER, DE_COMM, DE_Q,    DE_G,    DE_C,    DE_L,    DE_M,    DE_F,    _______,
      _______, PUQ_H,   PUQ_I,   DE_E,    DE_A,    DE_O,    DE_D,    DE_T,    DE_R,    PUQ_N,   PUQ_S,   _______,
      _______, DE_K,    DE_Y,    DE_DOT,  MY_SLSH, DE_X,    DE_J,    DE_V,    DE_W,    DE_B,    DE_Z,    _______,
      _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______
      ),

  [_COLEMAK_GERMAN] = LAYOUT_ortho_4x12(
      _______, _______, _______, _______, _______, _______, _______, _______, DE_UDIA, _______, _______, _______,
      _______, DE_ADIA, _______, DE_SS,   _______, _______, _______, _______, _______, _______, DE_ODIA, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      ),

  [_PUQ_GERMAN] = LAYOUT_ortho_4x12(
      _______, _______, DE_UDIA, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, DE_ADIA, DE_ODIA, _______, _______, _______, _______, DE_SS,   _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      ),

  [_EXTEND] = LAYOUT_ortho_4x12(
      APP_TAB, XXXXXXX, DE_7,    DE_8,    DE_9,     DE_PLUS, XXXXXXX, XXXXXXX, VIM_ALT, XXXXXXX, MY_SCSH, _______,
      XXXXXXX, KC_LCTL, HOME_4,  HOME_5,  HOME_6,   DE_MINS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, _______,
      XXXXXXX, XXXXXXX, DE_1,    DE_2,    DE_3,     XXXXXXX, XXXXXXX, XXXXXXX, DE_COMM, DE_DOT,  XXXXXXX, QK_BOOT,
      XXXXXXX, XXXXXXX, _______, _______, SFT_ZERO, KC_BSPC, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
      ),

  [_SYMBOLS] = LAYOUT_ortho_4x12(
      _______, DE_BSLS, DE_LABK, DE_DQUO, DE_RABK, DE_PLUS, DE_CIRC, DE_LBRC, DE_UNDS, DE_RBRC, DE_EURO, KC_BSPC,
      _______, DE_EXLM, DE_LPRN, DE_QUOT, DE_RPRN, DE_MINS, DE_PERC, DE_LCBR, DE_EQL,  DE_RCBR, DE_PIPE, _______,
      _______, XXXXXXX, DE_HASH, DE_AT,   DE_TILD, DE_DLR,  DE_GRV,  DE_AMPR, DE_ASTR, DE_COLN, DE_QUES, _______,
      XXXXXXX, XXXXXXX, _______, _______, _______, KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
      ),

  [_MEDIA] = LAYOUT_ortho_4x12(
      KC_BRIU, RGB_VAI, XXXXXXX, RGB_MOD,  RGB_HUI, RGB_SAI, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,
      KC_BRID, RGB_VAD, XXXXXXX, RGB_RMOD, RGB_HUD, RGB_SAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,
      XXXXXXX, XXXXXXX, XXXXXXX, RGB_M_P,  XXXXXXX, XXXXXXX, COL_SET, PUQ_SET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
      )

};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EXT_SPC:
      return true;
    default:
      return false;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_achordion(keycode, record)) { return false; }

  switch (keycode) {
    case MY_SLSH:
      if (record->event.pressed) {
        if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) {
          tap_code16(DE_QUES);
        } else {
          tap_code16(DE_SLSH);
        }
      }
      return false;
    case KC_ESC:
      if (get_oneshot_mods()) {
        clear_oneshot_mods();
        return false;
      } else {
        return true;
      }
    default:
      return true;
  }
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  if (tap_hold_record->event.key.row == 3) { return true; }
  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
    case HOME_4:
    case HOME_5:
    case HOME_6:
    case EXT_SPC:
      return 0;  // Bypass Achordion for these keys.
  }

  return 800;  // Otherwise use a timeout of 800 ms.
}

void matrix_scan_user(void) {
  achordion_task();
}
