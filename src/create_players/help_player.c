/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Help Player
*/

#include "header.h"

player_t **help_player(void)
{
    player_t **players = malloc(sizeof(player_t *));

    players[0] = NULL;
    return players;
}