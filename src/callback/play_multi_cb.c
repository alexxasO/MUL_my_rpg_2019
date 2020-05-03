/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Play multi callback
*/

#include "header.h"

void play_multi_callback(game_manager_t *gm)
{
    gm->scene_id = SAVE_MULTI_ID;
}

void play_multi_id_callback(game_manager_t *gm)
{
    gm->scene_id = MULTI_IP_ID;
}

void validate_ip_cb(game_manager_t *gm)
{
    gm->client.ip_s = my_strdup(gm->scenes[gm->scene_id]->texts[0]->string);
    init_socket(&gm->client, gm->client.ip_s);
    create_client_socket(&gm->client);
    free(gm->scenes[gm->scene_id]->texts[1]->string);
    gm->scenes[gm->scene_id]->texts[1]->string =
    my_strdup("Connected to server\nWaiting for enemy");
    if (waiting_for_connexion(gm) == true)
        gm->scene_id = CHAT_ID;
}

void chat_cb(game_manager_t *gm)
{
    send_packages(&gm->client, gm->scenes[gm->scene_id]->texts[0]->string);
}

void refresh_cb(game_manager_t *gm)
{
    char * tmp = receive_packages(&gm->client);

    if (tmp) {
        free(gm->scenes[gm->scene_id]->texts[1]->string);
        gm->scenes[gm->scene_id]->texts[1]->string = my_strdup(tmp);
    }
}