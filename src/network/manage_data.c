/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** Main
*/

#include "header.h"

void get_infos(client_t *cli)
{
    cli->ip_s = malloc(sizeof(char) * 16);

    if (cli->sok) {
        cli->ip = sfTcpSocket_getRemoteAddress(cli->sok);
        cli->port = sfTcpSocket_getRemotePort(cli->sok);
        sfIpAddress_toString(cli->ip, cli->ip_s);
        my_printf("Client from ip : %s port %i connected\n", cli->ip_s, cli->port);
    }
}

void create_client_socket(client_t *client)
{
    sfTime time = sfSeconds(15.0);
    sfSocketStatus status;

    status = sfTcpSocket_connect(client->sok, client->ip, client->port, time);
}

void send_packages(client_t *client, char *pack)
{
    sfTcpSocket_setBlocking(client->sok, sfTrue);
    if (sfTcpSocket_send(client->sok, pack, REC_SIZE) != sfSocketDone) {
        my_printf("Send error\n");
        sfTcpSocket_setBlocking(client->sok, sfFalse);
        return;
    }
    my_printf("Data send\n");
    sfTcpSocket_setBlocking(client->sok, sfFalse);
}

char *receive_packages(client_t *client)
{
    char *data;
    size_t size;

    data = malloc(sizeof(char) * REC_SIZE);
    if (sfTcpSocket_receive(client->sok, data, REC_SIZE, &size) == sfSocketDone) {
        return data;
    }
    return NULL;
}

client_t *init_socket(client_t *client)
{
    //sfTime time = sfSeconds(15.0);
    client->sok = sfTcpSocket_create();
    //client->ip = sfIpAddress_getPublicAddress(time);
    client->ip = sfIpAddress_LocalHost;
    client->port = PORT;
    return client;
}