/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Create button
*/

#include "header.h"

button_t *create_button(char *pathname, sfVector2f pos,
void (*callback) (game_manager_t *))
{
    button_t *button = malloc(sizeof(button_t));
    sfVector2u size;

    button->pathname = pathname;
    button->texture = sfTexture_createFromFile(button->pathname, NULL);
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    button->pos = pos;
    size = sfTexture_getSize(sfSprite_getTexture(button->sprite));
    button->rect = (sfIntRect){0, 0, size.x, size.y};
    button->is_clicked = sfFalse;
    return button;
}