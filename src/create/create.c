/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Create everything
*/

#include "header.h"

const char *music[] = {NULL};

button_t **null_button_func(void)
{
    button_t **buttons = malloc(sizeof(button_t *));

    buttons[0] = NULL;
    return buttons;
}

background_t **null_background_func(void)
{
    background_t **backgrounds = malloc(sizeof(background_t *));

    backgrounds[0] = NULL;
    return backgrounds;
}

player_t **null_player_func(void)
{
    player_t **players = malloc(sizeof(player_t *));

    players[0] = NULL;
    return players;
}

enemy_t **null_enemy_func(void)
{
    enemy_t **enemies = malloc(sizeof(enemy_t *));

    enemies[0] = NULL;
    return enemies;
}

static scene_t **create_scenes(int nb_scenes)
{
    scene_t **scenes = malloc(sizeof(scene_t *) * (nb_scenes + 1));
    void (*scene_func_ptr[])(game_manager_t *) = {&start_menu_func, &save_func, &game_func, &fight_func};
    button_t **(*button_func_ptr[])(void) = {&start_menu_button, &save_button, &game_button, &null_button_func};
    background_t **(*background_func_ptr[])(void) = {&start_menu_background, &save_background, &game_background, &fight_background};
    player_t **(*player_func_ptr[])(void) = {&start_menu_player, &save_player, &game_player, &fight_players};
    enemy_t **(*enemy_func_ptr[])(void) = {&start_menu_enemy, &save_enemy, &game_enemy, &fight_enemy};

    for (int i = 0; i < nb_scenes; i++) {
        scenes[i] = malloc(sizeof(scene_t));
        if (music[i] != NULL) {
            scenes[i]->music = sfMusic_createFromFile(music[i]);
            sfMusic_setLoop(scenes[i]->music, sfTrue);
        }
        scenes[i]->func_ptr = scene_func_ptr[i];
        scenes[i]->buttons = button_func_ptr[i]();
        scenes[i]->backgrounds = background_func_ptr[i]();
        scenes[i]->players = player_func_ptr[i]();
        scenes[i]->enemies = enemy_func_ptr[i]();
        scenes[i]->texts = NULL;
    }
    scenes[nb_scenes] = NULL;
    return scenes;
}

game_manager_t *create_game_manager(void)
{
    game_manager_t *game_manager = malloc(sizeof(game_manager_t));
    size_t nb_scenes = NB_SCENES;
    sfVector2f click_position = {-1.f, -1.f};

    game_manager->window = create_window(1920, 1080);
    game_manager->scene_id = 0;
    game_manager->nb_scenes = nb_scenes;
    game_manager->scenes = create_scenes(nb_scenes);
    game_manager->click_position = click_position;
    game_manager->is_mouse_clicked = sfFalse;
    game_manager->key_pressed = my_strdup("none");
    return game_manager;
}
