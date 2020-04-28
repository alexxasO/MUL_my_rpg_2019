/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** Draw the text
*/

#include "header.h"

void draw_text(game_manager_t *gm, scene_t *scene)
{
    text_t *text = NULL;

    if (scene->texts != NULL) {
        for (size_t i = 0; scene->texts[i]; i++) {
            text = scene->texts[i];
            sfText_setFont(text->text, text->font);
            sfText_setCharacterSize(text->text, text->size);
            sfText_setColor(text->text, text->color);
            sfText_setString(text->text, text->string);
            sfText_setPosition(text->text, text->pos);
            sfRenderWindow_drawText(gm->window, text->text, sfFalse);
        }
    }
}