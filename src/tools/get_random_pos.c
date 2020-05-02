/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Get random pos
*/

#include "header.h"

sfVector2f get_random_pos(void)
{
    sfImage *limit = sfImage_createFromFile("image/other/level_limit.png");
    unsigned int x = random_int(1500) + 500;
    unsigned int y = random_int(2000) + 100;
    sfColor px_color = sfImage_getPixel(limit, x, y);
    sfVector2f pos;

    sfImage_destroy(limit);
    if (px_color.r != sfWhite.r && px_color.g != sfWhite.g &&
    px_color.b != sfWhite.b)
        return (sfVector2f){-1, -1};
    pos.x = x;
    pos.y = y;
    return pos;
}