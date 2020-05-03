/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** fight_scene.c
*/

#include "header.h"

static int end_fight(player_t **players, enemy_t **enemies)
{
    int nb_ply = count_players(players);
    int nb_eny = count_enemies(enemies);
    int count = 0;

    for (int i = 0; players[i]; i++) {
        if (players[i]->life <= 0)
            count++;
    }
    if (count >= nb_ply)
        return -1;
    count = 0;
    for (int i = 0; enemies[i]; i++) {
        if (enemies[i]->life <= 0)
            count++;
    }
    if (count >= nb_eny)
        return 1;
    return 0;
}

static void enemy_turn(enemy_t **enemies, player_t **players,
UN game_manager_t *gm, int nb_ply)
{
    int ply_id = 0;
    int attack_id = 0;

    for (int i = 0; enemies[i]; i++) {
        ply_id = random_int(nb_ply);
        attack_id = random_int(4);
        attack_fighter(enemies[i]->fighter_info, players[ply_id]->fighter_info,
        enemies[i]->fighter_info->attacks[attack_id]);
    }
}

static void win_func(game_manager_t *gm)
{
    int nb = random_int(12);

    gm->saves[gm->save_id]->exp = gm->saves[gm->save_id]->exp + 10;
    if (gm->saves[gm->save_id]->exp > 100) {
        gm->saves[gm->save_id]->exp = 0;
        gm->saves[gm->save_id]->level = gm->saves[gm->save_id]->level + 1;
    }
    if (!my_strcmp(gm->scenes[gm->scene_id]->music_pathname,
    "music/boss_music.ogg"))
    gm->saves[gm->save_id]->stage = gm->saves[gm->save_id]->stage + 1;
    if (gm->saves[gm->save_id]->inventory[nb] == 0)
        gm->saves[gm->save_id]->inventory[nb] = 1;
    game_callback(gm);
}

void begin_fight(player_t **players, enemy_t **enemies, game_manager_t *gm)
{
    int nb_player = count_players(players);
    int nb_enemy = count_enemies(enemies);
    static int turn = 0;
    int win = 0;

    if (turn >= nb_player) {
        turn = 0;
        enemy_turn(enemies, players, gm, nb_player);
    }
    place_player(players, nb_player);
    place_enemies(enemies, nb_enemy);
    place_infobar_texts(players, enemies, gm);
    create_info_bar(gm, gm->fight_bar, &turn);
    win = end_fight(players, enemies);
    if (win == 1) {
        win_func(gm);
    } else if (win == -1)
        gm->scene_id = START_MENU_ID;
}