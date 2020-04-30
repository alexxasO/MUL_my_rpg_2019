/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** fight_players.c
*/

#include "header.h"

player_t **fight_player(void)
{
    player_t **players = malloc(sizeof(player_t *) * 3);

    players[0] = create_player("image/player/axel.png",
    (sfVector2f){100, 500}, NULL, NULL);
    players[0]->rect = (sfIntRect){0, 0, players[0]->size.x / 7,
    players[0]->size.y / 4};
    players[0]->fighter_info->sprite = players[0]->sprite;
    players[1] = create_player("image/player/axel.png",
    (sfVector2f){100, 500}, NULL, NULL);
    players[1]->rect = (sfIntRect){0, 0, players[0]->size.x / 7,
    players[1]->size.y / 4};
    players[1]->fighter_info->sprite = players[0]->sprite;
    players[2] = NULL;
    return players;
}