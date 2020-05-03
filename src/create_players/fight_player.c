/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** Fight Player
*/

#include "header.h"

player_t **fight_player(void)
{
    player_t **players = malloc(sizeof(player_t *) * 5);

    players[0] = NULL;
    players[1] = NULL;
    players[2] = NULL;
    players[3] = NULL;
    players[4] = NULL;
    return players;
}