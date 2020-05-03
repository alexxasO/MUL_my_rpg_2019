/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** Fight Player
*/

#include "header.h"

// static void create_fighter_info(player_t *player) // just for tests
// {
//     attack_t *attacka = malloc(sizeof(attack_t) * 1);
//     attack_t *attackb = malloc(sizeof(attack_t) * 1);
//     attack_t *attackc = malloc(sizeof(attack_t) * 1);
//     attack_t *attackd = malloc(sizeof(attack_t) * 1);
//     attack_t **attacks = malloc(sizeof(attack_t *) * 5);

//     attacks[0] = malloc(sizeof(attack_t));
//     attacks[1] = malloc(sizeof(attack_t));
//     attacks[2] = malloc(sizeof(attack_t));
//     attacks[3] = malloc(sizeof(attack_t));
//     attacks[0]->name ="testa";
//     attacks[1]->name ="testb";
//     attacks[2]->name ="testc";
//     attacks[3]->name ="testd";
//     player->fighter_info->attacks = attacks;
// }

player_t **fight_player(void)
{
    player_t **players = malloc(sizeof(player_t *) * 1);

    players[0] = NULL;
    return players;
}