#include "input.h"
#include <windows.h>

static char _keys[256];

void get_keyboard_state(void) {
    GetKeyboardState(_keys);
}

bool is_key_pressed(key_index_t key){
    return _keys[key] & 0x80;
}