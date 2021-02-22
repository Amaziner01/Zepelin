#ifndef MAT4_H
#define MAT4_H

#include <immintrin.h>

typedef struct mat4_t {
    union {
        float m[16];
        struct {__m128 r1, r2, r3, r4;};
    };
} mat4_t;

#define mat4_identity(x)((mat4_t){\
x, 0, 0, 0,\
0, x, 0, 0,\
0, 0, x, 0,\
0, 0, 0, x,\
})

#endif