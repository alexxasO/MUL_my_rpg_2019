/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** Handle buttons
*/

#include "header.h"

void handle_buttons(game_manager_t *gm, scene_t *scene)
{
    for (size_t i = 0; scene->buttons[i]; i++) {
        if (scene->buttons[i]->state == 2 &&
        scene->buttons[i]->callback != NULL)
            scene->buttons[i]->callback(gm);
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