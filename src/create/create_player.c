/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Create player
*/

#include "header.h"

player_t *create_player(char *pathname, sfVector2f pos,
void (*ptr_move) (struct player_s *, sfVector2f),
void (*ptr_anim) (struct player_s *, sfRenderWindow *))
{
    player_t *player = malloc(sizeof(player_t));

    player->pathname = pathname;
    player->texture = sfTexture_createFromFile(player->pathname, NULL);
    player->sprite = sfSprite_create();
    sfSprite_setTexture(player->sprite, player->texture, sfFalse);
    player->pos = pos;
    player->size = sfTexture_getSize(sfSprite_getTexture(player->sprite));
    player->rect = (sfIntRect){0, 0, player->size.x, player->size.y};
    player->clock = sfClock_create();
    player->ptr_move = ptr_move;
    player->ptr_anim = ptr_anim;
    player->sound = NULL;
    return player;
}