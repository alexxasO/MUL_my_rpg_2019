/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** fight_func.c
*/

#include "header.h"

static void print_char_infos(int id, char *name, scene_t *scene, int start)
{
    sfText *text = sfText_create();
    sfText **scene_texts = scene->sftexts;
    sfText **new_scene_texts =  malloc(sizeof(sfText *) * (id + 2));
    sfFont *font = sfFont_createFromFile("font/Astrolab.ttf");

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
    sfText_setPosition(text, (sfVector2f){SCR_WIDTH - 300,
    SCR_HEIGHT - 160 + (25 * (id - start))});
    new_scene_texts[id] = text;
    new_scene_texts[id + 1] = NULL;
    scene->sftexts = new_scene_texts;
    free(scene_texts);
}

static char *get_char_info(enemy_t *enemy)
{
    char *life_info = my_strcat_malloc(" - ", my_put_nbr_in_str(enemy->life));
    char *name_info = my_strcat_malloc(enemy->fighter_info->name, life_info);

    free(life_info);
    return name_info;
}

static void show_char_info(enemy_t **enemies, game_manager_t *gm)
{
    char *enemy_name = NULL;
    int enemy_id = -1;
    scene_t *scene = gm->scenes[gm->scene_id];
    int start = 0;

    if (scene->sftexts)
        for (; scene->sftexts[start]; start++);
    for (int i = 0; enemies[i]; i++) {
        enemy_name = get_char_info(enemies[i]);
        enemy_id = start + i;
        print_char_infos(enemy_id, enemy_name, scene, start);
        free(enemy_name);
        enemy_name = NULL;
    }
}

void place_info_enemies(enemy_t **enemies, game_manager_t *gm)
{
    show_char_info(enemies, gm);
}