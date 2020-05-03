/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Multi Scene
*/

#include "header.h"

void multi_func(game_manager_t *gm)
{
    scene_t *scene = gm->scenes[gm->scene_id];

    handle_buttons(gm, scene);
}

void ip_func(game_manager_t *gm)
{
    scene_t *scene = gm->scenes[gm->scene_id];

    handle_buttons(gm, scene);
}

void chat_func(game_manager_t *gm)
{
    scene_t *scene = gm->scenes[gm->scene_id];

    handle_buttons(gm, scene);
}