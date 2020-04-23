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

int host_socket_and_listener(sfIpAddress ip, unsigned short port, serv_t *serv)
{
    sfTcpListener *listener = sfTcpListener_create();

    serv->cli_a.sok = sfTcpSocket_create();
    serv->cli_b.sok = sfTcpSocket_create();
    if (sfTcpListener_listen(listener, port, ip) != sfSocketDone) {
        printf("error 1\n");
        return 1;
    }
    if (sfTcpListener_accept(listener, &serv->cli_a.sok) != sfSocketDone) {
        printf("error accept\n");
    }
    printf("Client a connected\n");
    if (sfTcpListener_accept(listener, &serv->cli_b.sok) != sfSocketDone) {
        printf("error accept\n");
    }
    printf("Client b connected\n");
    sfTcpListener_destroy(listener);
    return 0; 
}

void create_client_socket(client_t *client)
{
    sfTime time = sfSeconds(15.0);
    sfSocketStatus status;

    status = sfTcpSocket_connect(client->sok, client->ip, client->port, time);
    while(1);
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
    sfTime time = sfSeconds(15.0);
    client->sok = sfTcpSocket_create();
    //client->ip = sfIpAddress_getPublicAddress(time);
    client->ip = sfIpAddress_LocalHost;
    client->port = 5001;
    return client;
}

void launch_serv(client_t *client)
{
    serv_t serv;
    char test[16];

    client = init_socket(client);
    sfIpAddress_toString(client->ip, test);
    printf("Welcome !\nHost the best RPG on our server\nIp : %s\nPort : %i\n", test, client->port);
    host_socket_and_listener(client->ip, client->port, &serv);
    printf("coucou\n");
    // while (1) {
    //     receive_packages(serv.cli_a.sok);
    //     receive_packages(serv.cli_b.sok);
    // }
    sfTcpSocket_destroy(serv.cli_a.sok);
    sfTcpSocket_destroy(serv.cli_b.sok);
    sfTcpSocket_destroy(client->sok);
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
    if (host == 0) {
        init_socket(&client);
        create_client_socket(&client);
    }
    return 0;
}