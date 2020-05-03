/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** menu_display_sprites.c
*/

#include "header.h"

static void create_info_sprite(infobar_t *infobar)
{
    printf("oui en effet !\n");
    sfSprite *bar = sfSprite_create();
    sfSprite *arrow = sfSprite_create();
    sfTexture *arrow_texture = sfTexture_createFromFile("image/other/arrow.png",
    NULL);

    sfSprite_setTexture(arrow, arrow_texture, sfTrue);
    sfSprite_setPosition(arrow,
    (sfVector2f){SCR_WIDTH / 2 - 100, (SCR_HEIGHT - 160) - 15});
    sfSprite_setScale(arrow, (sfVector2f){50.0f / 512.0f, 50.0f / 512.0f});
    bar = arrow;
    infobar->sprites = malloc(sizeof(sfSprite *) * 3);
    infobar->sprites[0] = bar;
    infobar->sprites[1] = arrow;
    infobar->sprites[2] = NULL;
}

void menu_info_sprites(infobar_t *infobar, game_manager_t *gm)
{
    sfSprite **sprite = infobar->sprites;

    if (!sprite)
        create_info_sprite(infobar);
}