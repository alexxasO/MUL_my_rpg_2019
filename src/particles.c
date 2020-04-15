/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** particles.c
*/

#include "header.h"

static sfColor pick_random_color_hoven() {
    int r = randomize(0, 255);
    int g = 0;
    int b = 0;
    sfColor color = {r, g, b, 255};
    return color;
}

//TODO function to draw particles just like the hoven shown by kyllian
void draw_hoven_particles(sfVector2f *pos, sfVector2f size)
{

}