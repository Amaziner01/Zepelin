#include "surface.h"
#include <stdlib.h>
#include <windows.h>

surface_t *init_surface(surface_descriptor_t *desc) {
    surface_t *sf = malloc(sizeof(surface_t));
    sf->dc = GetDC(desc->win_handle);
    sf->m_dc = CreateCompatibleDC(sf->dc);
    sf->bmp = CreateCompatibleBitmap(sf->dc, desc->width, desc->height);
	SelectObject(sf->m_dc, sf->bmp);

    sf->bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	sf->bi.bmiHeader.biPlanes = 1;
	sf->bi.bmiHeader.biBitCount = desc->bpp;

	sf->bi.bmiHeader.biCompression = BI_RGB;
    sf->bi.bmiHeader.biWidth = desc->width;
	sf->bi.bmiHeader.biHeight = -desc->height;

    sf->width = desc->width;
	sf->height = desc->height;

    return sf;
}

void blit_to_surface(surface_t *sf, void *buffer) {
    SetDIBits(NULL, sf->bmp, 0, sf->height, buffer, &sf->bi, DIB_RGB_COLORS);
	BitBlt(sf->dc, 0, 0, sf->width, sf->height, sf->m_dc, 0, 0, SRCCOPY);
}

void terminate_surface(surface_t *sf) {
    DeleteObject(sf->bmp);
    DeleteDC(sf->m_dc);
    ReleaseDC(NULL, sf->dc);

    free(sf);
    sf = NULL;
}