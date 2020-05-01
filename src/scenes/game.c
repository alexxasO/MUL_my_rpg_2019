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
    move_all(gm, scene->players, scene->backgrounds[0]);
    handle_buttons(gm, scene);
    if (my_strcmp(gm->key_pressed, "esc") == 0)
        gm->scene_id = PAUSE_ID;
    if (my_strcmp(gm->key_pressed, "i") == 0)
        gm->scene_id = INV_STAT_ID;
}