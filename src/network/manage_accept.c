/*
** EPITECH PROJECT, 2020
** manage accpt
** File description:
** manage
*/

#include "header.h"

void manage_accept(sfTcpListener *listener, serv_t *serv)
{
    if (sfTcpListener_accept(listener, &serv->cli_a.sok) != sfSocketDone) {
        my_printf("error accept\n");
    }
    get_infos(&serv->cli_a);
    if (sfTcpListener_accept(listener, &serv->cli_b.sok) != sfSocketDone) {
        my_printf("error accept\n");
    }
    send_packages(&serv->cli_a, "ok");
    send_packages(&serv->cli_b, "ok");
    get_infos(&serv->cli_b);
}