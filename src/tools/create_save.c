/*
** EPITECH PROJECT, 2020
** create_save.c
** File description:
** create a save with the infos
*/

#include "../../include/header.h"

char *get_path(int slot)
{
    char *path = malloc(sizeof(char) * 10);

    path[0] ='f';
    path[1] ='i';
    path[2] ='l';
    path[3] ='e';
    path[4] ='/';
    path[5] ='s';
    path[6] ='a';
    path[7] ='v';
    path[8] ='e';
    path[9] = slot + '0';
    path[10] = '\0';
    return path;
}

void create_save(save_t *save, int save_slot)
{
    char *save_path = get_path(save_slot);
    FILE *fp = NULL;
    size_t size = sizeof(save_t);

    fp = fopen(save_path, "w");
    fwrite(save, size, 1, fp);
    fclose(fp);
    fp = NULL;
}
