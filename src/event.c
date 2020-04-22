/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** Handle events
*/

#include "header.h"

void handle_event(game_manager_t *gm, sfEvent event)
{
    gm->is_mouse_clicked = sfFalse;
    while (sfRenderWindow_pollEvent(gm->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(gm->window);
            break;
        }
        if (event.type == sfEvtMouseButtonPressed)
            gm->is_mouse_clicked = sfTrue;
        free(gm->key_pressed);
        if (event.type == sfEvtKeyPressed) {
            if (event.key.code == sfKeyLeft)
                gm->key_pressed = my_strdup("left");
            if (event.key.code == sfKeyRight)
                gm->key_pressed = my_strdup("right");
            if (event.key.code == sfKeyDown)
                gm->key_pressed = my_strdup("down");
            if (event.key.code == sfKeyUp)
                gm->key_pressed = my_strdup("up");
        } else {
            gm->key_pressed = my_strdup("none");
        }
    }
}