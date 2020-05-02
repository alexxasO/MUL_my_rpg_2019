/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Destroy text
*/

#include "header.h"

void destroy_text(text_t *text)
{
    sfFont_destroy(text->font);
    sfText_destroy(text->text);
    free(text->string);
    free(text);
}
