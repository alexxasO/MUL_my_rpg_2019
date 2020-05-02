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
    char *level = my_put_nbr_in_str(players[0]->level);
    char *life = my_put_nbr_in_str(players[0]->max_life);
    char *attack = my_put_nbr_in_str(players[0]->attack);
    char *defense = my_put_nbr_in_str(players[0]->defense);
    char *speed = my_put_nbr_in_str(players[0]->fighter_info->speed);

    compare_and_replace(&scene->texts[0]->string, level);
    compare_and_replace(&scene->texts[1]->string, life);
    compare_and_replace(&scene->texts[2]->string, attack);
    compare_and_replace(&scene->texts[3]->string, defense);
    compare_and_replace(&scene->texts[4]->string, speed);
    free(level);
    free(life);
    free(attack);
    free(defense);
    free(speed);
}

void inventory_and_status_func(game_manager_t *gm)
{
    scene_t *scene = gm->scenes[gm->scene_id];
    scene_t *game_scene = gm->scenes[GAME_ID];
    save_t *save = gm->saves[gm->save_id];

    for (size_t i = 0; i < 12; i++) {
        if (save->inventory[i] == 1 && scene->buttons[i] == NULL)
            add_unselect_button(i, scene);
        else if (save->inventory[i] == 2 && scene->buttons[i] == NULL)
            add_select_button(i, scene);
        if (save->inventory[i] == 0 && scene->buttons[i] != NULL) {
            destroy_button(scene->buttons[i]);
            scene->buttons[i] = NULL;
        }
    }
    print_stats(game_scene->players, scene);
    handle_buttons(gm, scene);
    if (my_strcmp(gm->key_pressed, "i") == 0)
        gm->scene_id = GAME_ID;
}