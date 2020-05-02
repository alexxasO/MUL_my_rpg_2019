/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Save Multi Scene
*/

#include "header.h"

static void compare_and_replace(char **string1, char *string2)
{
    if (my_strcmp(string1[0], string2) != 0) {
        free(string1[0]);
        string1[0] = my_strdup(string2);
    }
}

static void print_save_data(save_t **saves, scene_t *scene)
{
    char *level = NULL;
    char *stage = NULL;

    for (size_t i = 0; i < 3; i++) {
        if (saves[i] == NULL)
            continue;
        level = my_put_nbr_in_str(saves[i]->level);
        stage = my_put_nbr_in_str(saves[i]->stage);
        compare_and_replace(&scene->texts[i * 3]->string, saves[i]->name);
        scene->texts[i * 3]->pos.x = 400 -
        my_strlen(scene->texts[i * 3]->string) * 5;
        compare_and_replace(&scene->texts[i * 3 + 1]->string, level);
        compare_and_replace(&scene->texts[i * 3 + 2]->string, stage);
        free(level);
        free(stage);
    }
}

void save_multi_func(game_manager_t *gm)
{
    scene_t *scene = gm->scenes[gm->scene_id];

    print_save_data(gm->saves, scene);
    handle_buttons(gm, scene);
    for (size_t i = 0; i < 3; i++)
        if (scene->buttons[i]->state == 2)
            gm->save_id = i;
}