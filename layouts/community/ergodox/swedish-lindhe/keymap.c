/* Copyright 2017 Andreas Lindhé
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "config.h"
#include "debug.h"
#include "action_layer.h"
#include "keymap_swedish.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define NUMP 3 // numpad (numlock disabled)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-----------------------------------------------------.       ,-----------------------------------------------------.
 * | Print     |   !  |  "   |  #   |  #   |  %   |      |       |Middle|   &  |  /   |  (   |  )   |  =   |  ?        |
 * | Screen    |   1  |  2 @ |  3 £ |  4 $ |  5   | F11  |       |Mouse |   6  |  7 { |  8 [ |  9 ] |  0 } |  + \      |
 * |-----------+------+------+------+------+-------------|       |------+------+------+------+------+------+-----------|
 * | Tab       | Q    | W    | E    | R    | T    | ~L1  |       |  L3  | Y    | U    | I    | O    | P    | Å         |
 * |-----------+------+------+------+------+------|      |       |      |------+------+------+------+------+-----------|
 * | CapsLk    | A    | S    | D    | F    | G    |------|       |------| H    | J    | K    | L    | Ö    | Ä         |
 * |-----------+------+------+------+------+------| ` '  |       | Del  |------+------+------+------+------+-----------|
 * | LShft     | Z    | X    | C    | V    | B    | (~L3)|       |      | N    | M    | ,    | .    | -    | RShift (')|
 * `-----------+------+------+------+------+-------------'       `-------------+------+------+------+------+-----------'
 *   | LCtl    |  ^   | *    | LAlt | LGui |                                   | AltGr| Down |  Up  | Left | Right|
 *   |         |  " ~ | '  ´ |      |      |                                   |      |      |      |      |      |
 *   `-------------------------------------'                                   `----------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        | LCtl | LAlt |       | Home |   End  |
 *                                 ,------|------|------|       |------+-------+------.
 *                                 |      |      |  ~   |       | PgUp |       |      |
 *                                 | Space|Back- |------|       |------|  Tab  |Enter |
 *                                 |      |space | Enter|       | PgDn |       | L2   |
 *                                 `--------------------'       `---------------------'
 */

[BASE] = LAYOUT_ergodox(  // layer 0 : default
    // left hand
    KC_PSCR,         KC_1,     KC_2,     KC_3,    KC_4,    KC_5,   KC_F11,
    KC_TAB,          KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,   TT(SYMB),
    KC_CAPS,         KC_A,     KC_S,     KC_D,    KC_F,    KC_G,
    KC_LSFT,         KC_Z,     KC_X,     KC_C,    KC_V,    KC_B,   LT(NUMP,NO_ACUT),
    KC_LCTRL,        NO_CIRC,  NO_ASTR,  KC_LALT, KC_LGUI,
                                               KC_LCTRL,  KC_LALT,
                                                          NO_TILD,
                                         KC_SPC, KC_BSPC, KC_ENT,
    // right hand
         KC_MS_BTN3, KC_6,   KC_7,    KC_8,    KC_9,    KC_0,     NO_PLUS,
         TG(NUMP),   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,     NO_AA,
                     KC_H,   KC_J,    KC_K,    KC_L,    NO_OSLH,  NO_AE,
           KC_DELT,  KC_N,   KC_M,    KC_COMM, KC_DOT,  NO_MINS,  RSFT_T(NO_APOS),
                            NO_ALGR, KC_DOWN, KC_UP,   KC_LEFT,  KC_RGHT,
         KC_HOME,        KC_END,
         KC_PGUP,
         KC_PGDN, KC_TAB, LT(MDIA, KC_ENT)
),

/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |  /   |   *  |  -   |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |           |      |      |  7   |  8   |  9   |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |------|           |------|      |  4   |  5   |  6   |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F9  |  F10 |  F11 |  F12 |      |      |           |      |      |  1   |  2   |  3   | Enter|        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |  0   | ,    | .    | Enter|      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      | Sleep|       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_TRNS, KC_TRNS,
       KC_TRNS, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_TRNS,
       KC_TRNS, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_SLEP,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_PSLS, KC_PAST, KC_PMNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_7,    KC_8,    KC_9,    KC_PPLS, KC_TRNS,
                KC_TRNS, KC_4,    KC_5,    KC_6,    KC_PPLS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_1,    KC_2,    KC_3,    KC_PENT, KC_TRNS,
                         KC_0,    KC_COMM, KC_DOT,  KC_PENT, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |ScrlUp|      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|ScrlDn|------|           |------|      | Play | Pause| Prev | Next |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      | Lclk | Rclk |      |      |           |      |      |VolDn |VolUp | Mute |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |LeClk |RiClk |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_WH_U, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_BTN1, KC_BTN2, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_MPLY, KC_MPLY, KC_MPRV, KC_MNXT, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |  /   |   *  |  -   |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  7   |  8   |  9   |  +   |        |
 * |        |      |      |      |      |      |      |           |      |      | Home | Up   | PgUp |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |  4   |  5   |  6   |  +   |        |
 * |        |      |      |      |      |      |------|           |------|      |Left  |      | Right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  1   |  2   |  3   | Enter|        |
 * |        |      |      |      |      |      |      |           |      |      | End  | Down | PgUp |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |  0   | ,    | .    | Enter|      |
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
[NUMP] = LAYOUT_ergodox(
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_PSLS, KC_PAST, KC_PMNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS, KC_TRNS,
                KC_TRNS, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT, KC_TRNS,
                         KC_KP_0, KC_COMM, KC_DOT,  KC_PENT, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
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
            ergodox_right_led_3_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

    if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
        // if capslk is on, set led 1 on
        ergodox_right_led_1_on();
    } else {
        ergodox_right_led_1_off();
    }

};
