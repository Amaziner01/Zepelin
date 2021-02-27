#include "vec4.h"


inline vec4_t vec4_add(vec4_t v1, vec4_t v2) {
    return (vec4_t) {
        .v = _mm_add_ps(v1.v, v2.v)
    };
}

inline vec4_t vec4_sub(vec4_t v1, vec4_t v2) {
    return (vec4_t) {
        .v = _mm_sub_ps(v1.v, v2.v)
    };
}

inline vec4_t vec4_mul(vec4_t v1, vec4_t v2) {
    return (vec4_t) {
        .v = _mm_mul_ps(v1.v, v2.v)
    };
}

inline vec4_t vec4_mul_mat4(vec4_t v, mat4_t m) {
    return (vec4_t) {
        (v.x*m.m[0]) + (v.y*m.m[1]) + (v.z*m.m[2]) + (v.w*m.m[3]),
        (v.x*m.m[4]) + (v.y*m.m[5]) + (v.z*m.m[6]) + (v.w*m.m[7]),
        (v.x*m.m[8]) + (v.y*m.m[9]) + (v.z*m.m[10]) + (v.w*m.m[11]),
        (v.x*m.m[12]) + (v.y*m.m[13]) + (v.z*m.m[14]) + (v.w*m.m[15])
    };
}