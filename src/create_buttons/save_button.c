/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Save Button
*/

#include "header.h"

button_t **save_button(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 5);
    char *no_save_pathnames[] = {"image/button/no_save.png",
    "image/button/no_save_over.png", "image/button/no_save_clicked.png"};
    char *save_pathnames[] = {"image/button/save.png",
    "image/button/save_over.png", "image/button/save_clicked.png"};
    char *return_pathnames[] = {"image/button/return.png",
    "image/button/return_over.png", "image/button/return_clicked.png"};

    for (size_t i = 0; i < 3; i++) {
        if (check_save(i) == sfFalse)
            buttons[i] = create_button(no_save_pathnames,
            (sfVector2f){320, 32 + i * 288}, &new_callback);
        else
            buttons[i] = create_button(save_pathnames,
            (sfVector2f){320, 32 + i * 288}, &game_callback);
    }
    buttons[3] = create_button(return_pathnames,
    (sfVector2f){704, 896}, &return_callback);
    buttons[4] = NULL;
    return buttons;
}