/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Game Enemy
*/

#include "header.h"

enemy_t **fight_enemy(void)
{
    enemy_t **enemies = malloc(sizeof(enemy_t *) * 3);

    enemies[0] = create_enemy("image/player/axel.png",
    (sfVector2f){100, 500}, NULL, NULL);
    enemies[0]->rect = (sfIntRect){0, 0, enemies[0]->size.x / 7,
    enemies[0]->size.y / 4};
    enemies[0]->fighter_info->sprite = enemies[0]->sprite;
    enemies[1] = create_enemy("image/player/axel.png",
    (sfVector2f){100, 500}, NULL, NULL);
    enemies[1]->rect = (sfIntRect){0, 0, enemies[1]->size.x / 7,
    enemies[1]->size.y / 4};
    enemies[1]->fighter_info->sprite = enemies[1]->sprite;
    enemies[2] = NULL;
    return enemies;
}