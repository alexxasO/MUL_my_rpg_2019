/*
** EPITECH PROJECT, 2020
** pause_menu_button.c
** File description:
** pause menu buttons cretae
*/

#include "header.h"

button_t **pause_menu_button(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 3);
    char *resume_pathnames[] = {"image/button/resume.png",
                                "image/button/play_clicked.png"};
    char *quit_pathnames[] = {"image/button/quit.png",
                              "image/button/quit_over.png",
                              "image/button/quit_clicked.png"};
    char *how_to_pathnames[] = {"image/button/how_to_play.png",
                                "image/button/how_to_play_over.png",
                                "image/button/how_to_play_text.png"};
    char *return_pathnames[] = {"image/button/menu.png",
                                "image/button/menu_clicked.png"};

    buttons[0] = create_button(resume_pathnames,
                               (sfVector2f){320, 320}, &resume_callback);
    buttons[1] = create_button(how_to_pathnames,
                               (sfVector2f){320, 546}, &how_to_callback);
    buttons[2] = create_button(return_pathnames,
                               (sfVector2f){320, 772}, &return_callback);
    buttons[3] = create_button(quit_pathnames,
                               (sfVector2f){320, 928}, &quit_callback);
    buttons[4] = NULL;
    return buttons;
}
