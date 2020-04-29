/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** New Button
*/

#include "header.h"

button_t **new_button(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 4);
    char *left_arrow_pathnames[] = {"image/button/left_arrow.png",
    "image/button/left_arrow_over.png", "image/button/left_arrow_clicked.png"};
    char *right_arrow_pathnames[] = {"image/button/right_arrow.png",
    "image/button/right_arrow_over.png", "image/button/right_arrow_clicked.png"};
    char *create_pathnames[] = {"image/button/create.png",
    "image/button/create_over.png", "image/button/create_clicked.png"};

    buttons[0] = create_button(left_arrow_pathnames,
    (sfVector2f){752, 640}, NULL);
    buttons[1] = create_button(right_arrow_pathnames,
    (sfVector2f){1088, 640}, NULL);
    buttons[2] = create_button(create_pathnames,
    (sfVector2f){704, 896}, NULL);
    buttons[3] = NULL;
    return buttons;
}