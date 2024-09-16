/*
 * Copyright (c) 2024 Allister MacLeod
 *
 * SPDX-License-Identifier: MIT
 */

#include QMK_KEYBOARD_H

// TO-DO:
// - rearrange layouts to avoid using stretchiest thumb keys (LH0 and RH0)
// - numeric layer
// - symbol layer
// - hot keys in nav layer
// - combos for Z, Q, and Qu
// - home row mods
// - combos for SH, CH, TH, and WH, PH
// - combos for Ctrl, Esc, Backspace, and Tab

enum dasbob_layers {
  _HDNEU,
  _DVORAK,
  _COLEMAK,
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _KEEBCTL
};

#define SYM MO(_LOWER)
#define NAV MO(_RAISE)
#define NUM MO(_ADJUST)
#define KBC TG(_KEEBCTL)

#define HDNEU TO(_HDNEU)
#define DVORAK TO(_DVORAK)
#define COLEMAK TO(_COLEMAK)
#define QWERTY TO(_QWERTY)

#define SM_LALT OSM(MOD_LALT)
#define SM_RCTL OSM(MOD_RCTL)
#define SM_RGUI OSM(MOD_RGUI)
#define SM_RSFT OSM(MOD_RSFT)

enum custom_keycodes {
  KC_QU = SAFE_RANGE,
};

enum combos {
  COMBO_KBDCTL,
  COMBO_ZED,
  COMBO_Q,
  COMBO_QU
};

const uint16_t PROGMEM esc_bks_combo[] = {KC_ESC, KC_BACKSPACE, COMBO_END};
const uint16_t PROGMEM wf_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM uoy_combo[] = {KC_U, KC_O, KC_Y, COMBO_END};
const uint16_t PROGMEM uy_combo[] = {KC_U, KC_Y, COMBO_END};

combo_t key_combos[] = {
  [COMBO_KBDCTL] = COMBO(esc_bks_combo, KBC),
  [COMBO_ZED] = COMBO(wf_combo, KC_Z),
  [COMBO_Q] = COMBO(uoy_combo, KC_Q),
  [COMBO_QU] = COMBO(uy_combo, KC_QU)
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  const uint8_t mods = get_mods();
  const uint8_t oneshot_mods = get_oneshot_mods();

  switch (keycode) {
  case KC_QU:
    if (record->event.pressed) {
      if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
        del_oneshot_mods(MOD_MASK_SHIFT);
        unregister_mods(MOD_MASK_SHIFT);
        SEND_STRING("Qu");
        register_mods(mods);
      } else {
        SEND_STRING("qu");
      }
    }
    return false;
  }
  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Hands Down Neu
 * ,-----------------------------.   ,-----------------------------.
 * |  W  |  F  |  M  |  P  |  V  |   |  /  |  .  |  '  |  "  |  J  |
 * |  R  |  S  |  N  |  T  |  B  |   |  ,  |  A  |  E  |  I  |  H  |
 * |  X  |  C  |  L  |  D  |  G  |   |  -  |  U  |  O  |  Y  |  K  |
 * `-----------| SYM | Shf | Esc |   | Bks | Spc | NAV |-----------'
 */
[_HDNEU] = LAYOUT_split_3x5_3(
KC_W,    KC_F,    KC_M,    KC_P,    KC_V,        KC_SLSH, KC_DOT,  KC_QUOT, KC_DQT,  KC_J,
KC_R,    KC_S,    KC_N,    KC_T,    KC_B,        KC_COMM, KC_A,    KC_E,    KC_I,    KC_H,
KC_X,    KC_C,    KC_L,    KC_D,    KC_G,        KC_MINS, KC_U,    KC_O,    KC_Y,    KC_K,
                      SYM, KC_LSFT, KC_ESC,   KC_BACKSPACE, KC_SPACE, NAV
),
/* Dvorak
 * ,-----------------------------.   ,-----------------------------.
 * |  '  |  ,  |  .  |  P  |  Y  |   |  F  |  G  |  C  |  R  |  L  |
 * |  A  |  O  |  E  |  U  |  I  |   |  D  |  H  |  T  |  N  |  S  |
 * |  ;  |  Q  |  J  |  K  |  X  |   |  B  |  M  |  W  |  V  |  Z  |
 * `-----------| SYM | Shf | Esc |   | Bks | Spc | NAV |-----------'
 */
[_DVORAK] = LAYOUT_split_3x5_3(
KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,        KC_F,    KC_G,    KC_C,    KC_R,    KC_L,
KC_A,    KC_O,    KC_E,    KC_U,    KC_I,        KC_D,    KC_H,    KC_T,    KC_N,    KC_S,
KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,        KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,
                      SYM, KC_LSFT, KC_ESC,   KC_BACKSPACE, KC_SPACE, NAV
),
/* Colemak-DH
 * ,-----------------------------.   ,-----------------------------.
 * |  Q  |  W  |  F  |  P  |  B  |   |  J  |  L  |  U  |  Y  |  '  |
 * |  A  |  R  |  S  |  T  |  G  |   |  M  |  N  |  E  |  I  |  O  |
 * |  Z  |  X  |  C  |  D  |  V  |   |  K  |  H  |  ,  |  .  |  /  |
 * `-----------| SYM | Shf | Esc |   | Bks | Spc | NAV |-----------'
 */
