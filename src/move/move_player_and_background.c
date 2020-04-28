/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Move player and background
*/

#include "header.h"

static sfBool check_limit(sfImage *limit, player_t *player, float *add,
background_t *background)
{
    unsigned int x = 0;
    unsigned int y = 0;
    float xf = player->pos.x + add[0] + (player->rect.width / 2);
    float yf = player->pos.y + add[1] + player->rect.height;
    sfColor px_color;

    if (xf < 0 || xf > 1920 || yf < 0 || yf > 1080)
        return sfFalse;
    x = xf + (background->pos.x * -1);
    y = yf + (background->pos.y * -1);
    px_color = sfImage_getPixel(limit, x, y);
    if (px_color.r != sfWhite.r && px_color.g != sfWhite.g &&
    px_color.b != sfWhite.b)
        return sfFalse;
    return sfTrue;
}

static float *get_add_value(float *add, float time, size_t i)
{
    float framerate = 0.01;
    const float coef[] = {0, 5, 0, -5, 5, 0, -5, 0};

    add[0] = coef[i * 2] * time / framerate;
    add[1] = coef[i * 2 + 1] * time / framerate;
    return add;
}

static sfBool check_side(size_t i, sfVector2f p_pos)
{
    if (p_pos.x < 200 && i == 3)
        return sfTrue;
    if (p_pos.x > 1720 && i == 2)
        return sfTrue;
    if (p_pos.y < 200 && i == 1)
        return sfTrue;
    if (p_pos.y > 880 && i == 0)
        return sfTrue;
    return sfFalse;
}

static void move_background(player_t *player, background_t *background,
float *add, size_t i)
{
    sfVector2f p_pos = player->pos;
    sfVector2f b_pos = background->pos;

    if (check_side(i, p_pos) == sfTrue) {
        if (b_pos.x - add[0] > -1152 && b_pos.x - add[0] < 0) {
            background->pos.x -= add[0];
            player->pos.x -= add[0];
        }
        if (b_pos.y - add[1] > -1992 && b_pos.y - add[1] < 0) {
            background->pos.y -= add[1];
            player->pos.y -= add[1];
        }
    }
}

void move_player_and_background(game_manager_t *gm, player_t *player,
background_t *background)
{
    float time = sfTime_asSeconds(sfClock_getElapsedTime(player->clock_move));
    const char *keys[] = {"down", "up", "right", "left"};
    sfImage *limit = sfImage_createFromFile("image/other/level_limit2.png");
    float *add = malloc(sizeof(float) * 2);

    for (size_t i = 0; i < 4; i++) {
        add = get_add_value(add, time, i);
        if (my_strcmp(gm->key_pressed, keys[i]) == 0
        && check_limit(limit, player, add, background) == sfTrue) {
            player->pos.x += add[0];
            player->pos.y += add[1];
            move_background(player, background, add, i);
        }
    }
    sfClock_restart(player->clock_move);
    sfImage_destroy(limit);
    free(add);
}