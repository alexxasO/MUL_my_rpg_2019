/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Fulfill dave file
*/

#include "header.h"

static void write_and_add_newline(int fd, char *str, int length)
{
    write(fd, str, length);
    write(fd, "\n", 1);
}

void fulfill_save(save_t *save, char *filename)
{
    int fd = open(filename, O_RDWR);
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
    write_and_add_newline(fd, save->character, char_len);
    // for (int i = 0; save->inventory[i]; i++)
    //  write(fd, save->inventory[i], (my_strlen(save->inventory[i]));
    close(fd);
}
