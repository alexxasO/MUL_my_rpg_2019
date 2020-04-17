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

/* PLAYER */
player_t **start_menu_player(void);

/* ENEMY */
enemy_t **start_menu_enemy(void);

/* BUTTON */
button_t **start_menu_button(void);

/* SCENES */
void start_menu_func(game_manager_t *gm);

/* TOOLS */
void get_mouse_pos(game_manager_t *gm);
sfBool is_mouse_over_button(game_manager_t *gm, button_t *button);

#endif