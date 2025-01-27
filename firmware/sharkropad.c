#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE
#define __ NO_LED
led_config_t g_led_config = { {
  /* Key Matrix to LED Index */
  { __, __, __, __ },
  {  0,  1,  2,  3 },
  {  4,  5,  6,  7 },
  {  8,  9, 10, 11 }
}, {
  /* LED Index to Physical Position */
  { 189,  27 }, { 137,  27 }, { 86,  27 }, { 35,  27 }, 
  { 189,  41 }, { 137,  41 }, { 86,  41 }, { 35,  41 }, 
  { 189,  55 }, { 137,  55 }, { 86,  55 }, { 35,  55 }, 
  { 76,  3 }, { 148, 3}, 
  { 216, 17 }, { 216, 45 }, 
  { 224, 61}, { 60,  61 },
  { 8, 45 }, { 8, 17 }
}, {
  /* LED Index to Flag */
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2
} };
#endif