/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** menu_display_menu.c
*/

#include "header.h"

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
}

void create_info_bar(game_manager_t *gm, infobar_t *infobar, int *turn)
{
    menu_info_sprites(infobar, gm);
    menu_texts(infobar, gm, turn);
}