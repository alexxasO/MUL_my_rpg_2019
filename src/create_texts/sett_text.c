/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Sett Text
*/

#include "header.h"

text_t **sett_text(void)
{
    text_t **texts = malloc(sizeof(text_t *) * 2);

    texts[0] = create_text("", 100, sfBlack, (sfVector2f){1200, 340});
    texts[1] = NULL;
    return texts;
}