/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** fight.h
*/

#include "header.h"

#if !defined(FIGHT)
#define FIGHT

typedef struct attack {
    int dmg;
    int speed_dmg;
    int defense_dmg;
    int damage_dmg;
    //anim ?
} attack_t;

typedef struct ally_info {
    sfSprite *sprite;
    sfTexture *texture;
    bool is_enemy;
    char *path_to_spritesheet;
    int life;
    attack_t *attacks;
    //ptr anim
    //attack anim
    //idle anim
    //death/dead anim
    int speed;
    int damage_mod;
    int defense_mod;
    int speed_mod;
} fighter_info_t;

typedef struct player_object {
    bool is_attack;
    int life_effect;
    int damage_boost;
    int defense_boost;
    int speed_boost;
} inv_object_t;

#endif // FIGHT