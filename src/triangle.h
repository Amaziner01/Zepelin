#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "point.h"

typedef struct triangle_t {
	union {
		struct {
			point_t p1;
			point_t p2;
			point_t p3;
		};
		point_t p[3];
	};
} triangle_t;

#endif