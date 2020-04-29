/*
** EPITECH PROJECT, 2020
** name.c
** File description:
** choose your name
*/

#include "header.h"

extern int letter = 0;

void name(save_t *save, sfEvent *event)
{
    int key_id = event.key.code;
    char key = key_id + 'A';

    /* fonction qui display la lettre avec un int donné pour la position; */
    /* display_letter(key, letter); */
    save->name[letter] = key;
    letter++;
}
