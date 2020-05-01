/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_infobar.c
*/

#include "header.h"

void create_infobar(game_manager_t *gm)
{
    gm->fight_bar = malloc(sizeof(infobar_t) * 1);
    gm->fight_bar->sprites = NULL;
    gm->fight_bar->texts = NULL;
    gm->fight_bar->mode = DEFAULT;
}