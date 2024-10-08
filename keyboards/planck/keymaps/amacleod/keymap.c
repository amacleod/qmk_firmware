#include QMK_KEYBOARD_H
#include "features/layer_lock.h"
#include "features/singular_shift.h"


enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _HDNEU,
  _STURDY,
  _DEXTER,
  _SINISTER,
  _ELEVATE,
  _OVERLAY,
  _GAMING
};


#define QWERTY  TO(_QWERTY)
#define COLEMAK TO(_COLEMAK)
#define DVORAK  TO(_DVORAK)
#define HDNEU   TO(_HDNEU)
#define STURDY  TO(_STURDY)
/* I found that it was too easy to get multiple spaces by
   fat-fingering the central spacebar and one of the layer taps, so I
   will try using just MO on the side layers and let the actual
   spacebar be the only thing that sends space. ~ACM 2024-05-03 */
// #define DEX_TAP LT(_DEXTER, KC_SPACE)
// #define SIN_TAP LT(_SINISTER, KC_SPACE)
#define DEXTER  MO(_DEXTER)
#define SINISTR MO(_SINISTER)
#define ELEVATE MO(_ELEVATE)
#define OVERLAY MO(_OVERLAY)
#define OVER_ON TO(_OVERLAY)
#define OVERTOG TG(_OVERLAY)
#define GAME_ON TO(_GAMING)
#define GAMETOG TG(_GAMING)

/* Not currently using home row mod-tap, since it seems to introduce
   some sluggishness in normal typing. ~AM 2024-04-14 */
// Dvorak home row mods: -AOEU--HTNS-
#define HL_GUI_A LGUI_T(KC_A)
#define HO_ALT_O LALT_T(KC_O)
#define HL_CTL_E LCTL_T(KC_E)
#define HL_SFT_U LSFT_T(KC_U)

#define HR_SFT_H RSFT_T(KC_H)
#define HR_CTL_T RCTL_T(KC_T)
#define HO_ALT_N LALT_T(KC_N)
#define HR_GUI_S RGUI_T(KC_S)

// Colemak home row mods: -ARST--NEIO-
#define HO_ALT_R LALT_T(KC_R)
#define HL_CTL_S LCTL_T(KC_S)
#define HL_SFT_T LSFT_T(KC_T)

#define HR_SFT_N RSFT_T(KC_N)
#define HR_CTL_E RCTL_T(KC_E)
#define HO_ALT_I LALT_T(KC_I)
#define HR_GUI_O RGUI_T(KC_O)

// QWERTY home row mods: -ASDF--JKL;-
#define HO_ALT_S LALT_T(KC_S)
#define HL_CTL_D LCTL_T(KC_D)
#define HL_SFT_F LSFT_T(KC_F)

#define HR_SFT_J RSFT_T(KC_J)
#define HR_CTL_K RCTL_T(KC_K)
#define HO_ALT_L LALT_T(KC_L)
#define HR_GSCLN RGUI_T(KC_SCLN)

// One-shot mods (sticky mod keys)
#define OM_LCTL OSM(MOD_LCTL)
#define OM_LALT OSM(MOD_LALT)
#define OM_LGUI OSM(MOD_LGUI)
#define OM_LSFT OSM(MOD_LSFT)
#define OM_RCTL OSM(MOD_RCTL)
#define OM_RSFT OSM(MOD_RSFT)

// Other tap mods
#define TCTLESC LCTL_T(KC_ESC)
#define TCTLTAB LCTL_T(KC_TAB)


enum custom_keycodes {
  LLOCK = SAFE_RANGE,
  UPDIR
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
#ifdef SINGULAR_SHIFT_ENABLE
  if (!process_singular_shift(keycode, record)) { return false; }
#endif  // SINGULAR_SHIFT_ENABLE

  switch (keycode) {
  case UPDIR:
    if (record->event.pressed) {
      SEND_STRING("../");
    }
    return false;
  }

