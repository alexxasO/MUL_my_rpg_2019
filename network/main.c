/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** Main
*/

#include "header.h"
#include "SFML/Network.h"


void host_socket_and_listener(sfIpAddress ip, unsigned short port)
{
    sfTcpSocket *client = sfTcpSocket_create();
    sfTcpListener *listener = sfTcpListener_create();

    if (sfTcpListener_listen(listener, port, ip) != sfSocketDone) {
        return;
    }
    if (sfTcpListener_accept(listener, &client) != sfSocketDone) {
        return;
    }
}

void create_client_socket(sfIpAddress ip, unsigned short port)
{
    sfTcpSocket *socket = sfTcpSocket_create();
    sfTime time;
    sfSocketStatus status;

    time.microseconds = -1;
    status = sfTcpSocket_connect(socket, ip, port, time);
}

int main(int ac, char **av, char **env)
{
    sfIpAddress ip = sfIpAddress_LocalHost;
    unsigned short port = 5000;

    if (ac == 2) {
        create_client_socket(ip, port);
    }
    if (ac == 1) {
        host_socket_and_listener(ip, port);
    }
    return 0;
}