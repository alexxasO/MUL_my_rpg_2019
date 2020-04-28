/*
** EPITECH PROJECT, 2020
** create_save.c
** File description:
** here we go again
*/

#include "header.h"

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

char *int_to_buf(int i)
{
    char *buf = malloc(sizeof(char) * 3);

    buf[0] = i + '0';
    buf[1] = '\n';
    buf[2] = '\0';
    return buf;
}

void create_save(save_t *save, int save_slot)
{
    char *path = get_path(save_slot);
    int fd = 0;
    int name_len = my_strlen(save->name);
    int char_len = my_strlen(save->character);
//    int inventory_len = my_arraylen(save->inventory);

    fd = open(path, O_RDWR);
    write(fd, (my_strcat_malloc(save->name, "\n")), name_len + 1);
    write(fd, int_to_buf(save->level), 2);
    write(fd, int_to_buf(save->exp), 2);
    write(fd, int_to_buf(save->stage), 2);
    write(fd, (my_strcat_malloc(save->character, "\n"), char_len + 1);
    // for (int i = 0; save->inventory[i]; i++)
    //  write(fd, save->inventory[i], (my_strlen(save->inventory[i]));
    close(fd);
}
