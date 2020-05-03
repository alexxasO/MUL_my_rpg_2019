/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Create everything
*/

#include "header.h"

const char *music[] = {"music/menu_music.ogg", "music/menu_music.ogg",
"music/tower_music.ogg", "music/fight_music.ogg", "music/menu_music.ogg",
"music/tower_music.ogg", "music/tower_music.ogg", "music/tower_music.ogg",
"music/menu_music.ogg", "music/menu_music.ogg"};

static void get_func_ptr_and_game_object_ext(scene_t **scenes, size_t i)
{
    player_t **(*player_func_ptr[])(void) = {&start_menu_player, &save_player,
    &game_player, &fight_player, &new_player, &pause_player, &help_player,
    &inventory_and_status_player, &save_multi_player, &multi_player};
    enemy_t **(*enemy_func_ptr[])(void) = {&start_menu_enemy, &save_enemy,
    &game_enemy, &fight_enemy, &new_enemy, &pause_enemy, &help_enemy,
    &inventory_and_status_enemy, &save_multi_enemy, &multi_enemy, &ip_enemy};
    text_t **(*text_func_ptr[])(void) = {&start_menu_text, &save_text,
    &game_text, &fight_text, &new_text, &pause_text, &help_text,
    &inventory_and_status_text, &save_multi_text, &multi_text, &ip_text};

    scenes[i]->players = player_func_ptr[i]();
    scenes[i]->enemies = enemy_func_ptr[i]();
    scenes[i]->texts = text_func_ptr[i]();
    scenes[i]->sftexts = NULL; // TEMPORAIRE
}

static void get_func_ptr_and_game_object(scene_t **scenes, size_t i)
{
    void (*scene_func_ptr[])(game_manager_t *) = {&start_menu_func,
    &save_func, &game_func, &fight_func, &new_func, &pause_func,
    &help_func, &inventory_and_status_func, &save_multi_func,
    &multi_func, &ip_func};
    button_t **(*button_func_ptr[])(void) = {&start_menu_button,
    &save_button, &game_button, &fight_button, &new_button, &pause_button,
    &help_button, &inventory_and_status_button, &save_multi_button,
    &multi_button, &ip_button};
    background_t **(*background_func_ptr[])(void) = {&start_menu_background,
    &save_background, &game_background, &fight_background, &new_background,
    &pause_background, &help_background, &inventory_and_status_background,
    &save_multi_background, &multi_background, &multi_background};

    scenes[i]->func_ptr = scene_func_ptr[i];
    scenes[i]->buttons = button_func_ptr[i]();
    scenes[i]->backgrounds = background_func_ptr[i]();
    get_func_ptr_and_game_object_ext(scenes, i);
}

static scene_t **create_scenes(int nb_scenes)
{
    scene_t **scenes = malloc(sizeof(scene_t *) * (nb_scenes + 1));

    for (int i = 0; i < nb_scenes; i++) {
        scenes[i] = malloc(sizeof(scene_t));
        if (music[i] != NULL) {
            scenes[i]->music = sfMusic_createFromFile(music[i]);
            scenes[i]->music_pathname = my_strdup(music[i]);
            sfMusic_setLoop(scenes[i]->music, sfTrue);
        }
        get_func_ptr_and_game_object(scenes, i);
    }
    scenes[nb_scenes] = NULL;
    return scenes;
}

static save_t **get_all_save(void)
{
    save_t **saves = malloc(sizeof(save_t *) * 3);

    for (size_t i = 0; i < 3; i++) {
        if (check_save(i) == sfTrue)
            saves[i] = get_save_data(i);
        else
            saves[i] = NULL;
    }
    return saves;
}

game_manager_t *create_game_manager(void)
{
    game_manager_t *game_manager = malloc(sizeof(game_manager_t));
    size_t nb_scenes = NB_SCENES;
    sfVector2f click_position = {-1.f, -1.f};

    game_manager->window = create_window(1920, 1080);
    game_manager->scene_id = START_MENU_ID;
    game_manager->nb_scenes = nb_scenes;
    game_manager->scenes = create_scenes(nb_scenes);
    game_manager->click_position = click_position;
    game_manager->is_mouse_clicked = sfFalse;
    game_manager->key_pressed = my_strdup("none");
    game_manager->saves = get_all_save();
    game_manager->save_id = 0;
    return game_manager;
}
