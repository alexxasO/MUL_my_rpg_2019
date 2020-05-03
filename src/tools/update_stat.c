/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Update stat
*/

#include "header.h"

static int *get_value(void)
{
    int value_tmp[48] = {20, -10, 0, 0,
    0, 0, 6, -2,
    -10, 0, 10, 0,
    3, 3, 3, 3,
    -20, 10, 0, 0,
    0, 5, 0, 0,
    -20, 5, 0, 5,
    -10, 5, -5, 5,
    0, -5, 0, 10,
    0, 0, 0, 7,
    -10, 20, -10, -10,
    10, 0, 0, 0};
    int *value = malloc(sizeof(int) * 48);

    for (size_t i = 0; i < 48; i++)
        value[i] = value_tmp[i];
    return value;
}

void update_stat(size_t item_id, player_t **players, int coef)
{
    int *value = get_value();

    players[0]->max_life += value[item_id * 4] * coef;
    players[0]->attack += value[item_id * 4 + 1] * coef;
    players[0]->defense += value[item_id * 4 + 2] * coef;
    players[0]->fighter_info->speed += value[item_id * 4 + 3] * coef;
    free(value);
}