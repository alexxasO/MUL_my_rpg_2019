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

    // players[0] = create_player("image/player/axel.png",
    // (sfVector2f){100, 500}, NULL, NULL);
    // players[0]->rect = (sfIntRect){0, 0, players[0]->size.x / 7,
    // players[0]->size.y / 4};
    // players[0]->fighter_info->sprite = players[0]->sprite;
    // players[0]->life = 100;
    // create_fighter_info(players[0]);
    // players[1] = create_player("image/player/axel.png",
    // (sfVector2f){100, 500}, NULL, NULL);
    // players[1]->rect = (sfIntRect){0, 0, players[0]->size.x / 7,
    // players[1]->size.y / 4};
    // players[1]->fighter_info->sprite = players[0]->sprite;
    // players[1]->life = 48;
    // players[2] = NULL;
    // printf("attack 0 : %s\n", players[0]->fighter_info->attacks[0]->name);
    players[0] = NULL;
    return players;
}