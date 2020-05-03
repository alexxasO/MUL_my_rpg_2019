/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** place_fight_text.c
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
    texts[4] = NULL;
    return texts;
}

sfText **place_target_menu(game_manager_t *gm, int turn)
{
    scene_t *scene = gm->scenes[gm->scene_id];
    sfText **texts;
    int i = 0;

    texts = malloc(sizeof(sfText *) * (count_enemies(gm->enemy_list) + 1));
    for (; gm->enemy_list[i]; i++) {
        texts[i] = create_menu_text(gm->enemy_list[i]->fighter_info->name,
        (sfVector2f){SCR_WIDTH / 2 - 50, SCR_HEIGHT - 160 + 25 * i});
        texts[i + 1] = NULL;
    }
    return texts;
}