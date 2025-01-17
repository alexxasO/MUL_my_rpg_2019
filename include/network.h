/*
** EPITECH PROJECT, 2020
** network.h
** File description:
** networking
*/

#ifndef NET_H_
#define NET_H_

#define REC_SIZE 40
#define PORT 5000
#define IP_SERV "127.0.0.1"

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

void data_management(serv_t *serv);
void transmit_data(char who, serv_t *serv, char *data);
int host_soket_and_listener(sfIpAddress ip, unsigned short port, serv_t *serv);
void get_infos(client_t *cli);
void create_client_socket(client_t *client);
void send_packages(client_t *client, char *pack);
char *receive_packages(client_t *client);
client_t *init_socket(client_t *client, char *s);
void manage_accept(sfTcpListener *listener, serv_t *serv);

#endif
