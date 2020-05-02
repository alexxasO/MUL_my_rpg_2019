/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Game Enemy
*/

#include "header.h"

enemy_t **game_enemy(void)
{
    enemy_t **enemies = malloc(sizeof(enemy_t *) * 6);

    enemies[0] = NULL;
    enemies[1] = NULL;
    enemies[2] = NULL;
    enemies[3] = NULL;
    enemies[4] = NULL;
    enemies[5] = NULL;
    enemies[6] = NULL;
    return enemies;
}