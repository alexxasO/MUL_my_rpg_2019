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
text_t *create_text(char *string, size_t size, sfColor color,
sfVector2f pos);
void spawn_npc(game_manager_t *gm, scene_t *scene, char *sprite_path);

/* DESTROY */
void destroy_game_manager(game_manager_t *game_manager);
void destroy_text(text_t *text);
void destroy_button(button_t *button);
void destroy_save(save_t *save);

/* DRAW */
void draw_scene(game_manager_t *gm, scene_t *scene);
void draw_text(game_manager_t *gm, scene_t *scene);

/* EVENT */
void handle_event(game_manager_t *gm, sfEvent event);

/* BACKGROUND */
background_t **start_menu_background(void);
background_t **save_background(void);
background_t **game_background(void);
background_t **new_background(void);
background_t **fight_background(void);
background_t **pause_background(void);
background_t **help_background(void);
background_t **inventory_and_status_background(void);

/* PLAYER */
player_t **start_menu_player(void);
player_t **save_player(void);
player_t **game_player(void);
player_t **new_player(void);
player_t **fight_player(void);
player_t **pause_player(void);
player_t **help_player(void);
player_t **inventory_and_status_player(void);

/* ENEMY */
enemy_t **start_menu_enemy(void);
enemy_t **save_enemy(void);
enemy_t **game_enemy(void);
enemy_t **new_enemy(void);
enemy_t **fight_enemy(void);
enemy_t **pause_enemy(void);
enemy_t **help_enemy(void);
enemy_t **inventory_and_status_enemy(void);

/* BUTTON */
button_t **start_menu_button(void);
button_t **save_button(void);
button_t **game_button(void);
button_t **new_button(void);
button_t **fight_button(void);
button_t **pause_button(void);
button_t **help_button(void);
button_t **inventory_and_status_button(void);

/* TEXT */
text_t **start_menu_text(void);
text_t **save_text(void);
text_t **game_text(void);
text_t **new_text(void);
text_t **fight_text(void);
text_t **pause_text(void);
text_t **help_text(void);
text_t **inventory_and_status_text(void);

/* SCENES */
void start_menu_func(game_manager_t *gm);
void save_func(game_manager_t *gm);
void game_func(game_manager_t *gm);
void new_func(game_manager_t *gm);
void fight_func(game_manager_t *gm);
void pause_func(game_manager_t *gm);
void help_func(game_manager_t *gm);
void inventory_and_status_func(game_manager_t *gm);

/* TOOLS */
void get_mouse_pos(game_manager_t *gm);
sfBool is_mouse_over_button(game_manager_t *gm, button_t *button);
void handle_buttons(game_manager_t *gm, scene_t *scene);
sfBool is_arrow_pressed(char *key_pressed);
int randomize(int min, int max);

/* SAVE */
sfBool check_save(size_t save_nb);
save_t *get_save_data(size_t save_nb);
void write_save_name(game_manager_t *gm, sfEvent event);
void update_save_file(game_manager_t *gm);
void fulfill_save(save_t *save, char *filename);

/* CALLBACKS */
void quit_callback(game_manager_t *gm);
void play_callback(game_manager_t *gm);
void game_callback(game_manager_t *gm);
void return_callback(game_manager_t *gm);
void new_callback(game_manager_t *gm);
void create_callback(game_manager_t *gm);
void resume_callback(game_manager_t *gm);
void help_callback(game_manager_t *gm);

/* FIGHT */
int count_players(player_t **fighters);
int count_enemies(enemy_t **enemies);
void place_infobar(player_t **players, enemy_t **enemies, game_manager_t *gm);

/* ANIMATION */
void anim_player(game_manager_t *gm, player_t *player);

/* MOVEMENT */
void move_player_and_background(game_manager_t *gm, player_t *player,
background_t *background);

#endif
