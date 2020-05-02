/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Inventory and Status Background
*/

#include "header.h"

background_t **inventory_and_status_background(void)
{
    background_t **backgrounds = malloc(sizeof(background_t *) * 2);

    backgrounds[0] = create_background("image/background/inv_n_stat_bg.png",
    (sfVector2f){0, -32}, NULL);
    backgrounds[1] = NULL;
    return backgrounds;
}