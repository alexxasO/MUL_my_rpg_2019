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
    const float coef[] = {0, 8, 0, -8, 8, 0, -8, 0};

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

static void move_background(game_manager_t *gm, background_t *background,
float *add, size_t i)
{
    player_t **players = gm->scenes[gm->scene_id]->players;
    enemy_t **enemies = gm->scenes[gm->scene_id]->enemies;
    sfVector2f p_pos = players[0]->pos;
    sfVector2f b_pos = background->pos;

    if (check_side(i, p_pos) == sfTrue) {
        if (b_pos.x - add[0] > -384 && b_pos.x - add[0] < 0) {
            background->pos.x -= add[0];
            players[0]->pos.x -= add[0];
            move_npc_and_enemy(players, add[0], 0, enemies);
        }
        if (b_pos.y - add[1] > -1224 && b_pos.y - add[1] < 0) {
            background->pos.y -= add[1];
            players[0]->pos.y -= add[1];
            move_npc_and_enemy(players, 0, add[1], enemies);
        }
    }
}

void move_all(game_manager_t *gm, player_t **players,
background_t *background)
{
    float time = sfTime_asSeconds(sfClock_getElapsedTime(
    players[0]->clock_move));
    const char *keys[] = {"down", "up", "right", "left"};
    sfImage *limit = sfImage_createFromFile("image/other/level_limit.png");
    float *add = malloc(sizeof(float) * 2);

    for (size_t i = 0; i < 4; i++) {
        add = get_add_value(add, time, i);
        if (my_strcmp(gm->key_pressed, keys[i]) == 0
        && check_limit(limit, players[0], add, background) == sfTrue) {
            players[0]->pos.x += add[0];
            players[0]->pos.y += add[1];
            move_background(gm, background, add, i);
        }
    }
    sfClock_restart(players[0]->clock_move);
    sfImage_destroy(limit);
    free(add);
}