/* Copyright 2020 Hiroyuki Sakoh
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
#include "keymap_jp.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT( \
			KC_ESC ,      KC_F1  ,KC_F2  ,KC_F3  ,  KC_F4  ,KC_F5  ,  KC_MUTE,          KC_F6  ,KC_F7  ,KC_F8  ,  KC_F9  ,KC_F10 ,KC_F11 ,  KC_F12 ,    KC_PSCR,KC_SLCK,                                              \
			JP_ZKHK,JP_1   ,JP_2   ,JP_3   ,JP_4   ,JP_5   ,JP_6   ,                JP_7   ,JP_8   ,JP_9   ,JP_0   ,JP_MINS,JP_CIRC,JP_YEN ,KC_BSPC,    KC_INS ,KC_HOME,KC_PGUP,    KC_NLCK,KC_PSLS,KC_PAST,KC_PMNS,  \
			KC_TAB ,    JP_Q   ,JP_W   ,JP_E   ,JP_R   ,JP_T   ,  KC_BTN3,      JP_Y   ,JP_U   ,JP_I   ,JP_O   ,JP_P   ,JP_AT  ,JP_LBRC,    KC_ENT ,    KC_DEL ,KC_END ,KC_PGDN,    KC_P7  ,KC_P8  ,KC_P9  ,KC_PPLS,  \
			JP_EISU,      JP_A   ,JP_S   ,JP_D   ,JP_F   ,JP_G   ,                JP_H   ,JP_J   ,JP_K   ,JP_L   ,JP_SCLN,JP_COLN,JP_RBRC,                                          KC_P4  ,KC_P5  ,KC_P6  ,          \
			KC_LSFT,        JP_Z   ,JP_X   ,JP_C   ,JP_V   ,JP_B   ,                JP_N   ,JP_M   ,JP_COMM,JP_DOT ,JP_SLSH,JP_BSLS,KC_RSFT,                    KC_UP  ,            KC_P1  ,KC_P2  ,KC_P3  ,KC_PENT,  \
			KC_LCTL,  KC_LWIN,KC_LALT,  JP_MHEN,KC_SPC ,          KC_ENT ,          KC_SPC ,        JP_HENK,  JP_KANA,  KC_RALT,  KC_APP ,KC_RCTL,      KC_LEFT,KC_DOWN,KC_RGHT,    KC_P0          ,KC_PDOT           \
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    //Encoder1
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    //Encoder2
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_WH_U);
        } else {
            tap_code(KC_WH_D);
        }
    //Encoder3
    } else if (index == 2) {
        if (clockwise) {
            tap_code16(C(KC_TAB));
        } else {
            tap_code16(S(C(KC_TAB)));
        }
    }
}
