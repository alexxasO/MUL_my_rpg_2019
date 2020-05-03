/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** fight_scene.c
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

static void place_infobar_texts(player_t **players, enemy_t **enemies,
game_manager_t *gm)
{
    place_info_ply(players, gm);
    place_info_enemies(enemies, gm);
}

static int end_fight(player_t **players, enemy_t **enemies)
{
    int nb_ply = count_players(players);
    int nb_eny = count_enemies(enemies);
    int count = 0;

    for (int i = 0; players[i]; i++) {
        if (players[i]->life <= 0)
            count++;
    }
    if (count >= nb_ply)
        return -1;
    count = 0;
    for (int i = 0; enemies[i]; i++) {
        if (enemies[i]->life <= 0)
            count++;
    }
    if (count >= nb_eny)
        return 1;
    return 0;
}

static void enemy_turn(enemy_t **enemies, player_t **players,
game_manager_t *gm, int nb_ply)
{
    int ply_id = 0;
    int attack_id = 0;
    int attack_nb = 0;

    for (int i = 0; enemies[i]; i++) {
        attack_nb = 0;
        for (; enemies[i]->fighter_info->attacks[attack_nb]; attack_nb++);
        ply_id = random_int(nb_ply);
        attack_id = random_int(attack_nb);
        attack_fighter(enemies[i]->fighter_info, players[ply_id]->fighter_info,
        enemies[i]->fighter_info->attacks[attack_id]);
    }
}

void begin_fight(player_t **players, enemy_t **enemies, game_manager_t *gm)
{
    int nb_player = count_players(players);
    int nb_enemy = count_enemies(enemies);
    int turn = 0;

    place_player(players, nb_player);
    place_enemies(enemies, nb_enemy);
    place_infobar_texts(players, enemies, gm);
    create_info_bar(gm, gm->fight_bar, turn);
    turn++;
    if (turn >= nb_player) {
        turn = 0;
        enemy_turn(enemies, players, gm, nb_player);
    }
}