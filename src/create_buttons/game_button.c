/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Game Button
*/

#include "header.h"

button_t **game_button(void)
{
    button_t **buttons = malloc(sizeof(button_t *));

    buttons[0] = NULL;
    return buttons;
}