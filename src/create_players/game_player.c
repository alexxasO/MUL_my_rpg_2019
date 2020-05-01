/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Game Player
*/

#include "header.h"

player_t **game_player(void)
{
    player_t **players = malloc(sizeof(player_t *) * 3);

    players[0] = NULL;
    players[1] = NULL;
    players[2] = NULL;
    return players;
}