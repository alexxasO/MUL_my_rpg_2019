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

static void interpret_key(infobar_t *infobar, game_manager_t *gm)
{
    if (!my_strcmp(gm->key_pressed, "enter") && infobar->mode == DEFAULT)
        change_info_mode(infobar);
//     if (!my_strcmp(gm->key_pressed, "up"))
//         change_selector_up(infobar);
//     if (!my_strcmp(gm->key_pressed, "down"))
//         change_selector_down(infobar);
}

static void menu_texts(infobar_t *infobar, game_manager_t *gm, int turn)
{
    sfText **texts = infobar->texts;

    if (texts)
        free(texts);
    if (infobar->mode == DEFAULT)
        texts = place_default_menu();
    if (infobar->mode == ATTACK)
        texts = place_attack_menu(gm, turn);
    // if (infobar->mode == SELECTOR)
    //     texts = place_char_menu();
    infobar->texts = texts;
    interpret_key(infobar, gm);
}

void create_info_bar(game_manager_t *gm, infobar_t *infobar, int turn)
{
    menu_info_sprites(infobar, gm);
    menu_texts(infobar, gm, turn);
}