/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** menu_display_menu.c
*/

#include "header.h"

static void set_menu_mode(sfText *txt, infobar_t *infobar)
{
    if (!my_strcmp(sfText_getString(txt), "Attack")) {
        printf("attack oui tout a fait\n");
        infobar->mode = ATTACK;
    }
    if (!my_strcmp(sfText_getString(txt), "Menu"))
        infobar->mode = DEFAULT;
}

static void change_info_mode(infobar_t *infobar)
{
    sfSprite *arrow = infobar->sprites[1];
    sfText *txt;

    for (int i = 0; infobar->texts[i]; i++) {
        txt = infobar->texts[i];
        if (sfSprite_getPosition(arrow).y + 15 == sfText_getPosition(txt).y) {
            printf("oui !\n");
            set_menu_mode(txt, infobar);
        }
    }
}

static void stock_attack(infobar_t *infobar, game_manager_t *gm, int turn)
{
    sfVector2f arrow_pos = sfSprite_getPosition(infobar->sprites[1]);
    int selected_id = 0;
    player_t *ply = gm->player_list[turn];

    for (int i = 0; infobar->texts[i]; i++)
        if (sfText_getPosition(infobar->texts[i]).y == arrow_pos.y + 15)
            selected_id = i;
    infobar->attack_selected = ply->fighter_info->attacks[selected_id];
}

void apply_attack(infobar_t *info, game_manager_t *gm, int *turn) {
    sfVector2f arrow_pos = sfSprite_getPosition(info->sprites[1]);
    int selected_id = 0;
    enemy_t *enemy;

    for (int i = 0; info->texts[i]; i++)
        if (sfText_getPosition(info->texts[i]).y == arrow_pos.y + 15)
            selected_id = i;
    enemy = gm->enemy_list[selected_id];
    attack_fighter(gm->player_list[*turn]->fighter_info, enemy->fighter_info,
    info->attack_selected);
    gm->player_list[*turn]->life = gm->player_list[*turn]->fighter_info->life;
    enemy->life = enemy->fighter_info->life;
    info->mode = DEFAULT;
    *turn = *turn + 1;
    printf("j'add turn %d\nadresse : %p\n", *turn, turn);
}

static void interpret_key(infobar_t *infobar, game_manager_t *gm, int *turn)
{
    if (!my_strcmp(gm->key_pressed, "enter") && infobar->mode == SELECTOR) {
        apply_attack(infobar, gm, turn);
        printf("JE SUIS TURN ET JE SUIS CON %d\n", *turn);
    }
    if (!my_strcmp(gm->key_pressed, "enter") && infobar->mode == ATTACK) {
        infobar->mode = SELECTOR;
        stock_attack(infobar, gm, *turn);
    }
    if (!my_strcmp(gm->key_pressed, "enter") && infobar->mode == DEFAULT)
        change_info_mode(infobar);
    if (!my_strcmp(gm->key_pressed, "up"))
        change_selector_up(infobar);
    if (!my_strcmp(gm->key_pressed, "down"))
        change_selector_down(infobar);
}

static void menu_texts(infobar_t *infobar, game_manager_t *gm, int *turn)
{
    sfText **texts = infobar->texts;

    if (texts)
        free(texts);
    if (infobar->mode == DEFAULT)
        texts = place_default_menu();
    if (infobar->mode == ATTACK)
        texts = place_attack_menu(gm, (*turn));
    if (infobar->mode == SELECTOR)
        texts = place_target_menu(gm);
    infobar->texts = texts;
    interpret_key(infobar, gm, turn);
    printf("JE SUIS TOUJOURS STUPIDE %d\n", *turn);
}

void create_info_bar(game_manager_t *gm, infobar_t *infobar, int *turn)
{
    menu_info_sprites(infobar, gm);
    menu_texts(infobar, gm, turn);
}