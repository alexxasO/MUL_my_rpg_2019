/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Setup fight
*/

#include "header.h"

static void setup_music(game_manager_t *gm, int enemy_id)
{
    scene_t *scene = gm->scenes[gm->scene_id];
    char boss_music[] = "music/boss_music.ogg";
    char fight_music[] = "music/fight_music.ogg";

    if (enemy_id == 5 && my_strcmp(scene->music_pathname, boss_music) != 0) {
        if (sfMusic_getStatus(scene->music) != sfStopped)
            sfMusic_stop(scene->music);
        sfMusic_destroy(scene->music);
        scene->music = sfMusic_createFromFile(boss_music);
        scene->music_pathname = my_strdup(boss_music);
        sfMusic_setLoop(scene->music, sfTrue);
    } else if (enemy_id == 5 &&
    my_strcmp(scene->music_pathname, fight_music) != 0) {
        if (sfMusic_getStatus(scene->music) != sfStopped)
            sfMusic_stop(scene->music);
        sfMusic_destroy(scene->music);
        scene->music = sfMusic_createFromFile(fight_music);
        scene->music_pathname = my_strdup(fight_music);
        sfMusic_setLoop(scene->music, sfTrue);
    }
}

static attack_t **setup_attack(void)
{
    attack_t **attacks = malloc(sizeof(attack_t *) * 4);
    int dmg[] = {10, 0, 0, 0};
    int damage_dmg[] = {0, 10, 0, -5};
    int defense_dmg[] = {0, 0, 10, -5};
    char *attack_name[] = {"Punch", "Big eye", "Analyse", "Boost"};

    for (size_t i = 0; i < 4; i++) {
        attacks[i] = malloc(sizeof(attack_t));
        attacks[i]->dmg = dmg[i];
        attacks[i]->damage_dmg = damage_dmg[i];
        attacks[i]->defense_dmg = defense_dmg[i];
        attacks[i]->path_to_icon = NULL;
        attacks[i]->name = attack_name[i];
    }
    return attacks;
}

static void setup_player(game_manager_t *gm)
{
    player_t **players = gm->scenes[GAME_ID]->players;
    player_t **fplayers = gm->scenes[gm->scene_id]->players;

    for (size_t i = 0; i < 1; i++) {
        fplayers[i] = create_player(players[i]->pathname,
        (sfVector2f){100, 500}, NULL, NULL);
        fplayers[i]->rect = (sfIntRect){0, 0, fplayers[i]->size.x / 7,
        fplayers[i]->size.y / 4};
        fplayers[i]->fighter_info->sprite = players[i]->sprite;
        fplayers[i]->fighter_info->texture = players[i]->texture;
        fplayers[i]->fighter_info->life = players[i]->life;
        fplayers[i]->fighter_info->path_to_spritesheet = players[i]->pathname;
        fplayers[i]->fighter_info->damage_mod = players[i]->attack;
        fplayers[i]->fighter_info->defense_mod = players[i]->defense;
        fplayers[i]->fighter_info->name = "TO FULLFILL";
        fplayers[i]->fighter_info->attacks = setup_attack();
    }
}

static void setup_enemy(game_manager_t *gm, int enemy_id)
{
    enemy_t *enemy = gm->scenes[GAME_ID]->enemies[enemy_id];
    enemy_t **fenemies = gm->scenes[gm->scene_id]->enemies;

    for (size_t i = 0; i < 1; i++) {
        fenemies[i] = create_enemy(enemy->pathname,
        (sfVector2f){100, 500}, NULL, NULL);
        fenemies[i]->rect = (sfIntRect){0, 0, fenemies[i]->size.x / 7,
        fenemies[i]->size.y / 4};
        fenemies[i]->fighter_info->sprite = enemy->sprite;
        fenemies[i]->fighter_info->texture = enemy->texture;
        fenemies[i]->fighter_info->life = 50;
        fenemies[i]->fighter_info->path_to_spritesheet = enemy->pathname;
        fenemies[i]->fighter_info->damage_mod = 10;
        fenemies[i]->fighter_info->defense_mod = 10;
        fenemies[i]->fighter_info->name = "TO FULLFILL";
        fenemies[i]->fighter_info->attacks = setup_attack();
    }
}

void setup_fight(game_manager_t *gm, int enemy_id)
{
    background_t **backgrounds = gm->scenes[gm->scene_id]->backgrounds;

    setup_music(gm, enemy_id);
    setup_player(gm);
    setup_enemy(gm, enemy_id);
    if (backgrounds[0] != NULL) {
        destroy_background(backgrounds[0]);
        backgrounds[0] = create_background(
        gm->scenes[GAME_ID]->backgrounds[0]->pathname,
        (sfVector2f){-500, -500}, NULL);
    }
}