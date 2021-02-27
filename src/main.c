#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <process.h>
#include <math.h>

#include "window.h"
#include "Zepelin.h"

#include "vec4.h"

#define WIDTH 1000
#define HEIGHT 1000

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

	float *depth = malloc(WIDTH * HEIGHT * sizeof(float));
	bind_depthbuffer(depth);


	vec4_t v[] = {
		{-0.5,  0.5,  0.5, 0.0}, //0
        { 0.5,  0.5,  0.5, 0.0}, //1
        { 0.5, -0.5,  0.5, 0.0}, //2
        {-0.5, -0.5,  0.5, 0.0}, //3
        {-0.5,  0.5, -0.5, 0.0}, //4
        { 0.5,  0.5, -0.5, 0.0}, //5
        { 0.5, -0.5, -0.5, 0.0}, //6 
        {-0.5, -0.5, -0.5, 0.0} //7
	};

	int indices[] = {
        // front
        0, 1, 2,
        2, 3, 0,
        // back
        4, 5, 6,
        6, 7, 4,
        // right
        1, 5, 6,
        6, 2, 1,
        // left
        0, 3, 7,
        7, 4, 0,
        // bot
        3, 2, 6,
        6, 7, 3,
        // top
        0, 1, 5,
        5, 4, 0
    };

	vec4_t transformed[8];



	vec4_t pos = { 0, 0, 500, 0};

	vec4_t scl = { 50, -50, 50, 0};

	float deg = 0.0;
	float deg2 = 0.0;

	texture_t *tex = load_texture("res/lowbrick.bin");

	// TODO: KNN

	clock_t last, act;
	last = clock();
	float dt = 0.0;
	while (is_window_running()) {

		get_keyboard_state();

		if (is_key_pressed(key_o)) deg += 0.5 * dt;
		if (is_key_pressed(key_p)) deg -= 0.5 * dt;
		if (is_key_pressed(key_u)) deg2 += 0.5 * dt;
		if (is_key_pressed(key_i)) deg2 -= 0.5 * dt;
		if (is_key_pressed(key_d)) pos.x += 100 * dt;
		if (is_key_pressed(key_a)) pos.x -= 100 * dt;
		if (is_key_pressed(key_w)) pos.y -= 100 * dt;
		if (is_key_pressed(key_s)) pos.y += 100 * dt;
		if (is_key_pressed(key_e)) pos.z += 100 * dt;
		if (is_key_pressed(key_q)) pos.z -= 100 * dt;

		mat4_t rot = {
			sin(-deg), cos(-deg), 0.0, 0.0,
		    cos(-deg),-sin(-deg), 0.0, 0.0,
			0.0, 0.0, 1.0, 0.0,
			0.0, 0.0, 0.0, 0.0
		};

		mat4_t rot2 = {
			sin(-deg), 0.0, cos(-deg), 0.0,
		    0.0, 	   1.0, 0.0, 	   0.0,
			cos(-deg), 0.0, -sin(-deg), 0.0,
			0.0, 0.0, 0.0, 0.0
		};

		for (int i = 0; i < 8; ++i) {
			transformed[i] = vec4_add(vec4_mul_mat4(vec4_mul_mat4(vec4_mul(v[i],scl),rot), rot2),pos);
			transformed[i].x = transformed[i].x / (transformed[i].z * 0.001) + (WIDTH / 2) + 1;
			transformed[i].y = transformed[i].y / (transformed[i].z * 0.001) + (HEIGHT / 2) + 1;
		}

		clear_colour(colour(40, 180, 255));
		clear_depth();

		for (int i = 0; i < 6; ++i) {
			plot_triangle_texture(
				transformed[indices[i * 6]].x, transformed[indices[i * 6]].y, transformed[indices[i * 6]].z, 0.0, 0.0,
				transformed[indices[i * 6 + 1]].x, transformed[indices[i * 6 + 1]].y, transformed[indices[i * 6 + 1]].z, 0.0, 1.0,
				transformed[indices[i * 6 + 2]].x, transformed[indices[i * 6 + 2]].y, transformed[indices[i * 6 + 2]].z, 1.0, 1.0,
				tex
			);

			plot_triangle_texture(
				transformed[indices[i * 6 + 3]].x, transformed[indices[i * 6 + 3]].y, transformed[indices[i * 6 + 3]].z, 1.0, 1.0,
				transformed[indices[i * 6 + 4]].x, transformed[indices[i * 6 + 4]].y, transformed[indices[i * 6 + 4]].z, 1.0, 0.0,
				transformed[indices[i * 6 + 5]].x, transformed[indices[i * 6 + 5]].y, transformed[indices[i * 6 + 5]].z, 0.0, 0.0,
				tex
			);
		}

		/*
		plot_triangle_texture(
			transformed[2].x, transformed[2].y, 0.0, 0.0,
			transformed[3].x, transformed[3].y, 0.0, 1.0,
			transformed[0].x, transformed[0].y, 1.0, 1.0,
			tex
		);

		plot_triangle_texture(
			transformed[4].x, transformed[4].y, 1.0, 1.0,
			transformed[5].x, transformed[5].y, 1.0, 0.0,
			transformed[6].x, transformed[6].y, 0.0, 0.0,
			tex
		);

		plot_triangle_texture(
			transformed[6].x, transformed[6].y, 0.0, 0.0,
			transformed[7].x, transformed[7].y, 0.0, 1.0,
			transformed[4].x, transformed[4].y, 1.0, 1.0,
			tex
		);

		plot_triangle_texture(
			transformed[2].x, transformed[2].y, 0.0, 0.0,
			transformed[3].x, transformed[3].y, 0.0, 1.0,
			transformed[6].x, transformed[6].y, 1.0, 1.0,
			tex
		);

		plot_triangle_texture(
			transformed[6].x, transformed[6].y, 1.0, 1.0,
			transformed[7].x, transformed[7].y, 1.0, 0.0,
			transformed[2].x, transformed[2].y, 0.0, 0.0,
			tex
		);
		*/

		/*
		for (int i = 0; i < 4; ++i) {
			if (is_key_pressed(0x01)) {
				if (dst(p.x, p.y, transformed[i].x, transformed[i].y) < 20) {
					transformed[i].x = p.x;
					transformed[i].y = p.y;
				}
			}
		}
		*/

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
	free(depth);
	free(pixels);
	puts("Exiting");
	return 0;
}
