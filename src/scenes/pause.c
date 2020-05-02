/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Pause Scene
*/

#include "header.h"

void pause_func(game_manager_t *gm)
{
    scene_t *scene = gm->scenes[gm->scene_id];

    handle_buttons(gm,scene);
}
