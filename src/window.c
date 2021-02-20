#include "window.h"
#include <time.h>

static clock_t last, act;
static HWND window_handle;
static BOOL running;

static LRESULT win_proc(HWND win, UINT msg, WPARAM wparam, LPARAM lparam) {
	switch (msg) {
		case WM_CLOSE:
		case WM_DESTROY:
			PostQuitMessage(0);

		default:
			return DefWindowProcA(win, msg, wparam, lparam);
	}

	return 0;
}

void window_init(int width, int height, const char* title) {
	WNDCLASSA wclass = {0};
	wclass.lpszClassName = "WinCoolClass";
	wclass.lpfnWndProc = win_proc;
	wclass.hInstance = GetModuleHandle(NULL);
	wclass.hCursor = LoadCursor(NULL, IDC_ARROW);

	RegisterClassA(&wclass);

	window_handle = CreateWindowExA(
			0,
			wclass.lpszClassName,
			title,
			WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			width, height,
			NULL, NULL, NULL, NULL
			);

	ShowWindow(window_handle, SW_SHOW);
	UpdateWindow(window_handle);

	running = TRUE;
}

void window_terminate(void) {
	DestroyWindow(window_handle);
}

static MSG msg;
void window_poll_message(void) {

	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
		TranslateMessage(&msg);
		DispatchMessageA(&msg);

		if (msg.message == WM_QUIT) {
			running = FALSE;
		}
	}
}

HWND get_window_handle(void) {
	return window_handle;
}

BOOL is_window_running(void) {
	return running;
}
