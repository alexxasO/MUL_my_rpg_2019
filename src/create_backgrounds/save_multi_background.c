/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Save Multi Background
*/

#include "header.h"

background_t **save_multi_background(void)
{
    background_t **backgrounds = malloc(sizeof(background_t *) * 2);

    backgrounds[0] = create_background("image/background/save_bg.png",
    (sfVector2f){0, 0}, NULL);
    backgrounds[1] = NULL;
    return backgrounds;
}