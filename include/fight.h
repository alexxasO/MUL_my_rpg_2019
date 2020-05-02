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
    player_t **players;
    menubar_t *menu;
    enemy_t **enemies;
} infobar_t;


#endif // FIGHT