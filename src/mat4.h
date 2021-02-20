#ifndef MAT4_H
#define MAT4_H

#include <immintrin.h>

typedef struct mat4_t {
    union {
        float m[16];
        struct {__m128 r1, r2, r3, r4;};
    };
} mat4_t;

#endif