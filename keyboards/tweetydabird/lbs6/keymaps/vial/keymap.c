// Copyright 2022 Markus Knutsson (@TweetyDaBird)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_MPLY,
		TO(1),		KC_MSEL,	RGB_TOG,
		KC_MPRV,	KC_MSTP,	KC_MNXT
    ),
	
	[1] = LAYOUT(
        KC_TRNS, 	
		TO(0),		RGB_HUI, 	RGB_SAI,
		RGB_MOD,	RGB_HUD, 	RGB_SAD
    ),
	
	[2] = LAYOUT(
        KC_TRNS, 	
		KC_TRNS,	KC_TRNS, 	KC_TRNS,
		KC_TRNS,	KC_TRNS, 	KC_TRNS
    ),

    [3] = LAYOUT(
        KC_TRNS, 	
		KC_TRNS,	KC_TRNS, 	KC_TRNS,
		KC_TRNS,	KC_TRNS, 	KC_TRNS
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }
};
#endif

enum lighting_keycode {
    L_WHITE = QK_KB_0,  
    L_RED, 
    L_GREEN,
    L_BLUE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
	case L_WHITE:
            if (record->event.pressed) { rgblight_sethsv_noeeprom(HSV_WHITE); return true; }
        case L_RED:
            if (record->event.pressed) { rgblight_sethsv_noeeprom(HSV_RED); return true; }
        case L_GREEN:
            if (record->event.pressed) { rgblight_sethsv_noeeprom(HSV_GREEN); return true; }
        case L_BLUE:
            if (record->event.pressed) { rgblight_sethsv_noeeprom(HSV_BLUE); return true; }
	default:
    	    return true;

    }
}

