#ifndef CMATH_H
#define CMATH_H

#define abs(a) ((a > -1) ? a : -a)
#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)
#define lerp(a, b, t) (a + (t * (b - a)))

#endif