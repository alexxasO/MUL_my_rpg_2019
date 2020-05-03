/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Sett Player
*/

#include "header.h"

player_t **sett_player(void)
{
    player_t **players = malloc(sizeof(player_t *));

    players[0] = NULL;
    return players;
}