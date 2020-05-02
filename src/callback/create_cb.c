/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Create callback
*/

#include "header.h"

static save_t *set_new_save_data(game_manager_t *gm, save_t *save)
{
    save = malloc(sizeof(save_t));

    if (gm->scenes[gm->scene_id]->texts[0]->string[0] != '\0')
        save->name = my_strdup(gm->scenes[gm->scene_id]->texts[0]->string);
    else
        save->name = my_strdup("Unamed");
    save->level = 1;
    save->exp = 0;
    save->stage = 1;
    save->character = my_strdup("axel");
    for (size_t i = 0; i < 12; i++)
        save->inventory[i] = 0;
    return save;
}

void create_callback(game_manager_t *gm)
{
    char *save_pathnames[] = {"image/button/save.png",
    "image/button/save_over.png", "image/button/save_clicked.png"};

    gm->saves[gm->save_id] = set_new_save_data(gm, gm->saves[gm->save_id]);
    destroy_button(gm->scenes[SAVE_ID]->buttons[gm->save_id]);
    gm->scenes[SAVE_ID]->buttons[gm->save_id] =
    create_button(save_pathnames,
    (sfVector2f){320, 32 + gm->save_id * 288}, &game_callback);
    free(gm->scenes[NEW_ID]->texts[0]->string);
    gm->scenes[NEW_ID]->texts[0]->string = my_strdup("");
    game_callback(gm);
}