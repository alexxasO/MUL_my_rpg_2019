/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Game Player
*/

#include "header.h"

player_t **game_player(void)
{
    player_t **players = malloc(sizeof(player_t *) * 2);

    players[0] = create_player("image/player/axel.png",
    (sfVector2f){100, 500}, NULL, NULL);
    players[0]->rect = (sfIntRect){0, 0, players[0]->size.x / 7,
    players[0]->size.y / 4};
    players[1] = NULL;
    return players;
}