/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Game Scene
*/

#include "header.h"

static int check_collision_with_enemies(game_manager_t *gm)
{
    player_t *player = gm->scenes[gm->scene_id]->players[0];
    enemy_t **enemies = gm->scenes[gm->scene_id]->enemies;
    float diff_x = 0;
    float diff_y = 0;

    for (size_t i = 0; i < 6; i++) {
        if (enemies[i] == NULL)
            continue;
        diff_x = player->pos.x - enemies[i]->pos.x;
        diff_y = player->pos.y - enemies[i]->pos.y;
        if (diff_x < 50 && diff_x > -50 &&
        diff_y < 100 && diff_y > -100)
            return i;
    }
    return -1;
}

static void setup_for_fight(game_manager_t *gm, int enemy_id)
{
    scene_t *scene = gm->scenes[gm->scene_id];
    char boss_music[] = "music/boss_music.ogg";
    char fight_music[] = "music/fight_music.ogg";
    
    if (enemy_id == 5 && my_strcmp(scene->music_pathname, boss_music) != 0) {
        if (sfMusic_getStatus(scene->music) != sfStopped)
            sfMusic_stop(scene->music);
        sfMusic_destroy(scene->music);
        scene->music = sfMusic_createFromFile(boss_music);
        scene->music_pathname = my_strdup(boss_music);
        sfMusic_setLoop(scene->music, sfTrue);
    } else if (enemy_id == 5 &&
    my_strcmp(scene->music_pathname, fight_music) != 0) {
        if (sfMusic_getStatus(scene->music) != sfStopped)
            sfMusic_stop(scene->music);
        sfMusic_destroy(scene->music);
        scene->music = sfMusic_createFromFile(fight_music);
        scene->music_pathname = my_strdup(fight_music);
        sfMusic_setLoop(scene->music, sfTrue);
    }
}

void game_func(game_manager_t *gm)
{
    scene_t *scene = gm->scenes[gm->scene_id];
    int enemy_id = 0;

    anim_player(gm, scene->players[0]);
    move_all(gm, scene->players, scene->backgrounds[0]);
    handle_buttons(gm, scene);
    if (my_strcmp(gm->key_pressed, "esc") == 0) {
        gm->scene_id = PAUSE_ID;
        return;
    }
    if (my_strcmp(gm->key_pressed, "i") == 0) {
        gm->scene_id = INV_STAT_ID;
        return;
    }
    enemy_id = check_collision_with_enemies(gm);
    if (enemy_id != -1) {
        gm->scene_id = FIGHT_ID;
        setup_for_fight(gm, enemy_id);
    }
}