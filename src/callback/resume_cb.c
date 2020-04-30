/*
** EPITECH PROJECT, 2020
** resume_cb.c
** File description:
** resume callback
*/

#include "header.h"

void resume_callback(game_manager_t *gm)
{
    scene_t *scene = gm->scenes[GAME_ID];

    gm->scene_id = GAME_ID;
    get_player_from_save(gm->saves[gm->save_id]->character, scene->players);
}
