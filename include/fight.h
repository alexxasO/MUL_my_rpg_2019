/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** fight.h
*/

#include "header.h"

#if !defined(FIGHT)
#define FIGHT

typedef struct attack attack_t;

typedef struct infobar
{
    enum modes {DEFAULT, ATTACK, SELECTOR} mode;
    sfSprite **sprites;
    sfText **texts;
    attack_t *attack_selected;
} infobar_t;


#endif // FIGHT