/*
** EPITECH PROJECT, 2020
** network.h
** File description:
** networking
*/

#ifndef NET
#define NET
#include "includes.h"

typedef struct {
    sfIpAddress ip;
    unsigned short port;
    sfTcpSocket *sok;
} client_t;

typedef struct {
    client_t cli_a;
    client_t cli_b;
} serv_t;

#endif
