#ifndef INPUT_H
#define INPUT_H

#include <stdbool.h>

typedef enum key_index_t {
    key_a = 0x41,
    key_d = 0x44,
    key_e = 0x45,
    key_s = 0x53,
    key_w = 0x57,
    key_q = 0x51,
    key_p = 0x50,
    key_o = 0x4F,
    key_u = 0x55,
    key_i = 0x49,
} key_index_t;

void get_keyboard_state(void);
bool is_key_pressed(key_index_t key);

#endif