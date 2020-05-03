/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** fight.c
*/

#include "header.h"

void fight_func(game_manager_t *gm)
{
    // gm->player_list = scene->players;
    // gm->enemy_list = scene->enemies;
    begin_fight(gm->player_list, gm->enemy_list, gm);
}