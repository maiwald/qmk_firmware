#include QMK_KEYBOARD_H
#include "keymap_german_osx.h"

enum layers {
  _COLEMAK = 0,
  _EXTEND,
  _SYMBOLS,
  _GERMAN,
  _MEDIA
};

enum custom_keycodes {
  MY_SLSH = SAFE_RANGE,
  TMUX_1,
  TMUX_2,
  TMUX_3,
};

#define HOME_A    LCTL_T(DE_A)
#define HOME_O    RCTL_T(DE_O)
#define HOME_R    LSFT_T(DE_R)
#define HOME_I    RSFT_T(DE_I)
#define HOME_4    MT(MOD_LSFT, DE_4)

#define EXT_SPC   LT(_EXTEND, KC_SPC)
#define MEDIA     MO(_MEDIA)
#define OSL_GER   OSL(_GERMAN)
#define OSM_SFT   OSM(MOD_LSFT)
#define SFT_ZERO  MT(MOD_LSFT, DE_0)
#define SYM_BSPC  LT(_SYMBOLS, KC_BSPC)
#define SYM_ENT   LT(_SYMBOLS, KC_ENT)

#define VIM_ALT   C(DE_6)
#define MY_SCSH   G(S(KC_4))

enum combos {
  WF_ESC,
  UY_ENT
};

const uint16_t PROGMEM wf_combo[] = {DE_W, DE_F, COMBO_END};
const uint16_t PROGMEM uy_combo[] = {DE_U, DE_Y, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [WF_ESC] = COMBO(wf_combo, KC_ESC),
  [UY_ENT] = COMBO(uy_combo, KC_ENT)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT_ortho_4x12(
      KC_TAB,  DE_Q,    DE_W,    DE_F,    DE_P,    DE_B,     DE_J,    DE_L,    DE_U,    DE_Y,    KC_TAB,  KC_VOLU,
      KC_ESC,  HOME_A,  HOME_R,  DE_S,    DE_T,    DE_G,     DE_M,    DE_N,    DE_E,    HOME_I,  HOME_O,  KC_VOLD,
      KC_LSFT, DE_Z,    DE_X,    DE_C,    DE_D,    DE_V,     DE_K,    DE_H,    DE_COMM, DE_DOT,  MY_SLSH, KC_RSFT,
      XXXXXXX, XXXXXXX, KC_LALT, KC_LGUI, OSM_SFT, SYM_BSPC, SYM_ENT, EXT_SPC, OSL_GER, MEDIA,   XXXXXXX, XXXXXXX
      ),

  [_EXTEND] = LAYOUT_ortho_4x12(
      XXXXXXX, TMUX_3,  DE_7,    DE_8,    DE_9,     DE_PLUS, XXXXXXX, XXXXXXX, VIM_ALT, XXXXXXX, XXXXXXX, MY_SCSH,
      XXXXXXX, TMUX_2,  HOME_4,  DE_5,    DE_6,     DE_MINS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
      XXXXXXX, TMUX_1,  DE_1,    DE_2,    DE_3,     XXXXXXX, XXXXXXX, XXXXXXX, DE_COMM, DE_DOT,  XXXXXXX, RESET,
      XXXXXXX, _______, _______, _______, SFT_ZERO, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
      ),

  [_SYMBOLS] = LAYOUT_ortho_4x12(
      XXXXXXX, DE_EXLM, DE_LABK, DE_AT,   DE_RABK, DE_PLUS, DE_CIRC, DE_LBRC, DE_UNDS, DE_RBRC, DE_EURO, XXXXXXX,
      XXXXXXX, DE_BSLS, DE_LPRN, DE_DQUO, DE_RPRN, DE_MINS, DE_PERC, DE_LCBR, DE_EQL,  DE_RCBR, DE_PIPE, XXXXXXX,
      XXXXXXX, XXXXXXX, DE_TILD, DE_QUOT, DE_HASH, DE_DLR,  DE_GRV,  DE_AMPR, DE_ASTR, DE_COLN, DE_QUES, XXXXXXX,
      XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
      ),

  [_GERMAN] = LAYOUT_ortho_4x12(
      _______, _______, _______, _______, _______, _______, _______, _______, DE_UDIA, _______, _______, _______,
      _______, DE_ADIA, _______, DE_SS,   _______, _______, _______, _______, _______, _______, DE_ODIA, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      ),

  [_MEDIA] = LAYOUT_ortho_4x12(
      KC_BRIU, RGB_VAI, XXXXXXX, RGB_MOD,  RGB_HUI, RGB_SAI, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,
      KC_BRID, RGB_VAD, XXXXXXX, RGB_RMOD, RGB_HUD, RGB_SAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,
      XXXXXXX, XXXXXXX, XXXXXXX, RGB_M_P,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
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
  uint16_t one_shot_mod_state = get_oneshot_mods();

  switch (keycode) {
    case TMUX_1:
      if (record->event.pressed) {
        tap_code16(C(KC_B));
        tap_code16(KC_1);
      }
      return false;
    case TMUX_2:
      if (record->event.pressed) {
        tap_code16(C(KC_B));
        tap_code16(KC_2);
      }
      return false;
    case TMUX_3:
      if (record->event.pressed) {
        tap_code16(C(KC_B));
        tap_code16(KC_3);
      }
      return false;

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
