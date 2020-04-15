/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** Draw the scene
*/

#include "header.h"

static void draw_backgrounds(game_manager_t *gm, scene_t *scene)
{
    sfSprite *sprite = NULL;

    if (scene->backgrounds != NULL) {
        for (size_t i = 0; scene->backgrounds[i]; i++) {
            sprite = scene->backgrounds[i]->sprite;
            sfRenderWindow_drawSprite(gm->window, sprite, NULL);
        }
    }
}

static void draw_players(game_manager_t *gm, scene_t *scene)
{
    sfSprite *sprite = NULL;
    sfIntRect rect;

    if (scene->players != NULL) {
        for (size_t i = 0; scene->players[i]; i++) {
            sprite = scene->players[i]->sprite;
            rect = scene->players[i]->rect;
            sfSprite_setTextureRect(sprite, rect);
            sfRenderWindow_drawSprite(gm->window, sprite, NULL);
        }
    }
}

static void draw_enemies(game_manager_t *gm, scene_t *scene)
{
    sfSprite *sprite = NULL;

    if (scene->enemies != NULL) {
        for (size_t i = 0; scene->enemies[i]; i++) {
            sprite = scene->enemies[i]->sprite;
            sfRenderWindow_drawSprite(gm->window, sprite, NULL);
        }
    }
}

void draw_scene(game_manager_t *gm, scene_t *scene)
{
    draw_backgrounds(gm, scene);
    draw_players(gm, scene);
    draw_enemies(gm, scene);
    sfRenderWindow_display(gm->window);
    sfRenderWindow_clear(gm->window, sfBlack);
}