#ifndef ZEPELIN_H
#define ZEPELIN_H

#define NOMINMAX

#include "surface.h"
#include "statemachine.h"

#include "input.h"

#include "colour.h"
#include "texture.h"

#include "vec4.h"
#include "mat4.h"
#include "cmath.h"

/* Bind */
void bind_surface(surface_t *sf);
void bind_framebuffer(colour_t *fb);
void bind_depthbuffer(float *db);

/* Draw */
void refresh(void);
void clear_colour(colour_t c);
void clear_depth(void);

void plot_pixel(int x, int y, float z, colour_t c);
void plot_line(int x1, int y1, colour_t c1, int x2, int y2, colour_t c2);
void plot_triangle(
    int x1, int y1, float z1, colour_t c1, 
    int x2, int y2, float z2, colour_t c2,
    int x3, int y3, float z3, colour_t c3
    );
void plot_triangle_texture(
    int x1, int y1, float z1, float u1, float v1,
    int x2, int y2, float z2, float u2, float v2,
    int x3, int y3, float z3, float u3, float v3,
	texture_t *t
    );

#endif