  return true;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  |Ovrlay| Dext |    Space    |Sinist| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_mit(
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  TCTLTAB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SC_SENT,
  KC_LCTL, KC_LALT, KC_LGUI, OVERLAY, DEXTER,       KC_SPC,      SINISTR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),
/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  |Ovrlay| Dext |    Space    |Sinist| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_mit(
  KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
  TCTLTAB, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SC_SENT,
  KC_LCTL, KC_LALT, KC_LGUI, OVERLAY, DEXTER,       KC_SPC,      SINISTR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),
/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  |Ovrlay| Dext |    Space    |Sinist| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_planck_mit(
  KC_ESC,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,   KC_F,    KC_G,    KC_C,    KC_R,    KC_L,  KC_BSPC,
  TCTLTAB, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,   KC_D,    KC_H,    KC_T,    KC_N,    KC_S,  KC_MINS,
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,   KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,  SC_SENT,
  KC_LCTL, KC_LALT, KC_LGUI, OVERLAY, DEXTER,       KC_SPC,     SINISTR, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
),
/* Hands Down Neu (modified to personal preference)
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   W  |   F  |   M  |   P  |   V  |   /  |   .  |   Q  |   '  |   Z  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   R  |   S  |   N  |   T  |   B  |   ,  |   A  |   E  |   I  |   H  |  J   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   X  |   C  |   L  |   D  |   G  |   -  |   U  |   O  |   Y  |   K  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  |Ovrlay| Dext |    Space    |Sinist| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
/* Allister's modifications from basic H.D. Neu
 * (https://sites.google.com/alanreiser.com/handsdown/home/hands-down-neu)
 * - move Z to right-hand pinky high, allowing Backspace to stay where it is
 * - re-combine apostrophe and quote to make room for Z
 * Ideas to try next:
 * - put ! and ? as shifts of , and . as described by P. Getreuer's
 *   symbol layer doc: https://getreuer.info/posts/keyboards/symbol-layer/index.html
 *   (using custom shift keys: https://getreuer.info/posts/keyboards/custom-shift-keys/index.html)
 */
[_HDNEU] = LAYOUT_planck_mit(
  KC_ESC,  KC_W,    KC_F,    KC_M,    KC_P,    KC_V,   KC_SLSH, KC_DOT,  KC_Q,    KC_QUOT, KC_Z,    KC_BSPC,
  TCTLTAB, KC_R,    KC_S,    KC_N,    KC_T,    KC_B,   KC_COMM, KC_A,    KC_E,    KC_I,    KC_H,    KC_J,
  KC_LSFT, KC_X,    KC_C,    KC_L,    KC_D,    KC_G,   KC_MINS, KC_U,    KC_O,    KC_Y,    KC_K,    SC_SENT,
  KC_LCTL, KC_LALT, KC_LGUI, OVERLAY, DEXTER,       KC_SPC,     SINISTR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),
/* Sturdy
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   V  |   M  |   L  |   C  |   P  |   X  |   F  |   O  |   U  |   J  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   S  |   T  |   R  |   D  |   Y  |   .  |   N  |   A  |   E  |   I  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   K  |   Q  |   G  |   W  |   B  |   H  |   '  |   ;  |   ,  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  |Ovrlay| Dext |    Space    |Sinist| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_STURDY] = LAYOUT_planck_mit(
  KC_ESC,  KC_V,    KC_M,    KC_L,    KC_C,    KC_P,   KC_X,    KC_F,    KC_O,    KC_U,    KC_J,    KC_BSPC,
  TCTLTAB, KC_S,    KC_T,    KC_R,    KC_D,    KC_Y,   KC_DOT,  KC_N,    KC_A,    KC_E,    KC_I,    KC_MINS,
  KC_LSFT, KC_Z,    KC_K,    KC_Q,    KC_G,    KC_W,   KC_B,    KC_H,    KC_QUOT, KC_SCLN, KC_COMM, SC_SENT,
  KC_LCTL, KC_LALT, KC_LGUI, OVERLAY, DEXTER,       KC_SPC,     SINISTR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),
/* Rightward overlay: symbols on both hands, one-shot mods below.
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   +  |   \  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   _  |   {  |   [  |   (  |   <  |   >  |   )  |   ]  |   }  |   ?  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   |  |XXXXXX| Alt  | Ctrl | Del  | Ins  | Ctrl | Alt  |   =  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  |Ovrlay|######|    Space    | Elev | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DEXTER] = LAYOUT_planck_mit(
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_PLUS, KC_BSLS, _______,
  _______, KC_UNDS, KC_LCBR, KC_LBRC, KC_LPRN, KC_LABK, KC_RABK, KC_RPRN, KC_RBRC, KC_RCBR, KC_QUES, KC_MINS,
  _______, KC_PIPE, XXXXXXX, OM_LALT, OM_LCTL, KC_DEL,  KC_INS,  OM_RCTL, OM_LALT, KC_EQL,  KC_SLSH, _______,
  _______, _______, _______, _______, _______,      _______,     ELEVATE, _______, _______, _______, _______
),
/* Leftward overlay: left-hand symbols, right-hand navigation, one-shot mods below.
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  | Home | PgDn |  Up  | PgUp |   /  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   _  |   {  |   [  |   (  |   <  | End  | Left | Down |Right |   ?  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   |  |XXXXXX| Alt  | Ctrl |  ../ | Ins  | Ctrl | Alt  | Del  |   \  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  |Ovrlay| Elev |    Space    |######| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_SINISTER] = LAYOUT_planck_mit(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_HOME, KC_PGDN, KC_UP,   KC_PGUP, KC_SLSH, _______,
  _______, KC_UNDS, KC_LCBR, KC_LBRC, KC_LPRN, KC_LABK, KC_END,  KC_LEFT, KC_DOWN, KC_RGHT, KC_QUES, KC_MINS,
  _______, KC_PIPE, XXXXXXX, OM_LALT, OM_LCTL, UPDIR,   KC_INS,  OM_RCTL, OM_LALT, KC_DEL,  KC_BSLS, _______,
  _______, _______, _______, _______, ELEVATE,      _______,     _______, _______, _______, _______, _______
),
/* Elevated overlay: FN keys, layout selection, linear numbers (mimic top row).
 * ,-----------------------------------------------------------------------------------.
 * | Dvrk |  F1  |  F2  |  F3  |  F4  |PrtSc |   /  |   *  |   .  |   +  |   =  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Clmk |  F5  |  F6  |  F7  |  F8  |ScrLk |   0  |   1  |   2  |   3  |   4  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | QWTY |  F9  | F10  | F11  | F12  |Pause |   5  |   6  |   7  |   8  |   9  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Game |HD Neu|Sturdy|XXXXXX|######|    Space    |######|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
 * `-----------------------------------------------------------------------------------'
 */
[_ELEVATE] = LAYOUT_planck_mit(
  DVORAK,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_PSCR, KC_SLSH, KC_ASTR, KC_DOT,  KC_PLUS, KC_EQL,  _______,
  COLEMAK, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_SCRL, KC_0,    KC_1,    KC_2,    KC_3,    KC_4,    KC_MINS,
  QWERTY,  KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PAUS, KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    _______,
  GAME_ON, HDNEU,   STURDY,  XXXXXXX, _______,      _______,     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
/* General overlay: numeric keypad, extras.
 * ,-----------------------------------------------------------------------------------.
 * |   `  |      |      |      |      |      | Kp/  |   7  |   8  |   9  | Kp-  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |      |      |      |      |      | Kp*  |   4  |   5  |   6  | Kp+  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|      |      |      |      |      | OvLk |   1  |   2  |   3  |KpEnt |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  |######|XXXXXX|    Space    |   0  |XXXXXX|   .  |XXXXXX|XXXXXX|
 * `-----------------------------------------------------------------------------------'
 */
[_OVERLAY] = LAYOUT_planck_mit(
  KC_GRV,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS, KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PAST, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, KC_MINS,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LLOCK,   KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT, _______,
  _______, _______, _______, _______, XXXXXXX,      _______,     KC_KP_0, XXXXXXX, KC_PDOT, XXXXXXX, XXXXXXX
),
/* Gaming layer
 * ,-----------------------------------------------------------------------------------.
 * | Esc  | Tab  |   Q  |   W  |   E  |   R  | MWUp |MWLft |  MUp |MWRght| Acc2 | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   G  |Shift |   A  |   S  |   D  |   F  | MWDn |MLeft |  MDn |MRight| Acc0 |GamOff|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   5  | Ctrl |   Z  |   X  |   C  |   V  |   O  |   1  |   2  |   3  |   4  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |######|   T  |   Y  | Alt  |  RMB |    Space    |  LMB | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_GAMING] = LAYOUT_planck_mit(
  KC_ESC,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, KC_ACL2, _______,
  KC_G,    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_ACL0, GAMETOG,
  KC_5,    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_O,    KC_1,    KC_2,    KC_3,    KC_4,    KC_ENT,
  XXXXXXX, KC_T,    KC_Y,    KC_LALT, KC_BTN2,      KC_SPC,      KC_BTN1, _______, _______, _______, _______
)
};
