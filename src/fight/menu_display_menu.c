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
    sfText **texts = malloc(sizeof(sfText *) * 3);

    texts[0] = create_menu_text("Attack", (sfVector2f){SCR_WIDTH / 2 - 50,
    SCR_HEIGHT - 160});
    texts[1] = create_menu_text("Item", (sfVector2f){SCR_WIDTH / 2 - 50,
    SCR_HEIGHT - 160 + 25});
    texts[2] = NULL;
    return texts;
}

sfText **place_attack_menu(game_manager_t *gm, int turn)
{
    scene_t *scene = gm->scenes[gm->scene_id];
    sfText **texts = malloc(sizeof(sfText *) * 5);
    fighter_info_t *fighter = gm->player_list[turn]->fighter_info;

    texts[0] = create_menu_text(fighter->attacks[0]->name,
    (sfVector2f){SCR_WIDTH / 2 - 50, SCR_HEIGHT - 160});
    texts[1] = create_menu_text(fighter->attacks[1]->name,
    (sfVector2f){SCR_WIDTH / 2 - 50, SCR_HEIGHT - 160 + 25 * 1});
    texts[2] = create_menu_text(fighter->attacks[2]->name,
    (sfVector2f){SCR_WIDTH / 2 - 50, SCR_HEIGHT - 160 + 25 * 2});
    texts[3] = create_menu_text(fighter->attacks[3]->name,
    (sfVector2f){SCR_WIDTH / 2 - 50, SCR_HEIGHT - 160 + 25 * 3});
    return texts;
}

static void set_menu_mode(sfText *txt, infobar_t *infobar)
{
    if (sfText_getString(txt) == "Attack")
        infobar->mode = ATTACK;
    if (sfText_getString(txt) == "Menu")
        infobar->mode = DEFAULT;
}

static void change_info_mode(infobar_t *infobar)
{
    sfSprite *arrow = infobar->sprites[1];
    sfText *txt;

    for (int i = 0; infobar->texts[i]; i++) {
        txt = infobar->texts[i];
        if (sfSprite_getPosition(arrow).y == sfText_getPosition(txt).y)
            set_menu_mode(txt, infobar);
    }
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
    // if (infobar->mode == ITEM)
    //     texts = place_item_menu();
    if (!my_strcmp(gm->key_pressed, "enter") && infobar->mode == DEFAULT)
        change_info_mode(infobar);
    infobar->texts = texts;
}

void create_info_bar(game_manager_t *gm, infobar_t *infobar, int turn)
{
    //TODO : créer le sprite de la barre
    menu_texts(infobar, gm, turn);
}