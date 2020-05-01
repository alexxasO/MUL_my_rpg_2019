/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Inventory and Status Text
*/

#include "header.h"

text_t **inventory_and_status_text(void)
{
    text_t **texts = malloc(sizeof(text_t *) * 5);

    for (size_t i = 0; i < 4; i++) {
        texts[i] = create_text("", 30, sfBlack,
        (sfVector2f){1700, 345 + i * 193});
    }
    texts[4] = NULL;
    return texts;
}