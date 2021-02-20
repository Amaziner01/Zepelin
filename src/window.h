#ifndef WINDOW
#define WINDOW

#define NOMINMAX
#include <windows.h>

void window_init(int width, int height, const char* title);
void window_terminate(void);
void window_poll_message(void);

HWND get_window_handle(void);
BOOL is_window_running(void);


#endif
