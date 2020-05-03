/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Fight Enemy
*/

#include "header.h"

enemy_t **fight_enemy(void)
{
    enemy_t **enemies = malloc(sizeof(enemy_t *) * 3);

    enemies[0] = NULL;
    enemies[1] = NULL;
    enemies[2] = NULL;
    return enemies;
}