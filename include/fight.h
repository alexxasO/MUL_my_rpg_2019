/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** fight.h
*/

typedef struct attack {
    int dmg;
    //anim ?
} attack_t;

typedef struct enemy_info {
    char *path_to_spritesheet;
    int life;
    attack_t *attacks;
    //attack anim
    //idle
};