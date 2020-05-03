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
        diff_x = player->pos.x + player->rect.width / 2;
        diff_x -= enemies[i]->pos.x + enemies[i]->rect.width / 2;
        diff_y = player->pos.y + player->rect.height / 2;
        diff_y -= enemies[i]->pos.y + enemies[i]->rect.height / 2;
        if (diff_x < 50 && diff_x > -50 &&
        diff_y < 100 && diff_y > -100)
            return i;
    }
    return -1;
}

static void check_collision_with_npcs(game_manager_t *gm)
{
    player_t *player = gm->scenes[gm->scene_id]->players[0];
    player_t **npcs = gm->scenes[gm->scene_id]->players;
    float diff_x = 0;
    float diff_y = 0;

    for (size_t i = 1; i < 3; i++) {
        if (npcs[i] == NULL)
            continue;
        diff_x = player->pos.x + player->rect.width / 2;
        diff_x -= npcs[i]->pos.x + npcs[i]->rect.width / 2;
        diff_y = player->pos.y + player->rect.height / 2;
        diff_y -= npcs[i]->pos.y + npcs[i]->rect.height / 2;
        if (diff_x < 50 && diff_x > -50 &&
        diff_y < 100 && diff_y > -100) {
            display_dialog(gm, i);
            return;
        }
    }
    erase_dialog(gm);
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
    check_collision_with_npcs(gm);
    enemy_id = check_collision_with_enemies(gm);
    if (enemy_id != -1) {
        gm->scene_id = FIGHT_ID;
        setup_fight(gm, enemy_id);
    }
}