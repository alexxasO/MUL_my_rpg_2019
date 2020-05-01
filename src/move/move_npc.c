/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Move npc
*/

#include "header.h"

void move_npc(player_t **players, float add_x, float add_y)
{
    for (size_t i = 1; i < 2; i++) {
        players[i]->pos.x -= add_x;
        players[i]->pos.y -= add_y;
    }
}