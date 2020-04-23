/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** fight.c
*/

#include "header.h"

static void place_player(player_t **players, int nb_players)
{
    int delta_y = 170;
    int offset_y = 20;
    int offset_x = 50;

    for (int i = 0; i < nb_players; i++)
        players[i]->pos = (sfVector2f){offset_x, (delta_y * i) + offset_y};
}

static void place_enemies(enemy_t **enemies, int nb_enemies)
{
    int delta_y = 170;
    int offset_y = 20;
    int offset_x = SCR_WIDTH - 100;

    for (int i = 0; i < nb_enemies; i++)
        enemies[i]->pos = (sfVector2f){offset_x, (delta_y * i) + offset_y};
}

void begin_fight(player_t **players, enemy_t **enemies)
{
    int nb_player = count_players(players);
    int nb_enemy = count_enemies(enemies);
    int turn = 0;

    place_player(players, nb_player);
    place_enemies(enemies, nb_enemy);
    // place_infobar(players, enemies);
}

void fight_func(game_manager_t *gm)
{
    scene_t *scene = gm->scenes[gm->scene_id];

    gm->player_list = scene->players;
    gm->enemy_list = scene->enemies;
    begin_fight(gm->player_list, gm->enemy_list);
}