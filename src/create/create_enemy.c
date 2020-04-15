/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Create enemy
*/

#include "header.h"

enemy_t *create_enemy(char *pathname, sfVector2f pos,
void (*ptr_move) (struct enemy_s *, sfVector2f),
void (*ptr_anim) (struct enemy_s *, sfRenderWindow *))
{
    enemy_t *enemy = malloc(sizeof(enemy_t));

    enemy->pathname = pathname;
    enemy->texture = sfTexture_createFromFile(enemy->pathname, NULL);
    enemy->sprite = sfSprite_create();
    sfSprite_setTexture(enemy->sprite, enemy->texture, sfFalse);
    enemy->pos = pos;
    enemy->size = sfTexture_getSize(sfSprite_getTexture(enemy->sprite));
    enemy->rect = (sfIntRect){0, 0, enemy->size.x, enemy->size.y};
    enemy->clock = sfClock_create();
    enemy->ptr_move = ptr_move;
    enemy->ptr_anim = ptr_anim;
    enemy->origin = (sfVector2f){0, 0};
    enemy->sound = NULL;
    enemy->damage = -1;
    enemy->speed = -1;
    enemy->life = -1;
    return enemy;
}