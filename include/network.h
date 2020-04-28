/*
** EPITECH PROJECT, 2020
** network.h
** File description:
** networking
*/

#ifndef NET_H_
#define NET_H_
#include "includes.h"

#define REC_SIZE 20
#define PORT 4998

typedef struct {
    sfIpAddress ip;
    char *ip_s;
    unsigned short port;
    sfTcpSocket *sok;
} client_t;

typedef struct {
    client_t cli_a;
    client_t cli_b;
} serv_t;

#endif
