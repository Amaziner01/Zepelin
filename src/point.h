#ifndef POINT_H
#define POINT_H

#include "colour.h"

typedef struct point_t {
	int x, y;
	float z;
	float u, v;
	colour_t c;
} point_t;

#define point(x, y, z, u, v, c) (color)

#endif