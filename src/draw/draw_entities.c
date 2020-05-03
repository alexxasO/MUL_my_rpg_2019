/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** Draw entities
*/

#include "header.h"

static void draw_player(game_manager_t *gm, scene_t *scene, size_t i)
{
    sfSprite *sprite = scene->players[i]->sprite;
    sfIntRect rect = scene->players[i]->rect;
    sfVector2f pos = scene->players[i]->pos;

    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(gm->window, sprite, NULL);
}

static void draw_players(game_manager_t *gm, scene_t *scene)
{
    if (scene->players == NULL || scene->players[0] == NULL)
        return;
    if (scene->players[1] != NULL) {
        for (size_t i = 1; scene->players[i]; i++) {
            draw_player(gm, scene, i);
        }
    }
}

static void draw_enemies(game_manager_t *gm, scene_t *scene)
{
    sfSprite *sprite = NULL;
    sfIntRect rect;
    sfVector2f pos;

    if (scene->enemies == NULL)
        return;
    for (size_t i = 0; scene->enemies[i]; i++) {
        sprite = scene->enemies[i]->sprite;
        pos = scene->enemies[i]->pos;
        rect = scene->enemies[i]->rect;
        sfSprite_setTextureRect(sprite, rect);
        sfSprite_setPosition(sprite, pos);
        sfRenderWindow_drawSprite(gm->window, sprite, NULL);
    }
}

void draw_entities(game_manager_t *gm, scene_t *scene)
{
    draw_players(gm, scene);
    draw_enemies(gm, scene);
    if (scene->players[0] != NULL)
        draw_player(gm, scene, 0);
}