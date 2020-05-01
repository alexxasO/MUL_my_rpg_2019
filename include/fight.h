/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** fight.h
*/

#include "header.h"

#if !defined(FIGHT)
#define FIGHT

typedef struct infobar
{
    enum modes {DEFAULT, ATTACK, ITEM} mode;
    sfSprite **sprites;
    sfText **texts;
} infobar_t;


#endif // FIGHT