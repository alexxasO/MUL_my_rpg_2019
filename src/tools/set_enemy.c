/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Set Npc
*/

#include "header.h"

static char *get_random_enemy_pathname(size_t i)
{
    char *pathnames[] = {"image/enemy/zombie.png",
    "image/enemy/no_head.png", "image/enemy/watcher.png",
    "image/enemy/tricarn.png", "image/enemy/grounder.png",
    "image/enemy/darkelion.png", "image/enemy/dark_agent.png",
    "image/enemy/bloubi_violet.png", "image/enemy/bloubi_vert.png",
    "image/enemy/bloubi_rouge.png", "image/enemy/bloubi_rose.png",
    "image/enemy/bloubi_orange.png", "image/enemy/bloubi_marron.png",
    "image/enemy/bloubi_jaune.png", "image/enemy/bloubi_bleu.png"};
    char *boss_pathname[] = {"image/enemy/bloubi_ultima_"\
    "magica_perfecta_lumina.png"};

    if (i != 5)
        return pathnames[random_int(15)];
    return boss_pathname[0];
}

void set_enemy(enemy_t **enemies, background_t *background)
{
    sfVector2f pos = (sfVector2f){-1, -1};

    for (size_t i = 0; i < 6; i++) {
        if (enemies[i] != NULL) {
            destroy_enemy(enemies[i]);
            enemies[i] = NULL;
        }
        while (pos.x == -1)
            pos = get_random_pos();
        if (i == 5)
            pos = (sfVector2f){2000, 1400};
        enemies[i] = create_enemy(get_random_enemy_pathname(i),
        pos, NULL, NULL);
        enemies[i]->pos.x += background->pos.x - enemies[i]->rect.width / 2;
        enemies[i]->pos.y += background->pos.y - enemies[i]->rect.height;
        pos = (sfVector2f){-1, -1};
    }
}