/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Sett Button
*/

#include "header.h"

button_t **sett_button(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 2);
    char *return_pathnames[] = {"image/button/return.png",
    "image/button/return_over.png", "image/button/return_clicked.png"};

    buttons[0] = create_button(return_pathnames,
    (sfVector2f){704, 880}, &return_callback);
    buttons[1] = NULL;
    return buttons;
}