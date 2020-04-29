/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** fight_background.c
*/

#include "header.h"

background_t **fight_background(void)
{
    background_t **backgrounds = malloc(sizeof(background_t *) * 2);

    backgrounds[0] = create_background("image/background/save_bg.png",
    (sfVector2f){0, 0}, NULL);
    backgrounds[1] = NULL;
    return backgrounds;
}