// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     *             ┌────────────┐
     *             │ RGB_MOD    │
     * ┌───┬───┬───┼────────────┤
     * │ 7 │ 8 │ 9 │ RGB_TOGGLE │
     * ├───┼───┼───┼────────────┤
     * │ 4 │ 5 │ 6 │ NUM        │
     * ├───┼───┼───┼────────────┤
     * │ 1 │ 2 │ 3 │ 0          │
     * └───┴───┴───┴────────────┘
     */
        [0] = LAYOUT_numpad_4x4(
                             RGB_MOD,
        KC_P7, KC_P8, KC_P9, RGB_TOG,
        KC_P4, KC_P5, KC_P6, KC_NUM,
        KC_P1, KC_P2, KC_P3, KC_P0
    )
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(RGB_SPD, RGB_SPI)},
};
#endif

#ifdef OLED_ENABLE

const char *rgb_matrix_effect_names[] = {
    "None",                             // RGB_MATRIX_NONE
    "Solid Color",                      // RGB_MATRIX_SOLID_COLOR - Static single hue, no speed support
    "Alphas Mods",                      // RGB_MATRIX_ALPHAS_MODS - Static dual hue, speed is hue for secondary hue
    "Gradient Up/Down",                 // RGB_MATRIX_GRADIENT_UP_DOWN - Static gradient top to bottom, speed controls how much gradient changes
    "Gradient Left/Right",              // RGB_MATRIX_GRADIENT_LEFT_RIGHT - Static gradient left to right, speed controls how much gradient changes
    "Breathing",                        // RGB_MATRIX_BREATHING - Single hue brightness cycling animation
    "Band Saturation",                  // RGB_MATRIX_BAND_SAT - Single hue band fading saturation scrolling left to right
    "Band Value",                       // RGB_MATRIX_BAND_VAL - Single hue band fading brightness scrolling left to right
    "Band Pinwheel Sat",                // RGB_MATRIX_BAND_PINWHEEL_SAT - Single hue 3 blade spinning pinwheel fades saturation
    "Band Pinwheel Val",                // RGB_MATRIX_BAND_PINWHEEL_VAL - Single hue 3 blade spinning pinwheel fades brightness
    "Band Spiral Sat",                  // RGB_MATRIX_BAND_SPIRAL_SAT - Single hue spinning spiral fades saturation
    "Band Spiral Val",                  // RGB_MATRIX_BAND_SPIRAL_VAL - Single hue spinning spiral fades brightness
    "Cycle All",                        // RGB_MATRIX_CYCLE_ALL - Full keyboard solid hue cycling through full gradient
    "Cycle Left/Right",                 // RGB_MATRIX_CYCLE_LEFT_RIGHT - Full gradient scrolling left to right
    "Cycle Up/Down",                    // RGB_MATRIX_CYCLE_UP_DOWN - Full gradient scrolling top to bottom
    "Cycle Out/In",                     // RGB_MATRIX_CYCLE_OUT_IN - Full gradient scrolling out to in
    "Cycle Out/In Dual",                // RGB_MATRIX_CYCLE_OUT_IN_DUAL - Full dual gradients scrolling out to in
    "Rainbow Chevron",                  // RGB_MATRIX_RAINBOW_MOVING_CHEVRON - Full gradient Chevron-shaped scrolling left to right
    "Cycle Pinwheel",                   // RGB_MATRIX_CYCLE_PINWHEEL - Full gradient spinning pinwheel around center of keyboard
    "Cycle Spiral",                     // RGB_MATRIX_CYCLE_SPIRAL - Full gradient spinning spiral around center of keyboard
    "Dual Beacon",                      // RGB_MATRIX_DUAL_BEACON - Full gradient spinning around center of keyboard
    "Rainbow Beacon",                   // RGB_MATRIX_RAINBOW_BEACON - Full tighter gradient spinning around center of keyboard
    "Rainbow Pinwheels",                // RGB_MATRIX_RAINBOW_PINWHEELS - Full dual gradients spinning two halves of keyboard
    "Flower Blooming",                  // RGB_MATRIX_FLOWER_BLOOMING - Full tighter gradient of first half scrolling left to right and second half scrolling right to left
    "Raindrops",                        // RGB_MATRIX_RAINDROPS - Randomly changes a single key's hue
    "Jellybean Raindrops",              // RGB_MATRIX_JELLYBEAN_RAINDROPS - Randomly changes a single key's hue and saturation
    "Hue Breathing",                    // RGB_MATRIX_HUE_BREATHING - Hue shifts up a slight amount at the same time, then shifts back
    "Hue Pendulum",                     // RGB_MATRIX_HUE_PENDULUM - Hue shifts up a slight amount in a wave to the right, then back to the left
    "Hue Wave",                         // RGB_MATRIX_HUE_WAVE - Hue shifts up a slight amount and then back down in a wave to the right
    "Pixel Fractal",                    // RGB_MATRIX_PIXEL_FRACTAL - Single hue fractal-filled keys pulsing horizontally out to edges
    "Pixel Flow",                       // RGB_MATRIX_PIXEL_FLOW - Pulsing RGB flow along LED wiring with random hues
    "Pixel Rain",                       // RGB_MATRIX_PIXEL_RAIN - Randomly light keys with random hues
    "Typing Heatmap",                   // RGB_MATRIX_TYPING_HEATMAP - How hot is your WPM!
    "Digital Rain",                     // RGB_MATRIX_DIGITAL_RAIN - That famous computer simulation
    "Reactive Simple",                  // RGB_MATRIX_SOLID_REACTIVE_SIMPLE - Pulses keys hit to hue & value then fades value out
    "Reactive",                         // RGB_MATRIX_SOLID_REACTIVE - Static single hue, pulses keys hit to shifted hue then fades to current hue
    "Reactive Wide",                    // RGB_MATRIX_SOLID_REACTIVE_WIDE - Hue & value pulse near a single key hit then fades value out
    "Reactive Multiwide",                   // RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE - Hue & value pulse near multiple key hits then fades value out
    "Reactive Cross",                   // RGB_MATRIX_SOLID_REACTIVE_CROSS - Hue & value pulse the same column and row of a single key hit then fades value out
    "Reactive Multicross",              // RGB_MATRIX_SOLID_REACTIVE_MULTICROSS - Hue & value pulse the same column and row of multiple key hits then fades value out
    "Reactive Nexus",                   // RGB_MATRIX_SOLID_REACTIVE_NEXUS - Hue & value pulse away on the same column and row of a single key hit then fades value out
    "Reactive Multinexus",              // RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS - Hue & value pulse away on the same column and row of multiple key hits then fades value out
    "Splash",                           // RGB_MATRIX_SPLASH - Full gradient & value pulse away from a single key hit then fades value out
    "Multisplash",                      // RGB_MATRIX_MULTISPLASH - Full gradient & value pulse away from multiple key hits then fades value out
    "Solid Splash",                     // RGB_MATRIX_SOLID_SPLASH - Hue & value pulse away from a single key hit then fades value out
    "Solid Multisplash",                // RGB_MATRIX_SOLID_MULTISPLASH - Hue & value pulse away from multiple key hits then fades value out
    "Starlight",                        // RGB_MATRIX_STARLIGHT - LEDs turn on and off at random at varying brightness, maintaining user set color
    "Starlight Dual Hue",               // RGB_MATRIX_STARLIGHT_DUAL_HUE - LEDs turn on and off at random at varying brightness, modifies user set hue by +- 30
    "Starlight Dual Sat",               // RGB_MATRIX_STARLIGHT_DUAL_SAT - LEDs turn on and off at random at varying brightness, modifies user set saturation by +- 30
    "Riverflow",                        // RGB_MATRIX_RIVERFLOW - Modification to breathing animation, offsets animation depending on key location to simulate a river flowing
    "Effect Max"                        // RGB_MATRIX_EFFECT_MAX - Placeholder for max effects*
};

bool oled_task_user(void) {

    oled_write_ln_P(PSTR("Mode: "), false);
    oled_write_ln(rgb_matrix_effect_names[rgb_matrix_get_mode()], false);

    oled_write_ln_P(PSTR("RGB Speed: "), false);
    char speedBuffer[4];
    uint8_t speedPercentage = (uint8_t)(((float)rgb_matrix_get_speed() / 255.0) * 100.0);  // Proper float division
    sprintf(speedBuffer, "%d", speedPercentage);
    oled_write(speedBuffer, false);
    oled_write("%  ", false);
    return false;
}
#endif
