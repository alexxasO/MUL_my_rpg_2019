/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Create background
*/

#include "header.h"

background_t *create_background(char *pathname, sfVector2f pos,
void (*ptr_move) (struct background_s *, sfVector2f))
{
    background_t *background = malloc(sizeof(background_t));
    sfVector2u size;

    background->pathname = pathname;
    background->texture = sfTexture_createFromFile(background->pathname, NULL);
    background->sprite = sfSprite_create();
    sfSprite_setTexture(background->sprite, background->texture, sfFalse);
    background->pos = pos;
    size = sfTexture_getSize(sfSprite_getTexture(background->sprite));
    background->rect = (sfIntRect){0, 0, size.x, size.y};
    background->clock = sfClock_create();
    background->ptr_move = ptr_move;
    return background;
}