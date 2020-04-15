/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Start Menu Button
*/

#include "header.h"

button_t **start_menu_button(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 3);

    buttons[0] = create_button("image/background/play.png",
    (sfVector2f){0, 0}, NULL);
    buttons[1] = create_button("image/background/quit.png",
    (sfVector2f){0, 100}, NULL);
    buttons[2] = NULL;
    return buttons;
}