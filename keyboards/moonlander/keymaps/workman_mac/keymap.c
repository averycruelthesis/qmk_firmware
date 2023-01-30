/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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
#include "version.h"

#define LT_BSPC_SYM  LT(_SYMBOLS,  KC_BSPC)
#define LT_SPC_NN    LT(_NAVNUM, KC_SPC)

enum layers {
  _WORKMAN,  // default layer
  _NAVNUM,
  _SYMBOLS,
};

enum custom_keycodes {
  LOCK = SAFE_RANGE,
  NEW_TAB,
  CTAGS_NEXT
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_WORKMAN] = LAYOUT_moonlander(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐────────┐        ┌────────┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NO,            KC_NO,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_KB_VOLUME_UP,
  //├────────┼────────┼────────┼────────┼────────┼────────┤────────┐        ┌────────├────────┼────────┼────────┼────────┼────────┼────────┤
     LOCK,    KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    KC_NO,            KC_NO,   KC_J,    KC_F,    KC_U,    KC_P,    KC_EXLM, KC_KB_VOLUME_DOWN,
  //├────────┼────────┼────────┼────────┼────────┼────────┤────────┐        ┌────────├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_A,    KC_S,    KC_H,    KC_T,    KC_G,    KC_NO,            KC_NO,   KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_RSFT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┘        └───────┼────────┼────────┼────────┼────────┼────────┼────────┤ 
     KC_NO,   KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,                               KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_QUES, KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_TAB,           KC_ENT,           KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    LT_SPC_NN, KC_LCMD, KC_LCTL,                 KC_ROPT, KC_RCMD, LT_BSPC_SYM
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  
  [_NAVNUM] = LAYOUT_moonlander(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐────────┐        ┌────────┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NO,            KC_NO,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BRIU,
  //├────────┼────────┼────────┼────────┼────────┼────────┤────────┐        ┌────────├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, KC_NO,   KC_P7,   KC_P8,   KC_P9,   KC_NO,   KC_NO,            KC_NO,   NEW_TAB, KC_G,    KC_AMPR, KC_0,    KC_NO,   KC_BRID,
  //├────────┼────────┼────────┼────────┼────────┼────────┤────────┐        ┌────────├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, KC_NO,   KC_P4,   KC_P5,   KC_P6,   KC_0,    KC_NO,            KC_NO, CTAGS_NEXT,KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┘        └────────┼────────┼────────┼────────┼────────┼────────┼────────┤ 
     KC_NO,   KC_NO,   KC_P1,   KC_P2,   KC_P3,   KC_X,                               KC_EQL,  KC_PAST, KC_MINS, KC_PPLS, KC_SLSH, KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_TRNS,          KC_TRNS,          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SYMBOLS] = LAYOUT_moonlander(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐────────┐        ┌────────┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO,            KC_NO,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤────────┐        ┌────────├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, KC_COLN, KC_AMPR, KC_LABK, KC_RABK, KC_PERC, KC_NO,            KC_NO,   KC_TILD, KC_LCBR, KC_RCBR, KC_PIPE, KC_EXLM, KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤────────┐        ┌────────├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, KC_SCLN, KC_DLR,  KC_LPRN, KC_RPRN, KC_QUOT, KC_NO,            KC_NO,   KC_DQT,  KC_LBRC, KC_RBRC, KC_UNDS, KC_BSLS, KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┘        └────────┼────────┼────────┼────────┼────────┼────────┼────────┤ 
     KC_NO,   KC_NO,   KC_CIRC, KC_AT,   KC_HASH, KC_GRV,                             KC_EQL,  KC_PAST, KC_MINS, KC_PPLS, KC_SLSH, KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_TRNS,         KC_TRNS,           KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOCK:
            if (record->event.pressed) {
                register_code(KC_LCMD);
                register_code(KC_LCTL);
                register_code(KC_Q);
            } else{
                unregister_code(KC_LCMD);
                unregister_code(KC_LCTL);
                unregister_code(KC_Q);
            }
            break;
        case NEW_TAB:
            if (record->event.pressed) {
                register_code(KC_LCMD);
                register_code(KC_T);
            } else {
                unregister_code(KC_LCMD);
                unregister_code(KC_T);
            }
            break;
        case CTAGS_NEXT:
            if (record->event.pressed) {
                register_code(KC_LCMD);
                register_code(KC_LBRC);
            } else {
                unregister_code(KC_LCMD);
                unregister_code(KC_LBRC);
            }
            break;
    }
    return true;
}

