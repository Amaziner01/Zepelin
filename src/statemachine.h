#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "colour.h"

typedef struct statemachine_t {
    surface_t *_bound_surface;
    colour_t *_bound_framebuffer;
    float *_bound_depthbuffer;
} statemachine_t;

#endif