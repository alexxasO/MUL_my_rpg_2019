/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** menu_selector.c
*/

#include "header.h"

static int count_texts_info(infobar_t *inf)
{
    int i = 0;

    for (; inf->texts[i]; i++);
    return i;
}

void change_selector_up(infobar_t *infobar)
{
    sfVector2f arrow_pos = sfSprite_getPosition(infobar->sprites[1]);
    int selected_id = 0;

    for (int i = 0; infobar->texts[i]; i++) {
        if (sfText_getPosition(infobar->texts[i]).y == arrow_pos.y + 15)
            selected_id = i;
    }
    if (selected_id > 0)
        arrow_pos.y = arrow_pos.y - 25;
    sfSprite_setPosition(infobar->sprites[1], arrow_pos);
}

void change_selector_down(infobar_t *infobar)
{
    sfVector2f arrow_pos = sfSprite_getPosition(infobar->sprites[1]);
    int selected_id = 0;

    for (int i = 0; infobar->texts[i]; i++) {
        if (sfText_getPosition(infobar->texts[i]).y == arrow_pos.y + 15)
            selected_id = i;
    }
    if (selected_id < count_texts_info(infobar) - 1)
        arrow_pos.y = arrow_pos.y + 25;
    sfSprite_setPosition(infobar->sprites[1], arrow_pos);
}