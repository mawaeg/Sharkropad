#include "quantum.h"
#include <ctype.h>
#include <lib/lib8tion/lib8tion.h>
#include <rgb_matrix.h>

#if defined(RGB_MATRIX_EFFECT)
#    undef RGB_MATRIX_EFFECT
#endif // defined(RGB_MATRIX_EFFECT)

#define RGB_MATRIX_EFFECT(x) RGB_MATRIX_EFFECT_##x,
enum {
    RGB_MATRIX_EFFECT_NONE,
#include "rgb_matrix_effects.inc"
#ifdef RGB_MATRIX_CUSTOM_KB
#    include "rgb_matrix_kb.inc"
#endif // RGB_MATRIX_CUSTOM_KB
#ifdef RGB_MATRIX_CUSTOM_USER
#    include "rgb_matrix_user.inc"
#endif // RGB_MATRIX_CUSTOM_USER
#undef RGB_MATRIX_EFFECT
};

#define RGB_MATRIX_EFFECT(x)    \
    case RGB_MATRIX_EFFECT_##x: \
        return #x;
const char *rgb_matrix_name(uint8_t effect) {
    switch (effect) {
        case RGB_MATRIX_EFFECT_NONE:
            return "NONE";
#include "rgb_matrix_effects.inc"
#ifdef RGB_MATRIX_CUSTOM_KB
#    include "rgb_matrix_kb.inc"
#endif // RGB_MATRIX_CUSTOM_KB
#ifdef RGB_MATRIX_CUSTOM_USER
#    include "rgb_matrix_user.inc"
#endif // RGB_MATRIX_CUSTOM_USER
#undef RGB_MATRIX_EFFECT
        default:
            return "UNKNOWN";
    }
}

static uint8_t effect_name_len = 0;

const char *rgb_matrix_get_effect_name(void) {
    static char buf[32] = {0};

    snprintf(buf, sizeof(buf), "%s", rgb_matrix_name(rgb_matrix_get_mode()));
    for (uint8_t i = 1; i < sizeof(buf); ++i) {
        if (buf[i] == 0) {
            effect_name_len = i;
            break;
        } else if (buf[i] == '_')
            buf[i] = ' ';
        else if (buf[i - 1] == ' ')
            buf[i] = toupper(buf[i]);
        else if (buf[i - 1] != ' ')
            buf[i] = tolower(buf[i]);
    }
    return buf;
}

bool oled_task_kb(void) {
    if (!oled_task_user()) { return false; }

    static uint8_t  last_effect = 0;
    static uint8_t  last_speed  = 0;
    static uint16_t key_timer   = 0;
    static uint8_t  start_index = 0;

    uint8_t speedPercentage  = scale8(rgb_matrix_get_speed(), 100);
    bool    is_timer_elapsed = timer_elapsed(key_timer) > 200;

    if (last_effect != rgb_matrix_get_mode() || last_speed != speedPercentage || is_timer_elapsed) {
        last_effect = rgb_matrix_get_mode();
        last_speed  = speedPercentage;

        oled_write_ln_P(PSTR("Mode: "), false);
        const char *name = rgb_matrix_get_effect_name();
        if (effect_name_len > 21) {
            if (!is_timer_elapsed && start_index != 0) {
                start_index -= 1;
            } else {
                key_timer = timer_read();
            }
            if (start_index > effect_name_len) {
                start_index = 0;
            }
            for (uint8_t char_index = 0; char_index < 21; char_index++) {
                if ((start_index + char_index) % effect_name_len == 0 && char_index != 0) {
                    oled_write_char(' ', false);
                } else {
                    oled_write_char(name[(start_index + char_index) % (effect_name_len + 1)], false);
                }
            }
            start_index += 1;
        } else {
            oled_write_ln(name, false);
            start_index = 0;
        }

        oled_set_cursor(0, 2);
        oled_write_ln_P(PSTR("RGB Speed: "), false);
        oled_write(get_u8_str(speedPercentage, ' '), false);
        oled_write("%", false);
    }

    return true;
}
