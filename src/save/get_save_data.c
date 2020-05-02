/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** Get Save Data
*/

#include "header.h"

static void get_name_level_stage_and_char(FILE *file, save_t *save)
{
    size_t n = 0;
    char *buf = NULL;

    getline(&buf, &n, file);
    save->name = my_strdup(buf);
    save->name[my_strlen(save->name) - 1] = '\0';
    getline(&buf, &n, file);
    save->level = my_getnbr(buf);
    getline(&buf, &n, file);
    save->exp = my_getnbr(buf);
    getline(&buf, &n, file);
    save->stage = my_getnbr(buf);
    getline(&buf, &n, file);
    save->character = my_strdup(buf);
    save->character[my_strlen(save->character) - 1] = '\0';
    getline(&buf, &n, file);
    for (size_t i = 0; i < 12; i++)
        save->inventory[i] = buf[i] - '0';
    free(buf);
}

save_t *get_save_data(size_t save_nb)
{
    save_t *save = malloc(sizeof(save_t));
    char filename[] = "file/savex";
    FILE *file = NULL;

    filename[9] = 49 + save_nb;
    file = fopen(filename, "r");
    get_name_level_stage_and_char(file, save);
    fclose(file);
    return save;
}
