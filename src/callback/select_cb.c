/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Select callback
*/

#include "header.h"

static void replace_button(scene_t *scene, size_t item_id)
{
    destroy_button(scene->buttons[item_id]);
    add_select_button(item_id, scene);
}

static int count_select(save_t *save)
{
    int select = 0;

    for (size_t i = 0; i < 12; i++) {
        if (save->inventory[i] == 2)
            select++;
    }
    return select;
}

void select_callback(game_manager_t *gm)
{
    save_t *save = gm->saves[gm->save_id];
    scene_t *scene = gm->scenes[gm->scene_id];
    scene_t *game_scene = gm->scenes[GAME_ID];

    for (size_t i = 0; i < 12; i++) {
        if (save->inventory[i] == 3 && count_select(save) < 3) {
            update_stat(i, game_scene->players, 1);
            save->inventory[i] = 2;
            replace_button(scene, i);
            break;
        } else if (save->inventory[i] == 3) {
            save->inventory[i] = 1;
            break;
        }
    }
}
