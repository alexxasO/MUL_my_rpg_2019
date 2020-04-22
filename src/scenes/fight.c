/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** fight.c
*/

#include "fight.h"

static void place_player(player_t **players, int nb_players)
{
    int delta_y = 170;
    int offset_y = 20;
    int offset_x = 50;

    for (int i = 0; i < nb_players; i++)
        players[i]->pos = (sfVector2f){offset_x, (delta_y * i) + offset_y};
}

void begin_fight(player_t **players, enemy_t **enemies)
{
    int nb_player = count_players(players);
    // int nb_enemy = count_enemies(enemies);
    int turn = 0;

    place_player(players, nb_player);
    // place_ennemies(enemies, nb_enemy);
    // place_infobar(players, enemies);
}

void fight_func(game_manager_t *gm)
{
    scene_t *scene = gm->scenes[gm->scene_id];
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
    gm->player_list = players;
    gm->scenes[gm->scene_id]->players = players;
    begin_fight(gm->player_list, gm->enemy_list);
}