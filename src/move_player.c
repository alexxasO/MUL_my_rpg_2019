/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Move player
*/

#include "header.h"

static sfBool check_limit(sfImage *limit, player_t *player, float add_x, float add_y)
{   
    sfVector2f player_pos = (sfVector2f){player->pos.x + add_x, player->pos.y + add_y};
    sfColor px_color;
    sfVector2u size = sfImage_getSize(limit);

    if (player_pos.x < 0 || player_pos.x > 1000 || player_pos.y < 0 || player_pos.y > 1000)
        return sfFalse;
    px_color = sfImage_getPixel(limit, player_pos.x, player_pos.x);
    printf("R = %d\n", px_color.r);
    printf("G = %d\n", px_color.g);
    printf("B = %d\n", px_color.b);
    printf("X = %f && Y = %f\n", player->pos.x, player->pos.y);
    printf("SX = %u && SY = %u\n", size.x, size.y);
    if (px_color.r != sfWhite.r && px_color.g != sfWhite.g && px_color.b != sfWhite.b)
        return sfFalse;
    return sfTrue;
}

void move_player(game_manager_t *gm, player_t *player)
{
    float time = sfTime_asSeconds(sfClock_getElapsedTime(player->clock_move));
    const char *keys[] = {"down", "up", "right", "left"};
    float framerate = 0.007;
    const float coef[] = {0, 1, 0, -1, 1, 0, -1, 0};
    sfImage *limit = sfImage_createFromFile("image/other/level_limit.png");

    for (size_t i = 0; i < 4; i++) {
        if (my_strcmp(gm->key_pressed, keys[i]) == 0
        && check_limit(limit, player, coef[i * 2] * time / framerate,
        coef[i * 2 + 1] * time / framerate) == sfFalse) {
            player->pos.x += coef[i * 2] * time / framerate;
            player->pos.y += coef[i * 2 + 1] * time / framerate;
        }
    }
    sfClock_restart(player->clock_move);
}