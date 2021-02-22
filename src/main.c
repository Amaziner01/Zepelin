#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <process.h>
#include <math.h>

#include "window.h"
#include "Zepelin.h"

#define WIDTH 1000
#define HEIGHT 1000

char keys[256];

int main(void) {
	window_init(WIDTH, HEIGHT, "Cool");

	surface_descriptor_t desc = {0};
	desc.win_handle = get_window_handle();
	desc.bpp = sizeof(colour_t) * 8;
	desc.width = WIDTH;
	desc.height = HEIGHT;
	
	surface_t *sf = init_surface(&desc);
	bind_surface(sf);

	colour_t *pixels = malloc(WIDTH * HEIGHT * sizeof(colour_t));
	bind_framebuffer(pixels);

	vec4_t v[] = {
		{ 0.5,  0.5,  0.0,  0.0},
		{-0.5,  0.5,  0.0,  0.0},
		{-0.5, -0.5,  0.0,  0.0}
	};

	vec4_t v2[] = {
		{-0.5, -0.5,  0.0,  0.0},
		{ 0.5, -0.5,  0.0,  0.0},
		{ 0.5,  0.5,  0.0,  0.0}
	};

	vec4_t transformed[3];
	vec4_t transformed2[3];

	vec4_t pos = { 500, 450, 0, 0};

	vec4_t scl = { 200, -200, 0, 0};

	float deg = 0.0;


	texture_t *tex = load_texture("lowbrick.bin");

	// TODO: KNN

	clock_t last, act;
	last = clock();
	float dt;
	while (is_window_running()) {
		deg += 0.5 * dt;

		get_keyboard_state();

		if (is_key_pressed(key_d)) pos.x += 100 * dt;
		if (is_key_pressed(key_a)) pos.x -= 100 * dt;
		if (is_key_pressed(key_w)) pos.y -= 100 * dt;
		if (is_key_pressed(key_s)) pos.y += 100 * dt;

		mat4_t rot = {
			sin(-deg), cos(-deg), 0.0, 0.0,
		    cos(-deg),-sin(-deg), 0.0, 0.0,
			0.0, 0.0, 1.0, 0.0,
			0.0, 0.0, 0.0, 0.0
		};


		clear_colour(colour(40, 180, 255));

		
		colour_t *tc = (colour_t*)tex->pixels;
		for (int j = 0; j < tex->h; ++j) {
			for (int i = 0; i < tex->w; ++i) {
				plot_pixel(i, j, tc[i + (j * tex->w)]);
			}
		}

		for (int i = 0; i < 3; ++i) {
			transformed[i] = vec4_add(vec4_mul_mat4(vec4_mul(v[i],scl),rot),pos);
		}
		for (int i = 0; i < 3; ++i) {
			transformed2[i] = vec4_add(vec4_mul_mat4(vec4_mul(v2[i],scl),rot),pos);
		}

		plot_triangle_texture(
			transformed[0].x, transformed[0].y, 1.0, 1.0,
			transformed[1].x, transformed[1].y, 1.0, 0.0,
			transformed[2].x, transformed[2].y, 0.0, 0.0,
			tex
		);

		
		plot_triangle_texture(
			transformed2[0].x, transformed2[0].y, 0.0, 0.0,
			transformed2[1].x, transformed2[1].y, 0.0, 1.0,
			transformed2[2].x, transformed2[2].y, 1.0, 1.0,
			tex
		);
		
		

		refresh();

		window_poll_message();

		char msg[25];
		sprintf(msg, "FPS: %f", 1.0 / dt);
		RECT r = {0, 0, 200, 100};
		SetBkMode(sf->dc, TRANSPARENT);
		SetBkColor(sf->dc, RGB(255, 255, 255));
		DrawTextA(sf->dc, msg, strlen(msg), &r, DT_BOTTOM);

		act = clock();
		dt = (act - last) * 0.001;
		last = act;
	}

	free_texture(tex);
	terminate_surface(sf);
	window_terminate();
	free(pixels);
	puts("Exiting");
	return 0;
}
