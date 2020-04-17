/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Start Menu Scene
*/

#include "header.h"

void start_menu_func(game_manager_t *gm)
{
    scene_t *scene = gm->scenes[gm->scene_id];

    for (size_t i = 0; scene->buttons[i]; i++) {
        if (gm->is_mouse_clicked == sfTrue
        && is_mouse_over_button(gm, scene->buttons[i]))
            scene->buttons[i]->state = 2;
        else if (gm->is_mouse_clicked == sfFalse
        && is_mouse_over_button(gm, scene->buttons[i]))
            scene->buttons[i]->state = 1;
        else
            scene->buttons[i]->state = 0;
    }
}