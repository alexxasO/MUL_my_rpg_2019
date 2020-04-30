/*
** EPITECH PROJECT, 2020
** create_save.c
** File description:
** here we go again
*/

#include "header.h"

static char *get_path(int slot)
{
    char *path = malloc(sizeof(char) * 10);

    path[0] = '\0';
    path = my_strcat(path, "file/save");
    path[9] = slot + '0';
    path[10] = '\0';
    return path;
}

static char *int_to_buf(int i)
{
    char *buf = malloc(sizeof(char) * 3);

    buf[0] = i + '0';
    buf[1] = '\n';
    buf[2] = '\0';
    return buf;
}

static void write_and_add_newline(int fd, char *str, int length)
{
    write(fd, str, length);
    write(fd, "\n", 1);
}

void fulfill_save(save_t *save, int save_slot)
{
    char *path = get_path(save_slot);
    int fd = open(path, O_RDWR);
    int name_len = my_strlen(save->name);
    int char_len = my_strlen(save->character);
    char *level = my_put_nbr_in_str(save->level);
    char *stage = my_put_nbr_in_str(save->stage);
    char *exp = my_put_nbr_in_str(save->exp);
//    int inventory_len = my_arraylen(save->inventory);

    write_and_add_newline(fd, save->name, name_len);
    write_and_add_newline(fd, level, my_strlen(level));
    write_and_add_newline(fd, stage, my_strlen(stage));
    write_and_add_newline(fd, exp, my_strlen(exp));
    write_and_add_newline(fd, save->character, char_len + 1);
    // for (int i = 0; save->inventory[i]; i++)
    //  write(fd, save->inventory[i], (my_strlen(save->inventory[i]));
    close(fd);
}
