/*
** EPITECH PROJECT, 2020
** check_inventory.c
** File description:
** check inventory to change stats
*/

#include "header.h"

void buff_stat(int item, player_t *player)
{
    if (item == 0 || item == 1)
        player->attack.dmg += 5;
    if (item == 2 || item == 3)
        player->attack.speed_dmg += 3;
    if (item == 4 || item == 5)
        player->defense.dmg += 10;
    if (item == 6 || item == 7)
        player->attack.dmg += 15;
    if (item == 8 || item == 9)
        player->attack.speed_dmg += 10;
}

void lower_stat(int item, player_t *player)
{
    if (item == 0 || item == 1)
        player->attack.dmg -= 5;
    if (item == 2 || item == 3)
        player->attack.speed_dmg -= 3;
    if (item == 4 || item == 5)
        player->defense.dmg -= 10;
    if (item == 6 || item == 7)
        player->attack.dmg -= 15;
    if (item == 8 || item == 9)
        player->attack.speed_dmg -= 10;
}

void update_inventory(save_t *save, player_t *player)
{
    for (int i = 0; inventory[i]; i++) {
        if (save->inventory[i] == 3) {
            add_stat(i, player);
            save->inventory[i] = 1;
        }
        if (save->inventory[i] == 4) {
            lower_stat(i, player);
            save->inventory[i] = 1;
        }
    }
}
