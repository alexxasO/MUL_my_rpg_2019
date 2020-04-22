/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Quit callback
*/

#include "header.h"

void quit_callback(game_manager_t *gm)
{
    sfRenderWindow_close(gm->window);
}