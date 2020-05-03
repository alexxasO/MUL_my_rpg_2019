/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Start Menu Button
*/

#include "header.h"

button_t **start_menu_button(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 5);
    char *play_pathnames[] = {"image/button/play.png",
    "image/button/play_over.png", "image/button/play_clicked.png"};
    char *quit_pathnames[] = {"image/button/quit.png",
    "image/button/quit_over.png", "image/button/quit_clicked.png"};
    char *multi_pathnames[] = {"image/button/multi.png",
    "image/button/multi_over.png", "image/button/multi_clicked.png"};
    char *sett_pathnames[] = {"image/button/setting.png",
    "image/button/setting_over.png", "image/button/setting_clicked.png"};

    buttons[0] = create_button(play_pathnames,
    (sfVector2f){320, 320}, &play_callback);
    buttons[1] = create_button(sett_pathnames,
    (sfVector2f){10, 768}, &sett_callback);
    buttons[2] = create_button(multi_pathnames,
    (sfVector2f){256, 544}, &play_multi_callback);
    buttons[3] = create_button(quit_pathnames,
    (sfVector2f){608, 768}, &quit_callback);
    buttons[4] = NULL;
    return buttons;
}