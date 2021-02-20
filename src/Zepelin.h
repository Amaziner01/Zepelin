#ifndef ZEPELIN_H
#define ZEPELIN_H

#define NOMINMAX

#include "surface.h"
#include "statemachine.h"

#include "colour.h"

#include "vec4.h"
#include "mat4.h"

/* Bind */
void bind_surface(surface_t *sf);
void bind_framebuffer(colour_t *fb);

#define embedded _inline __attribute__((__always_inline__))

/* Draw */
void refresh(void);
void clear_colour(colour_t c);
void plot_pixel(int x, int y, colour_t c);
void plot_line(int x1, int y1, colour_t c1, int x2, int y2, colour_t c2);
void plot_triangle(
    int x1, int y1, colour_t c1, 
    int x2, int y2, colour_t c2,
    int x3, int y3, colour_t c3
    );

#endif