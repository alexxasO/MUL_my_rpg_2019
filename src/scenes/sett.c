/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Sett Scene
*/

#include "header.h"

void sett_func(game_manager_t *gm)
{
    scene_t *scene = gm->scenes[gm->scene_id];
    char *volume_str = NULL;

    handle_buttons(gm, scene);
    if (my_strcmp(gm->key_pressed, "down") == 0 &&
    gm->volume > 0)
        gm->volume -= 1;
    if (my_strcmp(gm->key_pressed, "up") == 0 &&
    gm->volume < 100)
        gm->volume += 1;
    volume_str = my_put_nbr_in_str(gm->volume);
    free(scene->texts[0]->string);
    scene->texts[0]->string = volume_str;
}