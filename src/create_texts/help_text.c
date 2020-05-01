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
        "You will need to fight monsters\n"\
        "in each stage, to loot items which will\n"\
        "make you stronger by leveling you up.\n"\
        "To get to the next floor you'll need to \n"\
        "fight against the floor boss and win\n"\
        "be careful tho, he will be stronger than\n"\
        "the other monsters.\n"\
        "Move around by using the arrow keys, use\n"\
        "the F key to interact with other people\n"\
        "The I key is to open your inventory and\n"\
        "check your game status, \n"\
        "there, click on any item to equip it.\n"\
        "Fights will start when you touch a\n"\
        "monster.\n"\
        "Good luck and good game !\n";

    texts[0] = create_text(string, 30, sfBlack,
                           (sfVector2f){390, 120});
    texts[1] = NULL;
    return texts;
}
