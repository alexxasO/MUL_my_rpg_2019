/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** fight.h
*/

#include "header.h"

#if !defined(FIGHT)
#define FIGHT

typedef struct menubar
{
    enum modes {DEFAULT, ATTACK, ITEM} mode;
} menubar_t;

typedef struct infobar
{
    menubar_t *menu;
    sfSprite **sprites;
    sfText **texts;
} infobar_t;


#endif // FIGHT