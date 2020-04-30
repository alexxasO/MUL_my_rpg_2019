/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** New Text
*/

#include "header.h"

text_t **new_text(void)
{
    text_t **texts = malloc(sizeof(text_t *) * 2);

    texts[0] = create_text("", 100, sfBlack,
    (sfVector2f){350, 340});
    texts[1] = NULL;
    return texts;
}