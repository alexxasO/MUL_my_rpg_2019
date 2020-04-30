/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Game callback
*/

#include "header.h"

static void get_player_from_save(char *player_name, player_t **players)
{
    char *filename = malloc(sizeof(char) * (18 + my_strlen(player_name)));

    filename[0] = '\0';
    filename = my_strcat(filename, "image/player/");
    filename = my_strcat(filename, player_name);
    filename = my_strcat(filename, ".png");
    players[0] = create_player(filename,
    (sfVector2f){500, 500}, NULL, NULL);
    players[0]->rect = (sfIntRect){0, 0, players[0]->size.x / 7,
    players[0]->size.y / 4};
}

void game_callback(game_manager_t *gm)
{
    scene_t *scene = gm->scenes[GAME_ID];

    gm->scene_id = GAME_ID;
    get_player_from_save(gm->saves[gm->save_id]->character, scene->players);
}