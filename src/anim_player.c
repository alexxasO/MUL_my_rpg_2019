/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Animate player
*/

#include "header.h"

static void set_direction_and_top(game_manager_t *gm, player_t *player)
{
    const char *keys[] = {"down", "up", "right", "left"};

    for (size_t i = 0; i < 4; i++) {
        if (my_strcmp(gm->key_pressed, keys[i]) == 0) {
            player->direction = i;
            player->rect.top = player->direction * (player->size.y / 4);
        }
    }
}

static void set_left(player_t *player, float time, float framerate)
{
    for (float i = 0; i < time; i += framerate) {
        if (player->rect.left + (player->size.x / 7) >= player->size.x)
            player->rect.left = player->size.x / 7;
        else
            player->rect.left += player->size.x / 7;
    }
}

void anim_player(game_manager_t *gm, player_t *player)
{
    float time = sfTime_asSeconds(sfClock_getElapsedTime(player->clock_anim));
    float framerate = 0.15;

    if (is_arrow_pressed(gm->key_pressed) == sfFalse) {
        player->rect.top = player->direction * (player->size.y / 4);
        player->rect.left = 0;
    } else {
        set_direction_and_top(gm, player);
        if (time >= framerate) {
            set_left(player, time, framerate);
            sfClock_restart(player->clock_anim);
        }
    }
}