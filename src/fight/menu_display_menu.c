/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** menu_display_menu.c
*/

#include "header.h"

sfText *create_menu_text(char *content, sfVector2f pos)
{
    sfText *txt = sfText_create();
    sfFont *font = sfFont_createFromFile("font/Astrolab.ttf");

    sfText_setString(txt, content);
    sfText_setColor(txt, sfWhite);
    sfText_setCharacterSize(txt, 20);
    sfText_setFont(txt, font);
    sfText_setPosition(txt, pos);
    return txt;
}

sfText **place_default_menu()
{
    sfText **texts = malloc(sizeof(sfText *) * 4);

    texts[0] = create_menu_text("Attack", (sfVector2f){SCR_WIDTH / 2 - 3,
    SCR_HEIGHT - 250});
    texts[1] = create_menu_text("Item", (sfVector2f){SCR_WIDTH / 2 - 3,
    SCR_HEIGHT - 225});
    texts[2] = NULL;
    return texts;
}

static void menu_texts(infobar_t *infobar)
{
    sfText **texts = infobar->texts;

    if (!texts) {
        texts = malloc(sizeof(sfText *) * 1);
        texts[0] = NULL;
    }
    if (infobar->menu->mode == DEFAULT)
        texts = place_default_menu();
    // if (infobar->menu->mode == ATTACK)
    //     texts = place_attack_menu();
    // if (infobar->menu->mode == ITEM)
    //     texts = place_item_menu();
    infobar->texts = texts;
}

void create_info_bar(UN game_manager_t *gm, infobar_t *infobar)
{
    //TODO : créer le sprite de la barre
    menu_texts(infobar);
}