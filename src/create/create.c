/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Create everything
*/

#include "header.h"

const char *music[] = {NULL};

static void get_func_ptr_and_game_object(scene_t **scenes, size_t i)
{
    void (*scene_func_ptr[])(game_manager_t *) = {&start_menu_func,
    &save_func, &game_func};
    button_t **(*button_func_ptr[])(void) = {&start_menu_button,
    &save_button, &game_button};
    background_t **(*background_func_ptr[])(void) = {&start_menu_background,
    &save_background, &game_background};
    player_t **(*player_func_ptr[])(void) = {&start_menu_player, &save_player,
    &game_player};
    enemy_t **(*enemy_func_ptr[])(void) = {&start_menu_enemy, &save_enemy,
    &game_enemy};
    text_t **(*text_func_ptr[])(void) = {&start_menu_text, &save_text,
    &game_text};

    scenes[i]->func_ptr = scene_func_ptr[i];
    scenes[i]->buttons = button_func_ptr[i]();
    scenes[i]->backgrounds = background_func_ptr[i]();
    scenes[i]->players = player_func_ptr[i]();
    scenes[i]->enemies = enemy_func_ptr[i]();
    scenes[i]->texts = text_func_ptr[i]();
}

static scene_t **create_scenes(int nb_scenes)
{
    scene_t **scenes = malloc(sizeof(scene_t *) * (nb_scenes + 1));

    for (int i = 0; i < nb_scenes; i++) {
        scenes[i] = malloc(sizeof(scene_t));
        if (music[i] != NULL) {
            scenes[i]->music = sfMusic_createFromFile(music[i]);
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
    }
    return saves;
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
    game_manager->saves = get_all_save();
    game_manager->save_id = 0;
    return game_manager;
}
