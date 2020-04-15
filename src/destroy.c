/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Destroy everything
*/

#include "header.h"

static void destroy_background(background_t *background)
{
    sfSprite_destroy(background->sprite);
    sfTexture_destroy(background->texture);
    sfClock_destroy(background->clock);
    free(background);
}

static void destroy_player(player_t *player)
{
    sfSprite_destroy(player->sprite);
    sfTexture_destroy(player->texture);
    sfClock_destroy(player->clock);
    /*if (player->sound != NULL) {
        if (sfMusic_getStatus(player->sound) != sfStopped)
            sfMusic_stop(player->sound);
        sfMusic_destroy(player->sound);
    }*/
    free(player);
}

static void destroy_enemy(enemy_t *enemy)
{
    sfSprite_destroy(enemy->sprite);
    sfTexture_destroy(enemy->texture);
    sfClock_destroy(enemy->clock);
    free(enemy->pathname);
    if (enemy->sound != NULL) {
        if (sfMusic_getStatus(enemy->sound) != sfStopped)
            sfMusic_stop(enemy->sound);
        sfMusic_destroy(enemy->sound);
    }
    free(enemy);
}

static void destroy_button(button_t *button)
{
    for (size_t i = 0; i < 3; i++) {
        sfSprite_destroy(button->sprite[i]);
        sfTexture_destroy(button->texture[i]);
    }
    free(button->pathname);
    free(button->sprite);
    free(button->texture);
    free(button);
}

static void destroy_scene(scene_t *scene)
{
    for (int i = 0; scene->backgrounds[i] != NULL; i++)
        destroy_background(scene->backgrounds[i]);
    free(scene->backgrounds);
    for (int i = 0; scene->players[i] != NULL; i++)
        destroy_player(scene->players[i]);
    free(scene->players);
    for (int i = 0; scene->enemies[i] != NULL; i++)
        destroy_enemy(scene->enemies[i]);
    free(scene->enemies);
    for (int i = 0; scene->buttons[i] != NULL; i++)
        destroy_button(scene->buttons[i]);
    free(scene->buttons);
//    if (sfMusic_getStatus(scene->music) != sfStopped)
//        sfMusic_stop(scene->music);
//    sfMusic_destroy(scene->music);
    free(scene);
}

void destroy_game_manager(game_manager_t *game_manager)
{
    for (size_t i = 0; i < game_manager->nb_scenes; i++) {
        if (game_manager->scenes[i] != NULL)
            destroy_scene(game_manager->scenes[i]);
    }
    free(game_manager->scenes);
    sfRenderWindow_destroy(game_manager->window);
    free(game_manager);
}
