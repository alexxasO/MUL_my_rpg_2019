/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** Handle events
*/

#include "header.h"

static char *get_key_pressed(game_manager_t *gm, sfEvent event)
{
    if (gm->scene_id == NEW_ID)
        write_save_name(gm, event);
    if (event.key.code == sfKeyLeft)
        return my_strdup("left");
    if (event.key.code == sfKeyRight)
        return my_strdup("right");
    if (event.key.code == sfKeyDown)
        return my_strdup("down");
    if (event.key.code == sfKeyUp)
        return my_strdup("up");
    if (event.key.code == sfKeyI)
        return my_strdup("i");
    if (event.key.code == sfKeyEscape)
        return my_strdup("esc");
    if (event.key.code == sfKeyEnter)
        return my_strdup("enter");
    return my_strdup("none");
}

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
            gm->key_pressed = get_key_pressed(gm, event);
            break;
        } else
            gm->key_pressed = my_strdup("none");
    }
}
