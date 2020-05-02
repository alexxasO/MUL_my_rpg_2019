/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Unselect callback
*/

#include "header.h"

static void replace_button(scene_t *scene, size_t item_id)
{
    destroy_button(scene->buttons[item_id]);
    add_unselect_button(item_id, scene);
}

void unselect_callback(game_manager_t *gm)
{
    save_t *save = gm->saves[gm->save_id];
    scene_t *scene = gm->scenes[gm->scene_id];
    scene_t *game_scene = gm->scenes[GAME_ID];

    for (size_t i = 0; i < 12; i++) {
        if (save->inventory[i] == 4) {
            update_stat(i, game_scene->players, -1);
            save->inventory[i] = 1;
            replace_button(scene, i);
            break;
        }
    }
}
