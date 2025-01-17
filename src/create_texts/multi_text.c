/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Multi Text
*/

#include "header.h"

text_t **multi_text(void)
{
    text_t **texts = malloc(sizeof(text_t *) * 2);

    texts[0] = create_text("", 100, sfBlack, (sfVector2f){350, 340});
    texts[1] = NULL;
    return texts;
}

text_t **ip_text(void)
{
    text_t **texts = malloc(sizeof(text_t *) * 3);

    texts[0] = create_text(IP_SERV, 100, sfBlack, (sfVector2f){350, 340});
    texts[1] = create_text("", 50, sfBlack, (sfVector2f){400, 800});
    texts[2] = NULL;
    return texts;
}

text_t **chat_text(void)
{
    text_t **texts = malloc(sizeof(text_t *) * 3);

    texts[0] = create_text("", 100, sfBlack, (sfVector2f){350, 340});
    texts[1] = create_text("", 50, sfBlack, (sfVector2f){350, 500});
    texts[2] = NULL;
    return texts;
}