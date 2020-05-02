/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Pause button
*/

#include "header.h"

button_t **pause_button(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 5);
    char *help_pathnames[] = {"image/button/help.png",
    "image/button/help_over.png", "image/button/help_clicked.png"};
    char *quit_pathnames[] = {"image/button/quit.png",
    "image/button/quit_over.png", "image/button/quit_clicked.png"};
    char *resume_pathnames[] = {"image/button/resume.png",
    "image/button/resume_over.png", "image/button/resume_clicked.png"};
    char *menu_pathnames[] = {"image/button/menu.png",
    "image/button/menu_over.png", "image/button/menu_clicked.png"};

    buttons[0] = create_button(resume_pathnames,
    (sfVector2f){896, 96}, &resume_callback);
    buttons[1] = create_button(help_pathnames,
    (sfVector2f){1024, 320}, &help_callback);
    buttons[2] = create_button(menu_pathnames,
    (sfVector2f){1024, 544}, &return_callback);
    buttons[3] = create_button(quit_pathnames,
    (sfVector2f){1024, 768}, &quit_callback);
    buttons[4] = NULL;
    return buttons;
}
