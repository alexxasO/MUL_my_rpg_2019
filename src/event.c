/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** Handle events
*/

#include "header.h"

void handle_event(game_manager_t *gm, sfEvent event)
{
    while (sfRenderWindow_pollEvent(gm->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(gm->window);
    }
}
