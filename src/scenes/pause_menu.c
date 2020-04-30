/*
** EPITECH PROJECT, 2020
** pause_menu.c
** File description:
** paus emenu scene
*/

#include "header.h"

void pause_menu_func(game_manager_t *gm)
{
    scene_t *scene = gm->scenes[gm->scene_id];

    handle_buttons(gm,scene);
}
