/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Inventory and Status Scene
*/

#include "header.h"

static void compare_and_replace(char **string1, char *string2)
{
    if (my_strcmp(string1[0], string2) != 0) {
        free(string1[0]);
        string1[0] = my_strdup(string2);
    }
}

static void print_stats(player_t **players, scene_t *scene)
{
    char *level = my_put_nbr_in_str(0);
    char *life = my_put_nbr_in_str(1);
    char *attack = my_put_nbr_in_str(2);
    char *defense = my_put_nbr_in_str(3);

    compare_and_replace(&scene->texts[0]->string, level);
    compare_and_replace(&scene->texts[1]->string, life);
    compare_and_replace(&scene->texts[2]->string, attack);
    compare_and_replace(&scene->texts[3]->string, defense);
    free(level);
    free(life);
    free(attack);
    free(defense);
}

void inventory_and_status_func(game_manager_t *gm)
{
    scene_t *scene = gm->scenes[gm->scene_id];

    print_stats(scene->players, scene);
    handle_buttons(gm, scene);
    if (my_strcmp(gm->key_pressed, "i") == 0)
        gm->scene_id = GAME_ID;
}