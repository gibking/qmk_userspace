// Copyright 2022 Markus Knutsson (@TweetyDaBird)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_NO, 	
		KC_NO,	KC_NO, 	KC_NO,
		KC_NO,	KC_NO, 	KC_NO
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
};
#endif

enum lighting_keycode {
    L_WHITE = QK_KB_0,  
    L_RED,
    L_YELLOW,
    L_GREEN,
    L_CYAN,
    L_BLUE,
    L_MAGENTA
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
	case L_WHITE:
            if (record->event.pressed) { rgblight_sethsv_noeeprom(HSV_WHITE & rgblight_get_val()); return true; }
        case L_RED:
            if (record->event.pressed) { rgblight_sethsv_noeeprom(HSV_RED & rgblight_get_val()); return true; }
        case L_YELLOW:
            if (record->event.pressed) { rgblight_sethsv_noeeprom(HSV_YELLOW & rgblight_get_val()); return true; }
        case L_GREEN:
            if (record->event.pressed) { rgblight_sethsv_noeeprom(HSV_GREEN & rgblight_get_val()); return true; }
        case L_CYAN:
            if (record->event.pressed) { rgblight_sethsv_noeeprom(HSV_CYAN & rgblight_get_val()); return true; }
        case L_BLUE:
            if (record->event.pressed) { rgblight_sethsv_noeeprom(HSV_BLUE & rgblight_get_val()); return true; }
        case L_MAGENTA:
            if (record->event.pressed) { rgblight_sethsv_noeeprom(HSV_MAGENTA & rgblight_get_val()); return true; }
	default:
    	    return true;

    }
}

