/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** particles.c
*/

#include "header.h"
#include "particles.h"

static framebuffer *framebuffer_create(int width, int height)
{
    framebuffer *fb = malloc(sizeof(framebuffer));

    fb->width = width;
    fb->height = height;
    fb->pixels = malloc(fb->width * fb->height * 32 / 8);
    return fb;
}

static void set_pixel(framebuffer *fb, int x, int y, sfColor color)
{
    int formula = 4 * fb->width * (y - 1) + 4 * x;

    if (x >= 0 && x < fb->width && y < fb->height && y >= 0) {
        fb->pixels[formula] = color.r;
        fb->pixels[formula + 1] = color.g;
        fb->pixels[formula + 2] = color.b;
        fb->pixels[formula + 3] = color.a;
    }
}

static sfColor pick_random_color_hoven(void)
{
    int r = randomize(0, 255);
    int g = randomize(0, 255);
    int b = randomize(0, 255);
    sfColor color = {r, g, b, 255};
    return color;
}

void draw_hoven_particles(sfVector2f *pos, sfVector2f *size,
sfRenderWindow *win)
{
    framebuffer *fb = framebuffer_create(size->x, size->y);
    sfTexture *texture = sfTexture_create(fb->width, fb->height);
    sfSprite *sprite = sfSprite_create();
    sfColor tmp;

    sfSprite_setTexture(sprite, texture, sfTrue);
    for (int i = 0; i < fb->width; i++) {
        for (int j = 0; j < fb->height; j++) {
            tmp = pick_random_color_hoven();
            set_pixel(fb, i, j, tmp);
        }
    }
    sfTexture_updateFromPixels(texture, fb->pixels,
    fb->width, fb->height, 0, 0);
    sfSprite_setPosition(sprite, *pos);
    sfRenderWindow_drawSprite(win, sprite, NULL);
    sfRenderWindow_display(win);
}