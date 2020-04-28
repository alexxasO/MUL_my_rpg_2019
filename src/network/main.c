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

void get_infos(client_t *cli)
{
    cli->ip_s = malloc(sizeof(char) * 16);

    if (cli->sok) {
        cli->ip = sfTcpSocket_getRemoteAddress(cli->sok);
        cli->port = sfTcpSocket_getRemotePort(cli->sok);
        sfIpAddress_toString(cli->ip, cli->ip_s);
        printf("Client from ip : %s port %i connected\n", cli->ip_s, cli->port);
    }
}

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
    get_infos(&serv->cli_a);
    if (sfTcpListener_accept(listener, &serv->cli_b.sok) != sfSocketDone) {
        printf("error accept\n");
    }
    get_infos(&serv->cli_b);
    sfTcpListener_destroy(listener);
    return 0; 
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
        printf("Send error\n");
        sfTcpSocket_setBlocking(client->sok, sfFalse);
        return;
    }
    printf("Data send\n");
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

void transmit_data(char who, serv_t *serv, char *data)
{
    if (who == 'a') {
        printf("Data received from %s:%i\nData : %s\n", serv->cli_a.ip_s,
        serv->cli_a.port, data);
        send_packages(&serv->cli_b, data);
    }
    if (who == 'b') {
        printf("data received from %s:%i\nData : %s\n", serv->cli_b.ip_s,
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
    printf("Welcome !\nHost the best RPG on our server\nIp : %s\nPort : %i\n", ip, client->port);
    host_socket_and_listener(client->ip, client->port, &serv);
    sfTcpSocket_setBlocking(serv.cli_a.sok, sfFalse);
    sfTcpSocket_setBlocking(serv.cli_b.sok, sfFalse);
    data_management(&serv, client);
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
    if (host == 0 && av[1][0] == 'a') {
        init_socket(&client);
        create_client_socket(&client);
        send_packages(&client, "Ceci testenvoi");
    }
    if (host == 0 && av[1][0] == 'b') {
        init_socket(&client);
        create_client_socket(&client);
        receive_packages(&client);
    }
    return 0;
}