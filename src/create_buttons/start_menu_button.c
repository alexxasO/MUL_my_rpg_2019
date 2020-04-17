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
    char *play_pathnames[] = {"image/button/play.png",
    "image/button/play_over.png", "image/button/play_clicked.png"};
    char *quit_pathnames[] = {"image/button/quit.png",
    "image/button/quit_over.png", "image/button/quit_clicked.png"};

    buttons[0] = create_button(play_pathnames,
    (sfVector2f){320, 320}, NULL);
    buttons[1] = create_button(quit_pathnames,
    (sfVector2f){320, 546}, NULL);
    buttons[2] = NULL;
    return buttons;
}