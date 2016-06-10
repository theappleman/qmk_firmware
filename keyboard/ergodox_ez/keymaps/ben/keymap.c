#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "keymap_extras/keymap_uk.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

#define KC_LBRKT LSFT(KC_COMMA)
#define KC_RBRKT LSFT(KC_DOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |  1/! |  2/" |  3/£ |  4/$ |  5/% |  6/^ |           |  7/& |  8/ *|  9/( |  0/) |  -/_ | =/+  | BkSp   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  Y   |           |  L2  |   Y  |   U  |   I  |   O  |   P  | Del    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  | ;/:  | Enter  |
 * |--------+------+------+------+------+------|  L2  |           |  L1  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  | ,/<  |  ./> | //?  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  ~L1 | \/|  | Cmd  | Alt  | Ctrl |                                       |   B  | '/@  | #/~  | Alt  | Ctrl   |
 *   `----------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Home | End  |       | Left | Right|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | PgUp |       | Up   |        |      |
 *                                 | Space| Space|------|       |------|  Bksp  | Space|
 *                                 |      |      | PgDn |       | Down |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,    KC_3,     KC_4,            KC_5,     KC_6,
        KC_TAB,         KC_Q,         KC_W,    KC_E,     KC_R,            KC_T,     KC_Y,
        KC_TAB,         KC_A,         KC_S,    KC_D,     KC_F,            KC_G,
        KC_LSFT,        KC_Z,         KC_X,    KC_C,     KC_V,            KC_B,     TG(MDIA),
        MO(SYMB),       UK_BSLS,      KC_LGUI, KC_LALT,  KC_LCTL,
                                      // Thumb cluster
                                               KC_HOME,  KC_END,
                                                         KC_PGUP,
                                      KC_SPC,  KC_SPC,   KC_PGDN,
        // right hand
        KC_7,           KC_8,         KC_9,    KC_0,     KC_MINS,         KC_EQL,   KC_BSPC,
        TG(MDIA),       KC_Y,         KC_U,    KC_I,     KC_O,            KC_P,     KC_DELT,
                        KC_H,         KC_J,    KC_K,     KC_L,            KC_SCLN,  KC_ENT,
        TG(SYMB),       KC_N,         KC_M,    KC_COMM,  KC_DOT,          KC_SLSH,  KC_RSFT,
                                      KC_B,    KC_QUOTE, UK_HASH,         KC_RALT,  KC_RCTL,
        // Thumb cluster
        KC_LEFT,        KC_RIGHT,
        KC_UP,
        KC_DOWN,        KC_SPC,       KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  `/¬   |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   "  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   /  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   @  |------|           |------| Down |   4  |   5  |   6  |   *  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   -  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |   <  |   >  |                                       |   0  |    . |      |   +  |  =   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_GRV,  KC_F1,    KC_F2,         KC_F3,    KC_F4,     KC_F5,   KC_F6,
       KC_TRNS, KC_EXLM,  UK_QUOT,       KC_LCBR,  KC_RCBR,   UK_PIPE, KC_TRNS,
       KC_TRNS, UK_HASH,  KC_DLR,        KC_LPRN,  KC_RPRN,   UK_AT,
       KC_TRNS, KC_PERC,  KC_CIRC,       KC_LBRC,  KC_RBRC,   UK_TILD, KC_TRNS,
       KC_TRNS, KC_TRNS,  KC_TRNS,       KC_LBRKT, KC_RBRKT,
                                         // Thumb cluster
                                         KC_TRNS,  KC_TRNS,
                                                   KC_TRNS,
                          KC_TRNS,       KC_TRNS,  KC_TRNS,
       // right hand
       KC_F7,   KC_F8,    KC_F9,         KC_F10,   KC_F11,    KC_F12,  KC_TRNS,
       KC_TRNS, KC_UP,    KC_7,          KC_8,     KC_9,      KC_SLSH, KC_TRNS,
                KC_DOWN,  KC_4,          KC_5,     KC_6,      KC_ASTR, KC_TRNS,
       KC_TRNS, KC_AMPR,  KC_1,          KC_2,     KC_3,      KC_MINS, KC_TRNS,
                          KC_0,          KC_DOT,   KC_NO,     KC_PLUS, KC_EQL,
       // Thumb cluster
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS,  KC_TRNS
),
/* Keymap 2: Media keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   ~    |  !   |  @   |  #   |  $   |  %   |      |           |      |  ^   |  &   |  *   |  (   |  )   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |------|           |------|  F6  |  _   |  +   |  {   |  }   |  |     |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F7  |  F8  |  F9  |  F10 |  F11 |      |           |      |  F12 |      |      |      | RESET|        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | Play | Next | Mute | VolDn| VolUp|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA
KEYMAP(
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TILD, KC_EXLM, UK_AT,   UK_HASH,  KC_DLR,  KC_PERC, KC_TRNS,
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,
       KC_TRNS, KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_TRNS,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,
                                  // Thumb cluster
                                            KC_TRNS, KC_TRNS,
                                                     KC_TRNS,
                                  KC_TRNS,  KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
                 KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, UK_PIPE,
       KC_TRNS,  KC_F12,  KC_NO,   KC_NO,   KC_NO,   RESET,   KC_TRNS,
                          KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,
       // Thumb cluster
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
