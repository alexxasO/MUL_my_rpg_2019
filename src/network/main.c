/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** Main
*/

#include <stdio.h>
#include <SFML/Network.h>
#include "network.h"
#include "header.h"

void host_socket_and_listener(sfIpAddress ip, unsigned short port, serv_t *serv)
{
    sfTcpListener *listener = sfTcpListener_create();
    sfTime time;

    serv->cli_a.sok = sfTcpSocket_create();
    serv->cli_b.sok = sfTcpSocket_create();
    if (sfTcpListener_listen(listener, port, ip) != sfSocketDone) {
        printf("error\n");
        return;
    }
    if (sfTcpListener_accept(listener, &serv->cli_a.sok) != sfSocketDone) {
        printf("Client a connected\n");
        return;
    }
    if (sfTcpListener_accept(listener, &serv->cli_b.sok) != sfSocketDone) {
        printf("Client b connected\n");
        return;
    }
}

sfTcpSocket *create_client_socket(sfIpAddress ip)
{
    sfTcpSocket *socket = sfTcpSocket_create();
    unsigned short port = sfTcpSocket_getLocalPort(socket);
    sfTime time;
    sfSocketStatus status;

    time.microseconds = -1;
    status = sfTcpSocket_connect(socket, ip, port, time);
    return socket;
}

void send_packages(sfTcpSocket *client, char *pack)
{
    if (sfTcpSocket_send(client, pack, 10) != sfSocketDone) {
        printf("Send error\n");
        return;
    }
    printf("send\n");
}

void receive_packages(sfTcpSocket *client)
{
    char data[10];
    size_t size;

    if (sfTcpSocket_receive(client, data, 10, &size) != sfSocketDone) {
        //printf("Error received\n");
        return;
    }
    printf("data : %s\n", data);
}

client_t *init_socket(client_t *client)
{
    sfTime time;
    client->sok = sfTcpSocket_create();
    client->ip = sfIpAddress_getPublicAddress(time);
    return client;

}

void launch_serv(client_t *client)
{
    serv_t serv;
    char *line = NULL;
    size_t len;

    client = init_socket(client);
    getline(&line, &len, stdin);
    host_socket_and_listener(client->ip, client->port, &serv);
    while (1) {
        receive_packages(serv.cli_a.sok);
        receive_packages(serv.cli_b.sok);
    }
}

int main(int ac, char **av, char **env)
{
    client_t client;
    int host = 0;

    for (int i = 0; i < ac; i++) {
        if ((my_strcmp("--host", av[i]) == 0) || (my_strcmp("-H", av[i]) == 0)) {
            launch_serv(&client);
            host++;
            break;
        }
    }
    return 0;
}