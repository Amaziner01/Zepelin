#include "Zepelin.h"

#include <stdio.h>

#include "point.h"
#include "triangle.h"
#include "cmath.h"

static statemachine_t __global_state_machine;
#define FB __global_state_machine._bound_framebuffer
#define SF __global_state_machine._bound_surface

void bind_framebuffer(colour_t *fb) {
    FB = fb;
}

void bind_surface(surface_t *fb) {
    SF = fb;
}

void refresh(void) {
    if (FB != NULL && SF != NULL) {
        blit_to_surface(SF, FB);
    }
}

embedded void clear_colour(colour_t c) {
    if (FB != NULL && SF != NULL) {
        for (int i = 0; i < SF->width * SF->height; ++i) {
            FB[i] = c;
        }
    }
}

embedded void plot_pixel(int x, int y, colour_t c) {
	if (FB != NULL && SF != NULL) {
        if ( x > -1 && x < SF->width && y < SF->height && y > -1) {
            FB[x + (y * SF->width)] = c;
        }
    }
}

embedded void plot_line(int x1, int y1, colour_t c1, int x2, int y2, colour_t c2) {
	if (FB != NULL && SF != NULL) {
        int dx = x2 - x1;
        int dy = y2 - y1;
        register int i;

        float slope, scarry;
        int inc, a;

        if (abs(dx) > abs(dy)) {
            inc = dx < 0 ? -1 : 1;
            a = x1;
            slope = (float)dy / dx;
            scarry = y1;

            for (i = 0; i <= abs(dx); ++i) {
                plot_pixel(a, (int)scarry, colour(
                            lerp(c1.r, c2.r, (float)i / abs(dx)),
                            lerp(c1.g, c2.g, (float)i / abs(dx)),
                            lerp(c1.b, c2.b, (float)i / abs(dx))
                            )
                        );
                a += inc;
                scarry += slope;
            }
        }
        else {
            inc = dy < 0 ? -1 : 1;
            a = y1;
            slope = (float)dx / dy;
            scarry = x1;

            for (i = 0; i <= abs(dy); ++i) {
                plot_pixel((int)scarry, a, colour(
                            lerp(c1.r, c2.r, (float)i / abs(dy)),
                            lerp(c1.g, c2.g, (float)i / abs(dy)),
                            lerp(c1.b, c2.b, (float)i / abs(dy))
                            )
                        );
                a += inc;
                scarry += slope;
            }
        }
    }
}

embedded void plot_triangle(int x1, int y1, colour_t c1, 
			  int x2, int y2, colour_t c2,
			  int x3, int y3, colour_t c3
			  ) {

    if (FB != NULL && SF != NULL) {
        triangle_t tri = {
            (point_t){x1, y1, 0, 0, 0, c1},
            (point_t){x2, y2, 0, 0, 0, c2},
            (point_t){x3, y3, 0, 0, 0, c3}
        };

        register size_t i;
        register size_t j;

        point_t pb;
        for (i = 0; i < 3; ++i) {
            for (j = 0; j < 3; ++j) {
                if (tri.p[j].y > tri.p[i].y) {
                    pb = tri.p[i];
                    tri.p[i] = tri.p[j];
                    tri.p[j] = pb;
                }
            }
        }

        int dy1 = tri.p2.y - tri.p1.y;
        int dy2 = tri.p3.y - tri.p1.y;

        float s1 = (float)(tri.p2.x - tri.p1.x) / dy1;
        float s2 = (float)(tri.p3.x - tri.p1.x) / dy2;

        float sc1 = tri.p1.x;
        float sc2 = tri.p1.x;

        point_t p[2] = { tri.p1, tri.p2 };

        for (i = 0; i < abs(dy1); ++i) {
            p[0] = (point_t){
                .x = sc1,
                .y = i + tri.p1.y,
                .c = colour(
                lerp(tri.p1.c.r, tri.p2.c.r, (float)i / abs(dy1)),
                lerp(tri.p1.c.g, tri.p2.c.g, (float)i / abs(dy1)),
                lerp(tri.p1.c.b, tri.p2.c.b, (float)i / abs(dy1))
                )
            };

            p[1] = (point_t){
                .x = sc2,
                .y = i + tri.p1.y,
                .c = colour(
                lerp(tri.p1.c.r, tri.p3.c.r, (float)i / abs(dy2)),
                lerp(tri.p1.c.g, tri.p3.c.g, (float)i / abs(dy2)),
                lerp(tri.p1.c.b, tri.p3.c.b, (float)i / abs(dy2))
                )
            };

            if (p[0].x > p[1].x) {
                pb = p[0];
                p[0] = p[1];
                p[1] = pb;
            }

            int dp = p[0].x - p[1].x;

            for (j = 0; j < abs(dp); ++j) {
                plot_pixel(
                    p[0].x + j, p[0].y, colour(
                    lerp(p[0].c.r, p[1].c.r, (float)j / abs(dp)),
                    lerp(p[0].c.g, p[1].c.g, (float)j / abs(dp)),
                    lerp(p[0].c.b, p[1].c.b, (float)j / abs(dp))
                    )
                );
            }
            sc1 += s1;
            sc2 += s2;
        }

        if (s1 == s2) return;

        sc1 = tri.p2.x;
        s1 = (float)(tri.p3.x - tri.p2.x) / (tri.p3.y - tri.p2.y);
        int dy3 = tri.p3.y - tri.p2.y;

        int d = 0;
        for (i; i < abs(dy2); ++i) {

            p[0] = (point_t){
                .x = sc1,
                .y = i + tri.p1.y,
                .c = colour(
                lerp(tri.p2.c.r, tri.p3.c.r, (float)d / abs(dy3)),
                lerp(tri.p2.c.g, tri.p3.c.g, (float)d / abs(dy3)),
                lerp(tri.p2.c.b, tri.p3.c.b, (float)d / abs(dy3))
                )
            };

            p[1] = (point_t){
                .x = sc2,
                .y = i + tri.p1.y,
                .c = colour(
                lerp(tri.p1.c.r, tri.p3.c.r, (float)i / abs(dy2)),
                lerp(tri.p1.c.g, tri.p3.c.g, (float)i / abs(dy2)),
                lerp(tri.p1.c.b, tri.p3.c.b, (float)i / abs(dy2))
                )
            };

            if (p[0].x > p[1].x) {
                pb = p[0];
                p[0] = p[1];
                p[1] = pb;
            }

            int dp = p[0].x - p[1].x;

            for (j = 0; j < abs(dp); ++j) {
                plot_pixel(
                    p[0].x + j, p[0].y, colour(
                    lerp(p[0].c.r, p[1].c.r, (float)j / abs(dp)),
                    lerp(p[0].c.g, p[1].c.g, (float)j / abs(dp)),
                    lerp(p[0].c.b, p[1].c.b, (float)j / abs(dp))
                    )
                );
            }

            sc1 += s1;
            sc2 += s2;
            ++d;
        }
    }
}