[_COLEMAK] = LAYOUT_split_3x5_3(
KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,        KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
KC_A,    KC_R,    KC_S,    KC_T,    KC_G,        KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,        KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                      SYM, KC_LSFT, KC_ESC,   KC_BACKSPACE, KC_SPACE, NAV
),
/* QWERTY
 * ,-----------------------------.   ,-----------------------------.
 * |  Q  |  W  |  E  |  R  |  T  |   |  Y  |  U  |  I  |  O  |  P  |
 * |  A  |  S  |  D  |  F  |  G  |   |  H  |  J  |  K  |  L  |  ;  |
 * |  Z  |  X  |  C  |  V  |  B  |   |  N  |  M  |  ,  |  .  |  /  |
 * `-----------| SYM | Shf | Esc |   | Bks | Spc | NAV |-----------'
 */
[_QWERTY] = LAYOUT_split_3x5_3(
KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                      SYM, KC_LSFT, KC_ESC,   KC_BACKSPACE, KC_SPACE, NAV
),
/* Symbols Layer (LOWER)
 * ,-----------------------------.   ,-----------------------------.
 * |  `  |  <  |  >  |  "  |  '  |   |  &  |  :  |  [  |  ]  |  _  |
 * |  !  |  -  |  +  |  =  |  #  |   |  |  |  ;  |  {  |  }  |  ?  |
 * |  ~  |  /  |  *  |  %  |  @  |   |  ^  |  $  |  (  |  )  |  /  |
 * `-----------|#####|     |     |   |     |  \  | NUM |-----------'
 */
[_LOWER] = LAYOUT_split_3x5_3(
KC_GRV,  KC_LABK, KC_RABK, KC_DQT,  KC_QUOT,     KC_AMPR, KC_COLN, KC_LBRC, KC_RBRC, KC_UNDS,
KC_EXLM, KC_MINS, KC_PLUS, KC_EQL,  KC_HASH,     KC_PIPE, KC_SCLN, KC_LCBR, KC_RCBR, KC_QUES,
KC_TILD, KC_SLSH, KC_ASTR, KC_PERC, KC_AT,       KC_CIRC, KC_DLR,  KC_LPRN, KC_RPRN, KC_SLSH,
                    _______, _______, _______,   _______, KC_BSLS, NUM
),
/* Navigation Layer (RAISE)
 * ,-----------------------------.   ,-----------------------------.
 * |     |     |     |     |     |   | Hom | PgUp|  Up | PgDn| Bks |
 * |     |     |     |     |     |   | End | Left| Down|Right| Ret |
 * |     |     |     |     | Del |   | GUI | Ctl |Shift| Alt | Tab |
 * `-----------| NUM |     | Ins |   |     |     |#####|-----------'
 */
[_RAISE] = LAYOUT_split_3x5_3(
_______, _______, _______, _______, _______,       KC_HOME, KC_PGUP, KC_UP,   KC_PGDN, KC_BSPC,
_______, _______, _______, _______, _______,       KC_END,  KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,
_______, _______, _______, _______, KC_DEL,        SM_RGUI, SM_RCTL, SM_RSFT, SM_LALT, KC_TAB,
                          NUM, _______, KC_INS,   _______, _______, ______
),
/* Numeric Layer (ADJUST)
 * ,-----------------------------.   ,-----------------------------.
 * |     |     |     |     |     |   |     |     |     |     |     |
 * |     |     |     |     |     |   |     |     |     |     |     |
 * |     |     |     |     |     |   |     |     |     |     |     |
 * `-----------|     |#####|     |   |     |#####|     |-----------'
 */
[_ADJUST] = LAYOUT_split_3x5_3(
_______, _______, _______, _______, _______,       _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______,       _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______,       _______, _______, _______, _______, _______,
                     _______, _______, _______,   _______, _______, _______
),
/* Keyboard Control Layer
 * ,-----------------------------.   ,-----------------------------.
 * |     |HDNeu|Dvork|Clmak|     |   |     |     |     |     |     |
 * |QWRTY|     |     |     |     |   |     |     |     |     |     |
 * |     |     |     |     |     |   |     |     |     |     |     |
 * `-----------|     |     |     |   |     |     |     |-----------'
 */
[_KEEBCTL] = LAYOUT_split_3x5_3(
_______,   HDNEU,  DVORAK, COLEMAK, _______,       _______, _______, _______, _______, _______,
 QWERTY, _______, _______, _______, _______,       _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______,       _______, _______, _______, _______, _______,
                     _______, _______, _______,   _______, _______, _______
),
};


/*
 * ,-----------------------------.   ,-----------------------------.
 * |     |     |     |     |     |   |     |     |     |     |     |
 * |     |     |     |     |     |   |     |     |     |     |     |
 * |     |     |     |     |     |   |     |     |     |     |     |
 * `-----------|     |     |     |   |     |     |     |-----------'
 */
