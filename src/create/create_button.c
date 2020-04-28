/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Create button
*/

#include "header.h"

button_t *create_button(char **pathname, sfVector2f pos,
void (*callback) (game_manager_t *))
{
    button_t *button = malloc(sizeof(button_t));
    sfVector2u size;

    button->pathname = malloc(sizeof(char *) * 3);
    button->texture = malloc(sizeof(sfTexture *) * 3);
    button->sprite = malloc(sizeof(sfSprite *) * 3);
    for (size_t i = 0; i < 3; i++) {
        button->pathname[i] = pathname[i];
        button->texture[i] = sfTexture_createFromFile(button->pathname[i],
        NULL);
        button->sprite[i] = sfSprite_create();
        sfSprite_setTexture(button->sprite[i], button->texture[i], sfFalse);
    }
    button->pos = pos;
    size = sfTexture_getSize(sfSprite_getTexture(button->sprite[0]));
    button->rect = (sfIntRect){0, 0, size.x, size.y};
    button->state = 0;
    button->callback = callback;
    return button;
}