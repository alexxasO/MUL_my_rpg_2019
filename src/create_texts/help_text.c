/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Help Text
*/

#include "header.h"

text_t **help_text(void)
{
    text_t **texts = malloc(sizeof(text_t *) * 2);
    char string[] = "Welcome to The Tower, your objective is\n"\
    "to reach the last floor of The Tower.\n"\
    "For that, you will have to fight monsters\n"\
    "in each stage, to loot items which will\n"\
    "make you stronger and level-up.\n"\
    "Be careful, they will be also one boss\n"\
    "who you need to beat for go to the next\n"\
    "level, but he will be stronger than the\n"\
    "other monsters.\n"\
    "Move around by using the arrow keys, use\n"\
    "the F key to interact with other people\n"\
    "and the I key for see your status and\n"\
    "choose the item in your inventory you\n"\
    "want to use by clicking on them. Also,\n"\
    "fight will start when you will touch the\n"\
    "monsters.\n"\
    "Good luck and good game !\n";
 
    texts[0] = create_text(string, 30, sfBlack,
    (sfVector2f){390, 120});
    texts[1] = NULL;
    return texts;
}