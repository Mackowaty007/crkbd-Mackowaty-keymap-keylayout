#include QMK_KEYBOARD_H

enum custom_keycodes {
    CABT = SAFE_RANGE,
    RICKROLL,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case CABT:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("https://www.youtube.com/watch?v=fR9ClX0egTc");
        } else {
            // when keycode QMKBEST is released
        }
        break;

    case RICKROLL:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("https://www.youtube.com/watch?v=dQw4w9WgXcQ");
        } else {
            // when keycode QMKBEST is released
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x6_3(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, LSFT_T(KC_CAPS), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, MO(6), KC_LALT, LT(1,KC_SPC), KC_LGUI, MO(2), LT(5,KC_ENT), LT(3,KC_BSPC)),
	[1] = LAYOUT_split_3x6_3(KC_ESC, KC_TILD, KC_NO, KC_LT, KC_GT, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL, KC_BSLS, KC_LSFT, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_QUOT, KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ASTR, KC_SLSH, KC_LT, KC_GT, KC_SLSH, KC_NO, KC_LALT, KC_TRNS, KC_LGUI, KC_RSFT, KC_NO, KC_NO),
	[2] = LAYOUT_split_3x6_3(KC_TAB, KC_F1, KC_F2, KC_F3, KC_F4, KC_NO, KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_NO, KC_LSFT, KC_F5, KC_F6, KC_F7, KC_F8, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO, KC_LCTL, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LALT, KC_SPC, KC_LGUI, KC_TRNS, KC_NO, KC_NO),
	[3] = LAYOUT_split_3x6_3(KC_TAB, KC_NO, KC_PSCR, KC_SLCK, KC_PAUS, KC_NO, KC_BTN4, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3, KC_NO, KC_LSFT, KC_NO, KC_INS, KC_HOME, KC_PGUP, KC_NO, KC_BTN5, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_NO, KC_LCTL, KC_NO, KC_DEL, KC_END, KC_PGDN, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_BRID, KC_BRIU, KC_NO, MO(4), KC_NO, KC_LGUI, KC_NO, KC_NO, KC_TRNS),
	[4] = LAYOUT_split_3x6_3(KC_TAB, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BTN4, KC_BTN1, KC_WH_U, KC_BTN2, KC_BTN3, KC_NO, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BTN5, KC_WH_L, KC_WH_D, KC_WH_R, KC_NO, KC_NO, KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_LGUI, KC_NO, KC_NO, KC_NO),
	[5] = LAYOUT_split_3x6_3(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LSFT, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_RSFT, KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_APP, KC_RCTL, KC_LALT, KC_NO, KC_LGUI, KC_NO, KC_TRNS, KC_NO),
	[6] = LAYOUT_split_3x6_3(KC_TAB, CABT, RICKROLL, KC_NO, KC_NO, KC_NO, KC_NLCK, KC_P7, KC_P8, KC_P9, KC_PMNS, KC_NO, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PSLS, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_NO, KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PAST, KC_P1, KC_P2, KC_P3, KC_PENT, KC_TRNS, KC_LALT, KC_NO, KC_LGUI, KC_PEQL, KC_PDOT, KC_P0)
};

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_left()) {
        return OLED_ROTATION_180;
    } else {
        return OLED_ROTATION_0;
    }
}

void render_mod_status(uint8_t modifiers) {
    oled_write(" ", false);
    oled_write_P(PSTR("/--\\"), (modifiers & MOD_MASK_SHIFT));
    oled_write(" ", false);
    oled_write_P(PSTR("/--\\"), (modifiers & MOD_MASK_CTRL));
    oled_write(" ", false);
    oled_write_P(PSTR("/--\\"), (modifiers & MOD_MASK_ALT));
    oled_write(" ", false);
    oled_write_P(PSTR("/--\\"), (modifiers & MOD_MASK_GUI));
    oled_write(" ", false);

    oled_write(" ", false);
    oled_write_P(PSTR("SHIT"), (modifiers & MOD_MASK_SHIFT));
    oled_write(" ", false);
    oled_write_P(PSTR("CONT"), (modifiers & MOD_MASK_CTRL));
    oled_write(" ", false);
    oled_write_P(PSTR("ALTR"), (modifiers & MOD_MASK_ALT));
    oled_write(" ", false);
    oled_write_P(PSTR("SUPR"), (modifiers & MOD_MASK_GUI));
    oled_write(" ", false);

    oled_write(" ", false);
    oled_write_P(PSTR("\\--/"), (modifiers & MOD_MASK_SHIFT));
    oled_write(" ", false);
    oled_write_P(PSTR("\\--/"), (modifiers & MOD_MASK_CTRL));
    oled_write(" ", false);
    oled_write_P(PSTR("\\--/"), (modifiers & MOD_MASK_ALT));
    oled_write(" ", false);
    oled_write_P(PSTR("\\--/"), (modifiers & MOD_MASK_GUI));
    oled_write(" ", false);
    oled_write("RED - BLU - FRTY - TU", false);
}

static void renderSlave(void) {
    render_mod_status(get_mods());
}

void renderMaster(void) {
    oled_write_P(PSTR("/----\\"), host_keyboard_leds() & (1 << USB_LED_NUM_LOCK));
    oled_write(" ", false);
    oled_write_P(PSTR("/----\\"), host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK));
    oled_write(" ", false);
    oled_write_P(PSTR("/----\\"), host_keyboard_leds() & (1 << USB_LED_SCROLL_LOCK));
    oled_write(" ", false);
    oled_write_P(PSTR("NUMLCK"), host_keyboard_leds() & (1 << USB_LED_NUM_LOCK));
    oled_write(" ", false);
    oled_write_P(PSTR("CAPSLK"), host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK));
    oled_write(" ", false);
    oled_write_P(PSTR("SCRLCK"), host_keyboard_leds() & (1 << USB_LED_SCROLL_LOCK));
    oled_write(" ", false);
    oled_write_P(PSTR("\\----/"), host_keyboard_leds() & (1 << USB_LED_NUM_LOCK));
    oled_write(" ", false);
    oled_write_P(PSTR("\\----/"), host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK));
    oled_write(" ", false);
    oled_write_P(PSTR("\\----/"), host_keyboard_leds() & (1 << USB_LED_SCROLL_LOCK));
    oled_write(" Klawiatura Mateusza", false);
}



bool oled_task_user(void) {
    if (is_keyboard_left()) {
        renderSlave();
    } else {
        renderMaster();
    }
    return false;
}

#endif

