/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** Handle the music
*/

#include "header.h"

static void stop_all_music(game_manager_t *gm)
{
    scene_t *scene = NULL;

    for (size_t i = 0; i < NB_SCENES; i++) {
        scene = gm->scenes[i];
        if (sfMusic_getStatus(scene->music) != sfStopped)
            sfMusic_stop(scene->music);
    }
}

void handle_music(game_manager_t *gm)
{
    static int first = 1;
    static char *music_pathname = NULL;
    scene_t *scene = gm->scenes[gm->scene_id];

    if (first == 1) {
        music_pathname = scene->music_pathname;
        sfMusic_play(scene->music);
        first = 0;
    } else if (my_strcmp(music_pathname, scene->music_pathname) != 0) {
        stop_all_music(gm);
        music_pathname = scene->music_pathname;
        sfMusic_play(scene->music);
    }
}
