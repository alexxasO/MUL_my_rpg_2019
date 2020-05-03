/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Multi Button
*/

#include "header.h"

button_t **multi_button(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 3);
    char *host_pathnames[] = {"image/button/host.png",
    "image/button/host_over.png", "image/button/host_clicked.png"};
    char *join_pathnames[] = {"image/button/join.png",
    "image/button/join_over.png", "image/button/join_clicked.png"};

    buttons[0] = create_button(host_pathnames,
    (sfVector2f){320, 320}, &launch_serv);
    buttons[1] = create_button(join_pathnames,
    (sfVector2f){1050, 320}, &play_multi_id_callback);
    buttons[2] = NULL;
    return buttons;
}

button_t **ip_button(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 2);
    char *host_pathnames[] = {"image/button/join.png",
    "image/button/join_over.png", "image/button/join_clicked.png"};

    buttons[0] = create_button(host_pathnames,
    (sfVector2f){700, 520}, &validate_ip_cb);
    buttons[1] = NULL;
    return buttons;
}