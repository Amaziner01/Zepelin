#ifndef CMATH_H
#define CMATH_H

#include <math.h>

#define abs(a) ((a > -1) ? a : -a)

#if defined(__MINGW64__)
    #define max(a, b) ((a > b) ? a : b)
    #define min(a, b) ((a < b) ? a : b)
#endif

#define lerp(a, b, t) (a + (t * (b - a)))

#define sqr(a) ((a)*(a))

#define dst(x1, y1, x2, y2) (sqrt(sqr(x2 - x1) + sqr(y2 - y1)))

#endif