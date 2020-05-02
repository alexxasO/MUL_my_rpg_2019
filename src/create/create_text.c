/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Create text
*/

#include "header.h"

text_t *create_text(char *string, size_t size, sfColor color,
sfVector2f pos)
{
    text_t *text = malloc(sizeof(text_t));

    text->string = my_strdup(string);
    text->text = sfText_create();
    text->font = sfFont_createFromFile("font/Astrolab.ttf");
    text->size = size;
    text->color = color;
    text->pos = pos;
    return text;
}
