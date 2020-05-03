/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** objects.c
*/

#include "fight.h"

void attack_fighter(fighter_info_t *attacker, fighter_info_t *victim,
attack_t *attack)
{
    printf("attack_dmg : %d dmgmod : %d\n", attack->dmg, attacker->damage_mod);
    victim->life = victim->life - (attack->dmg + attacker->damage_mod);
    victim->defense_mod = victim->defense_mod - attack->defense_dmg;
    victim->damage_mod = victim->damage_mod - attack->damage_dmg;
}