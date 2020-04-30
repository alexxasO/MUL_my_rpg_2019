/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Destroy button
*/

#include "header.h"

void destroy_button(button_t *button)
{
    for (size_t i = 0; i < 3; i++) {
        sfSprite_destroy(button->sprite[i]);
        sfTexture_destroy(button->texture[i]);
    }
    free(button->pathname);
    free(button->sprite);
    free(button->texture);
    free(button);
}