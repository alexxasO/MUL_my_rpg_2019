/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** Handle events
*/

#include "header.h"

void get_mouse_pos(game_manager_t *gm)
{
    sfWindowHandle window_handle = sfRenderWindow_getSystemHandle(gm->window);
    sfWindow *window = sfWindow_createFromHandle(window_handle, NULL);
    sfVector2i click_pos = {-1, -1};

    click_pos = sfMouse_getPosition(window);
    gm->click_position = (sfVector2f){click_pos.x, click_pos.y};
    gm->click_position = (sfVector2f){click_pos.x, click_pos.y};
    sfWindow_destroy(window);
}