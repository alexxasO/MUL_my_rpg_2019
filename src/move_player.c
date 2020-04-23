/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Move player
*/

#include "header.h"

static sfBool check_limit(sfImage *limit, player_t *player, float add_x, float add_y)
{   
    unsigned int x = 0;
    unsigned int y = 0;
    float xf = player->pos.x + add_x + (player->rect.width / 2);
    float yf = player->pos.y + add_y + player->rect.height;
    sfColor px_color;

    if (xf < 0 || xf > 1000 || yf < 0 || yf > 1000)
        return sfTrue;
    x = xf;
    y = yf;
    px_color = sfImage_getPixel(limit, x, y);
    if (px_color.r != sfWhite.r && px_color.g != sfWhite.g && px_color.b != sfWhite.b)
        return sfTrue;
    return sfFalse;
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
    sfImage_destroy(limit);
}