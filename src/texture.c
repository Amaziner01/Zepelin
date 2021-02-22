#include "texture.h"
#include <stdio.h>
#include <stdlib.h>

texture_t *load_texture(const char *namepath) {
	texture_t *t = malloc(sizeof(texture_t)); 

	FILE *f = fopen(namepath, "rb");
	if (!f) {
		printf("File \"%s\" not found.", namepath);
		return NULL;
	}

	fread(&t->w, 4, 1, f);
	fread(&t->h, 4, 1, f);

	t->pixels = malloc(t->w * t->h * 9);
	fread(t->pixels, t->w * t->h * 9, 1, f);
	
	fclose(f);

	return t;
}

void free_texture(texture_t *t) {
	free(t->pixels);
	free(t);
}
