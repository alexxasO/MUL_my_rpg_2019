/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Write ip
*/

#include "header.h"

static void add_letter(game_manager_t *gm, char *old_string, char key)
{
    char *new_string = NULL;

    free(gm->scenes[gm->scene_id]->texts[0]->string);
    new_string = malloc(sizeof(char) * (my_strlen(old_string) + 2));
    new_string[0] = '\0';
    new_string = my_strcat(new_string, old_string);
    new_string[my_strlen(old_string)] = key;
    new_string[my_strlen(old_string) + 1] = '\0';
    gm->scenes[gm->scene_id]->texts[0]->string = new_string;
    free(old_string);
}

char modify_key(int key_id)
{
    char key;

    if (key_id == '0')
        key_id = (-1);
    if (key_id > 25 && key_id < 74) {
        if (key_id == 51)
            key_id -= 21;
        if (key_id == 56)
            key_id -= 24;
        key_id += 49;
    }
    if (key_id == (-1))
        key = key_id + 47;
    else if (key_id < 26)
        key = key_id + 'A';
    else
        key = key_id - 27;
    return key;
}

void write_ip(game_manager_t *gm, sfEvent event)
{
    int key_id = event.key.code;
    char key = modify_key(key_id);
    char *old_string = my_strdup(gm->scenes[gm->scene_id]->texts[0]->string);
    int old_length = my_strlen(old_string);

    if (event.key.code == 59 && my_strlen(old_string) != 0) {
        gm->scenes[gm->scene_id]->texts[0]->string[old_length - 1] = '\0';
        free(old_string);
        return;
    }
    add_letter(gm, old_string, key);
}
