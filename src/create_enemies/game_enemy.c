/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Game Enemy
*/

#include "header.h"

enemy_t **game_enemy(void)
{
    enemy_t **enemies = malloc(sizeof(enemy_t *));

    enemies[0] = NULL;
    return enemies;
}