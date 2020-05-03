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

/* DESTROY */
void destroy_game_manager(game_manager_t *game_manager);
void destroy_text(text_t *text);
void destroy_button(button_t *button);
void destroy_save(save_t *save);
void destroy_player(player_t *player);
void destroy_enemy(enemy_t *enemy);
void destroy_background(background_t *background);

/* DRAW */
void draw_scene(game_manager_t *gm, scene_t *scene);
void draw_text(game_manager_t *gm, scene_t *scene);
void draw_entities(game_manager_t *gm, scene_t *scene);

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
background_t **save_multi_background(void);
background_t **multi_background(void);
background_t **sett_back(void);
background_t **ip_back(void);
background_t **chat_back(void);

/* PLAYER */
player_t **start_menu_player(void);
player_t **save_player(void);
player_t **game_player(void);
player_t **new_player(void);
player_t **fight_player(void);
player_t **pause_player(void);
player_t **help_player(void);
player_t **inventory_and_status_player(void);
player_t **save_multi_player(void);
player_t **multi_player(void);
player_t **sett_player(void);
player_t **ip_multi_player(void);
player_t **chat_player(void);

/* ENEMY */
enemy_t **start_menu_enemy(void);
enemy_t **save_enemy(void);
enemy_t **game_enemy(void);
enemy_t **new_enemy(void);
enemy_t **fight_enemy(void);
enemy_t **pause_enemy(void);
enemy_t **help_enemy(void);
enemy_t **inventory_and_status_enemy(void);
enemy_t **save_multi_enemy(void);
enemy_t **multi_enemy(void);
enemy_t **sett_enemy(void);
enemy_t **ip_enemy(void);
enemy_t **chat_enemy(void);

/* BUTTON */
button_t **start_menu_button(void);
button_t **save_button(void);
button_t **game_button(void);
button_t **new_button(void);
button_t **fight_button(void);
button_t **pause_button(void);
button_t **help_button(void);
button_t **inventory_and_status_button(void);
button_t **save_multi_button(void);
button_t **multi_button(void);
button_t **sett_button(void);
button_t **ip_button(void);
button_t **chat_button(void);

/* TEXT */
text_t **start_menu_text(void);
text_t **save_text(void);
text_t **game_text(void);
text_t **new_text(void);
text_t **fight_text(void);
text_t **pause_text(void);
text_t **help_text(void);
text_t **inventory_and_status_text(void);
text_t **save_multi_text(void);
text_t **multi_text(void);
text_t **sett_text(void);
text_t **ip_text(void);
text_t **chat_text(void);

/* SCENES */
void start_menu_func(game_manager_t *gm);
void save_func(game_manager_t *gm);
void game_func(game_manager_t *gm);
void new_func(game_manager_t *gm);
void fight_func(game_manager_t *gm);
void pause_func(game_manager_t *gm);
void help_func(game_manager_t *gm);
void inventory_and_status_func(game_manager_t *gm);
void save_multi_func(game_manager_t *gm);
void multi_func(game_manager_t *gm);
void sett_func(game_manager_t *gm);
void ip_func(game_manager_t *gm);
void chat_func(game_manager_t *gm);

/* TOOLS */
void get_mouse_pos(game_manager_t *gm);
sfBool is_mouse_over_button(game_manager_t *gm, button_t *button);
void handle_buttons(game_manager_t *gm, scene_t *scene);
sfBool is_arrow_pressed(char *key_pressed);
void update_stat(size_t item_id, player_t **players, int coef);
void add_select_button(size_t i, scene_t *scene);
void add_unselect_button(size_t i, scene_t *scene);
sfVector2f get_random_pos(void);
void set_npc(player_t **players, background_t *background);
void set_enemy(enemy_t **enemies, background_t *background);
void write_ip(game_manager_t *gm, sfEvent event);
void display_dialog(game_manager_t *gm, size_t npc_id);
void erase_dialog(game_manager_t *gm);

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
void select_callback(game_manager_t *gm);
void unselect_callback(game_manager_t *gm);
void multi_callback(game_manager_t *gm);
void play_multi_callback(game_manager_t *gm);
void sett_callback(game_manager_t *gm);
void play_multi_id_callback(game_manager_t *gm);
void validate_ip_cb(game_manager_t *gm);
void chat_cb(game_manager_t *gm);
void refresh_cb(game_manager_t *gm);

/* FIGHT */
int count_players(player_t **fighters);
int count_enemies(enemy_t **enemies);
player_t **fight_players(void);
enemy_t **fight_enemy(void);
void place_info_ply(player_t **players, game_manager_t *gm);
void place_info_enemies(enemy_t **enemies, game_manager_t *gm);
button_t **fight_button(void);
text_t **fight_text(void);
void create_info_bar(game_manager_t *gm, infobar_t *infobar, int *turn);
void draw_infobar(game_manager_t *gm, scene_t *scene);
void create_infobar(game_manager_t *gm);
void begin_fight(player_t **players, enemy_t **enemies, game_manager_t *gm);
sfText **place_attack_menu(game_manager_t *gm, int turn);
sfText **place_default_menu();
sfText *create_menu_text(char *content, sfVector2f pos);
void menu_info_sprites(infobar_t *infobar, game_manager_t *gm);
sfText **place_target_menu(game_manager_t *gm);
void change_selector_up(infobar_t *infobar);
void change_selector_down(infobar_t *infobar);
void attack_fighter(fighter_info_t *attacker, fighter_info_t *victim,
attack_t *attack);
void setup_fight(game_manager_t *gm, int enemy_id);
void place_player(player_t **players, int nb_players);
void place_enemies(enemy_t **enemies, int nb_enemies);
void place_infobar_texts(player_t **players, enemy_t **enemies,
game_manager_t *gm);
void interpret_key(infobar_t *infobar, game_manager_t *gm, int *turn);

/* ANIMATION */
void anim_player(game_manager_t *gm, player_t *player);

/* MOVEMENT */
void move_all(game_manager_t *gm, player_t **players,
background_t *background);
void move_npc_and_enemy(player_t **players, float add_x, float add_y,
enemy_t **enemies);

/* MUSIC */
void handle_music(game_manager_t *gm);

/* NETWORK */
void launch_serv(game_manager_t *gm);
bool waiting_for_connexion(game_manager_t *gm);

#endif
