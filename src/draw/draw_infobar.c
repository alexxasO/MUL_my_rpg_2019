/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_infobar.c
*/

#include "header.h"

static void draw_infobar_text(game_manager_t *gm, infobar_t *infobar)
{
    sfText *text = NULL;

    if (infobar->texts != NULL) {
        for (int i = 0; infobar->texts[i]; i++) {
            text = infobar->texts[i];
            sfRenderWindow_drawText(gm->window, text, NULL);
        }
    }
}

void draw_infobar(game_manager_t *gm, scene_t *scene)
{
    sfSprite *sprite = NULL;

    if (gm->fight_bar && gm->fight_bar->sprites) {
        for (int i = 0; gm->fight_bar->sprites[i]; i++) {
            sprite = gm->fight_bar->sprites[i];
            sfRenderWindow_drawSprite(gm->window, sprite, NULL);
        }
    }
    draw_infobar_text(gm, gm->fight_bar);
}