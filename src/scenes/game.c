/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Game Scene
*/

#include "header.h"

static sfBool check_collision_with_enemies(game_manager_t *gm)
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
            return sfTrue;
    }
    return sfFalse;
}

void game_func(game_manager_t *gm)
{
    scene_t *scene = gm->scenes[gm->scene_id];

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
    if (check_collision_with_enemies(gm) == sfTrue)
        gm->scene_id = FIGHT_ID;
}