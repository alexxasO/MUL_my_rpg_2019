/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** fight.c
*/

#include "fight.h"

void fight_func(game_manager_t *gm)
{
    scene_t *scene = gm->scenes[gm->scene_id];
}

int count_fighters(fighter_info_t **fighters)
{
    int i = 0;

    while(fighters[i]) {
        i++;
    }
    return i;
}

void begin_fight(fighter_info_t **fighters, char *path_to_bckgnd)
{
    int nb_player = count_fighters(fighters);
    int turn = 0;
}

background_t **save_background(void)
{
    background_t **backgrounds = malloc(sizeof(background_t *) * 2);

    backgrounds[0] = create_background("image/background/fight_background.png",
    (sfVector2f){0, 0}, NULL);
    backgrounds[1] = NULL;
    return backgrounds;
}