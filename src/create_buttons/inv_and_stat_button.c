/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Inventory and Status Button
*/

#include "header.h"

button_t **inventory_and_status_button(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 13);

    for (size_t i = 0; i < 13; i++)
        buttons[i] = NULL;
    return buttons;
}