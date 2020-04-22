/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Game Scene
*/

#include "header.h"

void game_func(game_manager_t *gm)
{
    scene_t *scene = gm->scenes[gm->scene_id];

    handle_buttons(gm, scene);
    anim_player(gm, scene->players[0]);
    move_player(gm, scene->players[0]);
}