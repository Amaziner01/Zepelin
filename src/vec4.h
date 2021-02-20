#ifndef VEC4_H
#define VEC4_H

#include <immintrin.h>
#include "mat4.h"

typedef struct vec4_t {
    union {
        struct {float x, y, z, w;};
        __m128 v;
    };
} vec4_t;

#define vec4(x, y, z, w) ((vec4_t){x, y, z, w})

vec4_t vec4_add(vec4_t v1, vec4_t v2);
vec4_t vec4_sub(vec4_t v1, vec4_t v2);
vec4_t vec4_mul(vec4_t v1, vec4_t v2);
vec4_t vec4_mul_mat4(vec4_t v1, mat4_t v2);

#endif