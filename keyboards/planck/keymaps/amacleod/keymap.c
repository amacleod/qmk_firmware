#include QMK_KEYBOARD_H


enum planck_layers {
  _DVORAK,
  _COLEMAK,
  _QWERTY,
  _DEXTER,
  _SINISTER,
  _ELEVATE,
  _SYMBOLS,
  _GAMING
};


#define DVORAK  TO(0)
#define COLEMAK TO(1)
#define QWERTY  TO(2)
#define DEXTER  MO(3)
#define SINISTR MO(4)
#define ELEVATE MO(5)
#define SYMBOLS OSL(6)
#define GAME_ON TO(7)
#define GAMETOG TG(7)

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
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_LALT OSM(MOD_LALT)
#define OSM_LGUI OSM(MOD_LGUI)
#define OSM_LSFT OSM(MOD_LSFT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | Elev | Sym  | Dext |Sinist|Space | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_planck_grid(
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,   KC_F,    KC_G,   KC_C,    KC_R,    KC_L,  KC_BSPC,
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,   KC_D,    KC_H,   KC_T,    KC_N,    KC_S,  KC_MINS,
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,   KC_B,    KC_M,   KC_W,    KC_V,    KC_Z,  SC_SENT,
  KC_LCTL, KC_LALT, KC_LGUI, ELEVATE, SYMBOLS, DEXTER, SINISTR, KC_SPC, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
),
/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | Elev | Sym  | Dext |Sinist|Space | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
  KC_TRNS, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_TRNS,
  KC_TRNS, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_TRNS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | Elev | Sym  | Dext |Sinist|Space | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
  KC_TRNS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_TRNS,
  KC_TRNS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_TRNS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
/* Rightward overlay: numeric keypad
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |   .  |      |      |   /  |   7  |   8  |   9  |  Kp- |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | GUI  | Alt  | Ctrl | Shift|      |   *  |   4  |   5  |   6  |  Kp+ |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   1  |   2  |   3  |Enter |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Elev |   0  |      |   .  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_DEXTER] = LAYOUT_planck_grid(
  KC_TRNS, KC_NO,    KC_NO,    KC_PDOT,  KC_NO,    KC_NO,   KC_PSLS, KC_P7, KC_P8, KC_P9,   KC_PMNS, KC_TRNS,
  KC_TRNS, OSM_LGUI, OSM_LALT, OSM_LCTL, OSM_LSFT, KC_NO,   KC_PAST, KC_P4, KC_P5, KC_P6,   KC_PPLS, KC_MINS,
  KC_TRNS, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_P1, KC_P2, KC_P3,   KC_PENT, KC_TRNS,
  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, ELEVATE, KC_P0, KC_NO, KC_PDOT, KC_TRNS, KC_TRNS
),
/* Leftward overlay: navigation and numbers
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  | PgDn |  Up  | PgUp |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |   &  | Left | Down |Right |   ?  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   0  |   9  |   8  |   7  |   6  |   *  |   (  |   )  |   [  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | Elev |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SINISTER] = LAYOUT_planck_grid(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_PGDN, KC_UP,   KC_PGUP, KC_SLSH, KC_TRNS,
  KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_AMPR, KC_LEFT, KC_DOWN, KC_RGHT, KC_QUES, KC_TRNS,
  KC_TRNS, KC_0,    KC_9,    KC_8,    KC_7,    KC_6,    KC_ASTR, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, ELEVATE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
/* Elevated overlay: FN keys, layout selection, secondary navigation
 * ,-----------------------------------------------------------------------------------.
 * | Dvrk |  F1  |  F2  |  F3  |  F4  | Ins  | PgUp |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Clmk |  F5  |  F6  |  F7  |  F8  | Del  | PgDn |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | QWTY |  F9  | F10  | F11  | F12  | Home | End  |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Reset |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ELEVATE] = LAYOUT_planck_grid(
  DVORAK,  KC_F1, KC_F2,  KC_F3,   KC_F4,   KC_INS,  KC_PGUP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  COLEMAK, KC_F5, KC_F6,  KC_F7,   KC_F8,   KC_DEL,  KC_PGDN, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  QWERTY,  KC_F9, KC_F10, KC_F11,  KC_F12,  KC_HOME, KC_END,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  QK_BOOT, KC_NO, KC_NO,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
),
/* Symbol overlay: punctuation etc.
 * ,-----------------------------------------------------------------------------------.
 * |   `  |      |      |      |   *  |   !  |   $  |   |  |   -  |   =  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |   _  |   (  |   )  |   @  |   %  |   {  |   }  |   /  |   ?  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |   <  |   >  |   #  |   ^  |   [  |   ]  |   \  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Game |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOLS] = LAYOUT_planck_grid(
  KC_GRV,  KC_NO,   KC_NO,   KC_NO,   KC_ASTR, KC_EXLM, KC_DLR,  KC_PIPE, KC_MINS, KC_EQL,  KC_SLSH, KC_TRNS,
  KC_TRNS, KC_NO,   KC_UNDS, KC_LPRN, KC_RPRN, KC_AT,   KC_PERC, KC_LCBR, KC_RCBR, KC_SLSH, KC_QUES, KC_TRNS,
  KC_TRNS, KC_NO,   KC_NO,   KC_LT,   KC_GT,   KC_HASH, KC_CIRC, KC_LBRC, KC_RBRC, KC_BSLS, KC_NO,   KC_TRNS,
  GAME_ON, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
/* Gaming layer
 * ,-----------------------------------------------------------------------------------.
 * | Esc  | Tab  |   Q  |   W  |   E  |   R  | MWUp |MWLft |  MUp |MWRght| Acc2 | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   G  |Shift |   A  |   S  |   D  |   F  | MWDn |MLeft |  MDn |MRight| Acc0 |GamOff|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   5  | Ctrl |   Z  |   X  |   C  |   V  |   O  |   1  |   2  |   3  |   4  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   T  |   Y  | Alt  |Space |  RMB |  MMB |  LMB |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_GAMING] = LAYOUT_planck_grid(
  KC_ESC,  KC_TAB,  KC_Q, KC_W,    KC_E,   KC_R,    KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, KC_ACL2, KC_TRNS,
  KC_G,    KC_LSFT, KC_A, KC_S,    KC_D,   KC_F,    KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_ACL0, GAMETOG,
  KC_5,    KC_LCTL, KC_Z, KC_X,    KC_C,   KC_V,    KC_O,    KC_1,    KC_2,    KC_3,    KC_4,    KC_ENT,
  KC_NO,   KC_T,    KC_Y, KC_LALT, KC_SPC, KC_BTN2, KC_BTN3, KC_BTN1, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)
};
