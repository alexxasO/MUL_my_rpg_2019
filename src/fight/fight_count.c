/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** fight_count.c
*/

#include "header.h"
#include "fight.h"

int count_players(player_t **fighters)
{
    int i = 0;

    while (fighters[i]) {
        i++;
    }
    return i;
}

int count_enemies(enemy_t **enemies)
{
    int i = 0;

    while (enemies[i]) {
        i++;
    }
    return i;
}