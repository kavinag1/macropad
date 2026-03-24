#include QMK_KEYBOARD_H
#include <stdio.h>

enum layer_names {
    _BASE,
};

static char last_action[17] = "Boot";

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        C(KC_S),   C(KC_F),   C(KC_SLSH),   C(KC_Z),   C(S(KC_B))
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (record->event.key.col) {
            case 0:
                snprintf(last_action, sizeof(last_action), "Save");
                break;
            case 1:
                snprintf(last_action, sizeof(last_action), "Find");
                break;
            case 2:
                snprintf(last_action, sizeof(last_action), "Comment");
                break;
            case 3:
                snprintf(last_action, sizeof(last_action), "Undo");
                break;
            case 4:
                snprintf(last_action, sizeof(last_action), "Build");
                break;
            default:
                snprintf(last_action, sizeof(last_action), "Key");
                break;
        }
    }

    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code16(C(KC_PGDN));
            snprintf(last_action, sizeof(last_action), "Next Tab");
        } else {
            tap_code16(C(KC_PGUP));
            snprintf(last_action, sizeof(last_action), "Prev Tab");
        }
    }

    return false;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_0;
}

bool oled_task_user(void) {
    oled_clear();
    oled_write_ln_P(PSTR("xiao_macropad"), false);
    oled_write_ln_P(PSTR("Layer: BASE"), false);
    oled_write_P(PSTR("Last: "), false);
    oled_write_ln(last_action, false);
    oled_write_ln_P(PSTR("Enc: Tabs/Build"), false);
    return false;
}
#endif
