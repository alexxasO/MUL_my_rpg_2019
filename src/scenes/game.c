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

    anim_player(gm, scene->players[0]);
    move_player_and_background(gm, scene->players[0], scene->backgrounds[0]);
    handle_buttons(gm, scene);
}