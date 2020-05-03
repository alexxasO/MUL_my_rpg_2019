/*
** EPITECH PROJECT, 2020
** launch_serv.c
** File description:
** launch serv
*/

#include "header.h"

int host_soket_and_listener(sfIpAddress ip, unsigned short port, serv_t *serv)
{
    sfTcpListener *listener = sfTcpListener_create();

    serv->cli_a.sok = sfTcpSocket_create();
    serv->cli_b.sok = sfTcpSocket_create();
    if (sfTcpListener_listen(listener, port, ip) != sfSocketDone) {
        my_printf("error listener\n");
        return 1;
    }
    if (sfTcpListener_accept(listener, &serv->cli_a.sok) != sfSocketDone) {
        my_printf("error accept\n");
    }
    get_infos(&serv->cli_a);
    if (sfTcpListener_accept(listener, &serv->cli_b.sok) != sfSocketDone) {
        my_printf("error accept\n");
    }
    get_infos(&serv->cli_b);
    sfTcpListener_destroy(listener);
    return 0;
}

void transmit_data(char who, serv_t *serv, char *data)
{
    if (who == 'a') {
        my_printf("Data received from %s:%i\nData : %s\n", serv->cli_a.ip_s,
        serv->cli_a.port, data);
        send_packages(&serv->cli_b, data);
    }
    if (who == 'b') {
        my_printf("data received from %s:%i\nData : %s\n", serv->cli_b.ip_s,
        serv->cli_b.port, data);
        send_packages(&serv->cli_a, data);
    }
}

void data_management(serv_t *serv, client_t *client)
{
    char who = '\0';
    char *data = NULL;

    while (data == NULL) {
        if ((data = receive_packages(&serv->cli_a)) != NULL) {
            who = 'a';
            break;
        }
        if ((data = receive_packages(&serv->cli_b)) != NULL) {
            who = 'b';
            break;
        }
    }
    transmit_data(who, serv, data);
}

void launch_serv(client_t *client)
{
    serv_t serv;
    char ip[16];

    client = init_socket(client);
    sfIpAddress_toString(client->ip, ip);
    my_printf("Welcome !\nHost the best RPG on our server\n");
    my_printf("Ip : %s\nPort : %i\n", ip, client->port);
    host_soket_and_listener(client->ip, client->port, &serv);
    sfTcpSocket_setBlocking(serv.cli_a.sok, sfFalse);
    sfTcpSocket_setBlocking(serv.cli_b.sok, sfFalse);
    data_management(&serv, client);
    sfTcpSocket_destroy(serv.cli_a.sok);
    sfTcpSocket_destroy(serv.cli_b.sok);
    sfTcpSocket_destroy(client->sok);
}