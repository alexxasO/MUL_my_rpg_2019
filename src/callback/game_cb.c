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
    save_t *save = gm->saves[gm->save_id];

    gm->scene_id = GAME_ID;
    get_player_from_save(gm->saves[gm->save_id]->character, scene->players);
    scene->players[0]->level = save->level;
    scene->players[0]->max_life = save->level * 5 + 40;
    scene->players[0]->attack = save->level * 2 + 5;
    scene->players[0]->defense = save->level * 2 + 3;
    scene->players[0]->fighter_info->speed = save->level + 3;
    for (size_t i = 0; i < 12; i++)
        if (save->inventory[i] == 2)
            update_stat(i, scene->players, 1);
    set_npc(scene->players, scene->backgrounds[0]);
    set_enemy(scene->enemies, scene->backgrounds[0]);
}