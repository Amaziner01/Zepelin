#ifndef TEXTURE_H
#define TEXTURE_H

typedef struct texture_t {
	int w, h;
	int dw, dh;
	void *pixels;
} texture_t;

texture_t *load_texture(const char *namepath);
void free_texture(texture_t *t);

#endif


