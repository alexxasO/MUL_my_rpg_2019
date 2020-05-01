/*
** EPITECH PROJECT, 2020
** create_inventory.c
** File description:
** create the inventory in struct save
*/

#include "header.h"

void create_inventory(save_t *save)
{
    for (int i = 0; save->inventory[i]; i++)
        save->inventory[i] = 0;
}
