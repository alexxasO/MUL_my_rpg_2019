/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** Handle buttons
*/

#include "header.h"

static void change_status_of_item(game_manager_t *gm, size_t item_id)
{
    if (gm->scene_id == INV_STAT_ID) {
        if (gm->saves[gm->save_id]->inventory[item_id] == 1)
            gm->saves[gm->save_id]->inventory[item_id] = 3;
        if (gm->saves[gm->save_id]->inventory[item_id] == 2)
            gm->saves[gm->save_id]->inventory[item_id] = 4;
    }
}

void handle_buttons(game_manager_t *gm, scene_t *scene)
{
    for (size_t i = 0; scene->buttons[i]; i++) {
        if (scene->buttons[i]->state == 2 &&
        scene->buttons[i]->callback != NULL) {
            change_status_of_item(gm, i);
            scene->buttons[i]->callback(gm);
        }
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