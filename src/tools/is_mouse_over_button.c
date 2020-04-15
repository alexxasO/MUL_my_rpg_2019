/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** Handle events
*/

#include "header.h"

sfBool is_mouse_over_button(game_manager_t *gm, button_t *button)
{
    if (gm->click_position.x < button->pos.x)
        return sfFalse;
    if (gm->click_position.x > button->pos.x + button->rect.width)
        return sfFalse;
    if (gm->click_position.y < button->pos.y)
        return sfFalse;
    if (gm->click_position.y > button->pos.y + button->rect.height)
        return sfFalse;
    return sfTrue;
}