/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** Header for rpg
*/

#ifndef RPG_H
#define RPG_H

/* CREATE */
game_manager_t *create_game_manager(void);
sfRenderWindow *create_window(int width, int height);
button_t *create_button(char **pathname, sfVector2f pos,
void (*callback) (game_manager_t *));
enemy_t *create_enemy(char *pathname, sfVector2f pos,
void (*ptr_move) (struct enemy_s *, sfVector2f),
void (*ptr_anim) (struct enemy_s *, sfRenderWindow *));
player_t *create_player(char *pathname, sfVector2f pos,
void (*ptr_move) (struct player_s *, sfVector2f),
void (*ptr_anim) (struct player_s *, sfRenderWindow *));
background_t *create_background(char *pathname, sfVector2f pos,
void (*ptr_move) (struct background_s *, sfVector2f));

/* DESTROY */
void destroy_game_manager(game_manager_t *game_manager);

/* DRAW */
void draw_scene(game_manager_t *gm, scene_t *scene);

/* EVENT */
void handle_event(game_manager_t *gm, sfEvent event);

/* BACKGROUND */
background_t **start_menu_background(void);
background_t **save_background(void);

/* PLAYER */
player_t **start_menu_player(void);
player_t **save_player(void);

/* ENEMY */
enemy_t **start_menu_enemy(void);
enemy_t **save_enemy(void);

/* BUTTON */
button_t **start_menu_button(void);
button_t **save_button(void);

/* SCENES */
void start_menu_func(game_manager_t *gm);
void save_func(game_manager_t *gm);

/* TOOLS */
void get_mouse_pos(game_manager_t *gm);
sfBool is_mouse_over_button(game_manager_t *gm, button_t *button);
void handle_buttons(game_manager_t *gm, scene_t *scene);
sfBool check_save(size_t save_nb);

/* CALLBACKS */
void quit_callback(game_manager_t *gm);
void play_callback(game_manager_t *gm);
void return_callback(game_manager_t *gm);

#endif