/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** Check Save
*/

#include "header.h"

sfBool check_save(size_t save_nb)
{
    char filename[] = "file/savex";
    FILE *file = NULL;
    size_t n = 0;
    char *buf = NULL;

    filename[9] = 49 + save_nb;
    file = fopen(filename, "r");
    getline(&buf, &n, file);
    if (my_strcmp(buf, "NO\n") == 0) {
        fclose(file);
        free(buf);
        return sfFalse;
    }
    fclose(file);
    free(buf);
    return sfTrue;
}