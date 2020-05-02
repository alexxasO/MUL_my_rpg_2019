/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Set Npc
*/

#include "header.h"

static char *get_random_npc_pathname(void)
{
    char *pathnames[] = {"image/npc/grey.png",
    "image/npc/void.png", "image/npc/silios.png",
    "image/npc/sharp.png", "image/npc/sarah.png",
    "image/npc/ralem.png", "image/npc/rarrior.png",
    "image/npc/nig.png", "image/npc/liam.png",
    "image/npc/ian.png", "image/npc/guard.png",
    "image/npc/klive.png", "image/npc/blouik.png",
    "image/npc/alexia.png", "image/npc/achille.png"};

    return pathnames[random_int(15)];
}

void set_npc(player_t **players, background_t *background)
{
    sfVector2f pos = (sfVector2f){-1, -1};

    for (size_t i = 1; i < 3; i++) {
        if (players[i] != NULL) {
            destroy_player(players[i]);
            players[i] = NULL;
        }
        while (pos.x == -1)
            pos = get_random_pos();
        players[i] = create_player(get_random_npc_pathname(),
        pos, NULL, NULL);
        players[i]->pos.x += background->pos.x - players[i]->rect.width / 2;
        players[i]->pos.y += background->pos.y - players[i]->rect.height;
        pos = (sfVector2f){-1, -1};
    }
}