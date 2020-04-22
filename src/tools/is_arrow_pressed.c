/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** Is an arrow pressed
*/

#include "header.h"

sfBool is_arrow_pressed(char *key_pressed)
{
    if (my_strcmp(key_pressed, "down") == 0)
        return sfTrue;
    if (my_strcmp(key_pressed, "up") == 0)
        return sfTrue;
    if (my_strcmp(key_pressed, "right") == 0)
        return sfTrue;
    if (my_strcmp(key_pressed, "left") == 0)
        return sfTrue;
    return sfFalse;
}