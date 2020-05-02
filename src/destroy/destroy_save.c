/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Destroy save
*/

#include "header.h"

void destroy_save(save_t *save)
{
    if (save == NULL)
        return;
    free(save->name);
    free(save->character);
    free(save);
}