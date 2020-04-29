/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** fight_func.c
*/

#include "header.h"

static void print_char_infos(int id, char *name, UN int life, scene_t *scene)
{
    sfText *text = sfText_create();
    sfText **scene_texts = scene->sftexts;
    sfText **new_scene_texts =  malloc(sizeof(sfText *) * (id + 2));
    sfFont *font = sfFont_createFromFile("font/Comic Book.otf");

    if (scene_texts == NULL) {
        scene_texts = malloc(sizeof(sfText *) * 1);
        scene_texts[0] = NULL;
    }
    sfText_setColor(text, sfWhite);
    sfText_setCharacterSize(text, 20);
    sfText_setString(text, name);
    sfText_setFont(text, font);
    for (int j = 0; scene_texts[j]; j++)
        new_scene_texts[j] = scene_texts[j];
    sfText_setPosition(text, (sfVector2f){50, SCR_HEIGHT - 160 + (25 * id)});
    new_scene_texts[id] = text;
    new_scene_texts[id + 1] = NULL;
    scene->sftexts = new_scene_texts;
    free(scene_texts);
}

void show_char_info(player_t **players, game_manager_t *gm)
{
    int ply_life = 0;
    char *ply_name = NULL;
    int ply_id = -1;
    scene_t *scene = gm->scenes[gm->scene_id];

    for (int i = 0; players[i]; i++) {
        ply_life = players[i]->life;
        ply_name = "Exemple - 56HP";
        ply_id = i;
        print_char_infos(ply_id, ply_name, ply_life, scene);
    }
}

void place_infobar(player_t **players, UN enemy_t **enemies, game_manager_t *gm)
{
    show_char_info(players, gm);
}