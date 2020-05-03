/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Return callback
*/

#include "header.h"

void return_callback(game_manager_t *gm)
{
    if (gm->scene_id == PAUSE_ID)
        gm->scene_id = START_MENU_ID;
    if (gm->scene_id == SAVE_ID || gm->scene_id == SAVE_MULTI_ID)
        gm->scene_id = START_MENU_ID;
    if (gm->scene_id == HELP_ID)
        gm->scene_id = PAUSE_ID;
    if (gm->scene_id == SETT_ID)
        gm->scene_id = START_MENU_ID;
}