void plot_triangle_texture(
    int x1, int y1, float u1, float v1,
    int x2, int y2, float u2, float v2,
    int x3, int y3, float u3, float v3,
	texture_t *t
    ) {

    if (FB != NULL && SF != NULL) {
        triangle_t tri = {
            (point_t){x1, y1, 0, u1, v1, 0},
            (point_t){x2, y2, 0, u2, v2, 0},
            (point_t){x3, y3, 0, u3, v3, 0}
        };

        register size_t i;
        register size_t j;

        point_t pb;
        for (i = 0; i < 3; ++i) {
            for (j = 0; j < 3; ++j) {
                if (tri.p[j].y > tri.p[i].y) {
                    pb = tri.p[i];
                    tri.p[i] = tri.p[j];
                    tri.p[j] = pb;
                }
            }
        }

        int dy1 = tri.p2.y - tri.p1.y;
        int dy2 = tri.p3.y - tri.p1.y;

        float s1 = (float)(tri.p2.x - tri.p1.x) / dy1;
        float s2 = (float)(tri.p3.x - tri.p1.x) / dy2;

        float sc1 = tri.p1.x;
        float sc2 = tri.p1.x;

        int u, v;

        point_t p[2] = { tri.p1, tri.p2 };

        colour_t *pix = (colour_t *)t->pixels;

        for (i = 0; i < abs(dy1); ++i) {
            p[0] = (point_t){
                .x = sc1,
                .y = i + tri.p1.y,
                .u = lerp(tri.p1.u, tri.p2.u, (float)i/abs(dy1)) * t->w,
                .v = lerp(tri.p1.v, tri.p2.v, (float)i/abs(dy1)) * t->h
            };

            p[1] = (point_t){
                .x = sc2,
                .y = i + tri.p1.y,
                .u = lerp(tri.p1.u, tri.p3.u, (float)i/abs(dy2)) * t->w,
                .v = lerp(tri.p1.v, tri.p3.v, (float)i/abs(dy2)) * t->h
            };

            if (p[0].x > p[1].x) {
                pb = p[0];
                p[0] = p[1];
                p[1] = pb;
            }

            int dp = p[0].x - p[1].x;

            for (j = 0; j < abs(dp); ++j) {
                u = (int)lerp(p[0].u, p[1].u, (float)j/abs(dp));
                v = (int)lerp(p[0].v, p[1].v, (float)j/abs(dp));

                plot_pixel(
                    p[0].x + j, p[0].y, pix[u + (v * t->h)]
                );
            }
            sc1 += s1;
            sc2 += s2;
        }

        if (s1 == s2) return;

        sc1 = tri.p2.x;
        s1 = (float)(tri.p3.x - tri.p2.x) / (tri.p3.y - tri.p2.y);
        int dy3 = tri.p3.y - tri.p2.y;

        int d = 0;
        for (i; i < abs(dy2); ++i) {

            p[0] = (point_t){
                .x = sc1,
                .y = i + tri.p1.y,
                .u = lerp(tri.p2.u, tri.p3.u, (float)d/abs(dy3)) * t->w,
                .v = lerp(tri.p2.v, tri.p3.v, (float)d/abs(dy3)) * t->h
            };

            p[1] = (point_t){
                .x = sc2,
                .y = i + tri.p1.y,
                .u = lerp(tri.p1.u, tri.p3.u, (float)i/abs(dy2)) * t->w,
                .v = lerp(tri.p1.v, tri.p3.v, (float)i/abs(dy2)) * t->h
            };

            if (p[0].x > p[1].x) {
                pb = p[0];
                p[0] = p[1];
                p[1] = pb;
            }

            int dp = p[0].x - p[1].x;

            for (j = 0; j < abs(dp); ++j) {
                u = (int)lerp(p[0].u, p[1].u, (float)j/abs(dp));
                v = (int)lerp(p[0].v, p[1].v, (float)j/abs(dp));

                plot_pixel(
                    p[0].x + j, p[0].y, pix[u + (v * t->w)]
                );
            }

            sc1 += s1;
            sc2 += s2;
            ++d;
        }
    }
}
