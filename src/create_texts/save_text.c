/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Save Text
*/

#include "header.h"

text_t **save_text(void)
{
    text_t **texts = malloc(sizeof(text_t *) * 10);

    for (size_t i = 0; i < 3; i++) {
        texts[i * 3] = create_text("", 30, sfBlack,
        (sfVector2f){400, 170 + i * 300});
        texts[i * 3 + 1] = create_text("", 100, sfBlack,
        (sfVector2f){760, 200 + i * 300});
        texts[i * 3 + 2] = create_text("", 100, sfBlack,
        (sfVector2f){1180, 200 + i * 300});
    }
    texts[9] = NULL;
    return texts;
}