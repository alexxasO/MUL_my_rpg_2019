/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** Header for structures
*/

#ifndef STRUCT_H
#define STRUCT_H

#include "includes.h"

typedef struct game_manager_s game_manager_t;

typedef struct attack {
    int dmg;
    int speed_dmg;
    int defense_dmg;
    int damage_dmg;
    char *path_to_icon;
} attack_t;

typedef struct player_object {
    bool is_attack;
    int life_effect;
    int damage_boost;
    int defense_boost;
    int speed_boost;
    char *path_to_icons;
} inv_object_t;

typedef struct fighter_info {
    char *path_to_spritesheet;
    int life;
    sfSprite *sprite;
    sfTexture *texture;
    attack_t *attacks;
    inv_object_t *object;
    //ptr anim
    //attack anim
    //idle anim
    //death/dead anim
    int speed;
    int damage_mod;
    int defense_mod;
    int speed_mod;
} fighter_info_t;

typedef struct button {
    sfSprite **sprite;
    sfTexture **texture;
    sfVector2f pos;
    sfIntRect rect;
    int state;
    void (*callback) (game_manager_t *);
    char **pathname;
} button_t;

typedef struct enemy_s {
    char *pathname;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *clock;
    void (*ptr_move) (struct enemy_s *, sfVector2f);
    void (*ptr_anim) (struct enemy_s *, sfRenderWindow *);
    int life;
    size_t damage;
    size_t defense;
    sfMusic *sound;
    sfVector2u size;
    fighter_info_t *fighter_info;
} enemy_t;

typedef struct player_s {
    char *pathname;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *clock_anim;
    sfClock *clock_move;
    void (*ptr_move) (struct player_s *, sfVector2f);
    void (*ptr_anim) (struct player_s *, sfRenderWindow *);
    size_t max_life;
    int life;
    size_t attack;
    size_t defense;
    sfMusic *sound;
    sfVector2u size;
    fighter_info_t *fighter_info;
    size_t level;
    size_t experience;
    int direction;
} player_t;

typedef struct background_s {
    char *pathname;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *clock;
    void (*ptr_move) (struct background_s *, sfVector2f);
} background_t;

typedef struct text_s {
    char *string;
    sfText *text;
    sfFont *font;
    size_t size;
    sfColor color;
    sfVector2f pos;
} text_t;

typedef struct scene_s {
    background_t **backgrounds;
    player_t **players;
    enemy_t **enemies;
    button_t **buttons;
    text_t **texts;
    sfText **sftexts;
    void (*func_ptr)(game_manager_t *);
    sfMusic *music;
} scene_t;

typedef struct save_s {
    char *name;
    size_t level;
    size_t exp;
    size_t stage;
    char *character;
    int *inventory;
} save_t;

struct game_manager_s {
    scene_t **scenes;
    size_t nb_scenes;
    size_t scene_id;
    sfRenderWindow *window;
    sfEvent event;
    sfVector2f click_position;
    sfBool is_mouse_clicked;
    save_t **saves;
    size_t save_id;
    char *key_pressed;
    player_t **player_list;
    enemy_t **enemy_list;
};

#endif
