/*
** EPITECH PROJECT, 2020
** spawn_NPC.c
** File description:
** spawn an NPC and add coordinates to collisions
*/

#include "header.h"

npc_t **create_npc(char *pathname, sfVector2f pos,
                        void (*ptr_move) (struct npc_s *, sfVector2f),
                        void (*ptr_anim) (struct npc_s *, sfRenderWindow *))
{
    npc_t *npc = malloc(sizeof(npc_t));

    npc->pathname = pathname;
    npc->texture = sfTexture_createFromFile(npc->pathname, NULL);
    npc->sprite = sfSprite_create();
    sfSprite_setTexture(npc->sprite, npc->texture, sfFalse);
    npc->pos = pos;
    npc->size = sfTexture_getSize(sfSprite_getTexture(npc->sprite));
    npc->rect = (sfIntRect){0, 0, npc->size.x, npc->size.y};
    npc->clock_move = sfClock_create();
    npc->clock_anim = sfClock_create();
    npc->ptr_move = ptr_move;
    npc->ptr_anim = ptr_anim;
    npc->sound = NULL;
    return npc;
}

npc_t **new_npc(char *sprite_path, int x, int y)
{
    npc_t **npc = malloc(sizeof(npc_t *));

    npc[0] = create_npc(sprite_path, (sfVector2f){x, y}, NULL, NULL);
    npc[0]->rect = (sfIntRect){0, 0, npc[0]->size.x / 7, npc[0]->size.y / 4};
    npc[1] = NULL;
    return npc;
}

void spawn_npc(game_manager_t *gm, scene_t *scene, char *sprite_path)
{
    npc_t **npc = launch_npc(sprite_path);
    sfIntRect rect;
    int x = random_int(1200);
    int y = random_int(800);
    sfVector2f pos = {x, y};

    if (scene->npcs != NULL) {
        for (size_t i = 0; scene->npcs[i]; i++) {
            sprite = scene->npcs[i]->sprite;
            rect = scene->npcs[i]->rect;
            pos = scene->npcs[i]->pos;
            sfSprite_setTextureRect(sprite, rect);
            sfSprite_setPosition(sprite, pos);
            sfRenderWindow_drawSprite(gm->window, sprite, NULL);
        }
    }
}
