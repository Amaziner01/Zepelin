#ifndef SURFACE_H
#define SURFACE_H

#include <windows.h>

typedef struct surface_t{
	HDC dc;
	HDC m_dc;
	HBITMAP bmp;
	BITMAPINFO bi;

    int width, height;
} surface_t;

typedef struct surface_descriptor_t{
    HWND win_handle;
    short bpp;
    int width, height;
} surface_descriptor_t;

surface_t *init_surface(surface_descriptor_t *desc);
void blit_to_surface(surface_t *sf, void *pixels);
void terminate_surface(surface_t *sf);

#endif