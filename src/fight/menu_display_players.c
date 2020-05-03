/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** fight_func.c
*/

#include "header.h"

static sfText **set_to_null(sfText **scene_texts)
{
    scene_texts = malloc(sizeof(sfText *) * 1);
    scene_texts[0] = NULL;
    return scene_texts;
}

static void print_char_infos_ply(int id, char *name, scene_t *scene)
{
    sfText *text = sfText_create();
    sfText **scene_texts = scene->sftexts;
    sfText **new_scene_texts =  malloc(sizeof(sfText *) * (id + 2));
    sfFont *font = sfFont_createFromFile("font/Astrolab.ttf");

    if (scene_texts == NULL)
        scene_texts = set_to_null(scene_texts);
    sfText_setColor(text, sfWhite);
    sfText_setCharacterSize(text, 20);
    sfText_setString(text, name);
    sfText_setFont(text, font);
    for (int j = 0; scene_texts[j]; j++)
        new_scene_texts[j] = scene_texts[j];
    sfText_setPosition(text, (sfVector2f){50,
    SCR_HEIGHT - 160 + (25 * id)});
    new_scene_texts[id] = text;
    new_scene_texts[id + 1] = NULL;
    scene->sftexts = new_scene_texts;
    free(scene_texts);
}

static char *get_char_info_ply(player_t *player)
{
    char *life_info = my_strcat_malloc(" - ", my_put_nbr_in_str(player->life));
    char *name_info = my_strcat_malloc(player->fighter_info->name, life_info);

    free(life_info);
    return name_info;
}

static void show_char_info_ply(player_t **players, game_manager_t *gm)
{
    char *ply_name = NULL;
    int ply_id = -1;
    scene_t *scene = gm->scenes[gm->scene_id];

    if (scene->sftexts) {
        free(scene->sftexts);
        scene->sftexts = NULL;
    }
    for (int i = 0; players[i]; i++) {
        ply_name = get_char_info_ply(players[i]);
        ply_id = i;
        print_char_infos_ply(ply_id, ply_name, scene);
        free(ply_name);
        ply_name = NULL;
    }
}

void place_info_ply(player_t **players, game_manager_t *gm)
{
    show_char_info_ply(players, gm);
}