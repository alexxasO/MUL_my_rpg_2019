/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Play multi callback
*/

#include "header.h"

void play_multi_callback(game_manager_t *gm)
{
    gm->scene_id = SAVE_MULTI_ID;
}

void play_multi_id_callback(game_manager_t *gm)
{
    gm->scene_id = MULTI_IP_ID;
}