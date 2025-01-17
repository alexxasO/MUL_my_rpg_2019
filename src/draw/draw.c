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
    sfVector2f pos;

    if (scene->backgrounds != NULL) {
        for (size_t i = 0; scene->backgrounds[i]; i++) {
            sprite = scene->backgrounds[i]->sprite;
            pos = scene->backgrounds[i]->pos;
            sfSprite_setPosition(sprite, pos);
            sfRenderWindow_drawSprite(gm->window, sprite, NULL);
        }
    }
}

static void draw_buttons(game_manager_t *gm, scene_t *scene)
{
    sfSprite *sprite = NULL;
    int state = -1;
    sfVector2f pos;

    if (scene->buttons != NULL) {
        for (size_t i = 0; scene->buttons[i]; i++) {
            state = scene->buttons[i]->state;
            sprite = scene->buttons[i]->sprite[state];
            pos = scene->buttons[i]->pos;
            sfSprite_setPosition(sprite, pos);
            sfRenderWindow_drawSprite(gm->window, sprite, NULL);
        }
    }
}

static void draw_sftext(game_manager_t *gm, scene_t *scene)
{
    sfText *text = NULL;

    if (scene->sftexts != NULL) {
        for (size_t i = 0; scene->sftexts[i]; i++) {
            text = scene->sftexts[i];
            sfRenderWindow_drawText(gm->window, text, NULL);
        }
    }
}

void draw_scene(game_manager_t *gm, scene_t *scene)
{
    draw_backgrounds(gm, scene);
    draw_entities(gm, scene);
    draw_buttons(gm, scene);
    draw_text(gm, scene);
    draw_infobar(gm, scene);
    draw_sftext(gm, scene);
    sfRenderWindow_display(gm->window);
    sfRenderWindow_clear(gm->window, sfBlack);
}
