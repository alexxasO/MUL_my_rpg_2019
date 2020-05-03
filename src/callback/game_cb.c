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

static void set_background(background_t **backgrounds, size_t stage)
{
    char *stage_str = my_put_nbr_in_str(stage);
    char *pathname = malloc(sizeof(char) * (27 + my_strlen(stage_str)));

    pathname[0] = '\0';
    pathname = my_strcat(pathname, "image/background/level");
    pathname = my_strcat(pathname, stage_str);
    pathname = my_strcat(pathname, ".png");
    if (backgrounds[0] != NULL) {
        destroy_background(backgrounds[0]);
        backgrounds[0] = NULL;
        backgrounds[0] = create_background(pathname,
        (sfVector2f){0, -800}, NULL);
    }
    free(pathname);
    free(stage_str);
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
    for (size_t i = 0; i < 12; i++)
        if (save->inventory[i] == 2)
            update_stat(i, scene->players, 1);
    if (save->stage != 10) {
        set_npc(scene->players, scene->backgrounds[0]);
        set_enemy(scene->enemies, scene->backgrounds[0]);
    }
    set_background(scene->backgrounds, save->stage);
}