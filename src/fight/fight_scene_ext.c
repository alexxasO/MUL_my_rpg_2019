/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** fight_scene.c
*/

#include "header.h"

void place_player(player_t **players, int nb_players)
{
    int delta_y = 170;
    int offset_y = 20;
    int offset_x = 50;

    for (int i = 0; i < nb_players; i++)
        players[i]->pos = (sfVector2f){offset_x, (delta_y * i) + offset_y};
}

void place_enemies(enemy_t **enemies, int nb_enemies)
{
    int delta_y = 170;
    int offset_y = 20;
    int offset_x = SCR_WIDTH - 100;

    for (int i = 0; i < nb_enemies; i++)
        enemies[i]->pos = (sfVector2f){offset_x, (delta_y * i) + offset_y};
}

void place_infobar_texts(player_t **players, enemy_t **enemies,
game_manager_t *gm)
{
    place_info_ply(players, gm);
    place_info_enemies(enemies, gm);
}