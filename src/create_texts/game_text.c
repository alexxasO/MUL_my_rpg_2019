/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Game Text
*/

#include "header.h"

text_t **game_text(void)
{
    text_t **texts = malloc(sizeof(text_t *) * 2);

    texts[0] = create_text("", 15, sfWhite,
    (sfVector2f){1000, 950});
    texts[1] = NULL;
    return texts;
}