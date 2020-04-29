/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** objects.c
*/

#include "fight.h"

void apply_objects_effect(inv_object_t *obj, fighter_info_t *fighter)
{
    fighter->life = fighter->life + obj->life_effect;
    fighter->speed_mod = fighter->speed_mod + obj->speed_boost;
    fighter->defense_mod = fighter->defense_mod + obj->defense_boost;
    fighter->damage_mod = fighter->damage_mod + obj->damage_boost;
}

void attack_fighter(fighter_info_t *attacker, fighter_info_t *victim,
attack_t *attack)
{
    victim->life = victim->life - (attack->dmg + attacker->damage_mod);
    victim->speed_mod = victim->speed_mod - attack->speed_dmg;
    victim->defense_mod = victim->defense_mod - attack->defense_dmg;
    victim->damage_mod = victim->damage_mod - attack->damage_dmg;
}