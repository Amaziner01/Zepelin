#ifndef COLOUR_H
#define COLOUR_H

#include <stdint.h>

typedef struct colour_t{
	uint8_t b; 
	uint8_t g;
	uint8_t r;
} colour_t;

#define colour(r, g, b) (colour_t){ b, g, r}

#endif