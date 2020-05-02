/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Add unselect button
*/

#include "header.h"

static char **get_unselect_pathnames(void)
{
    char *unselect_pathnames_tmp[] = {"image/item/green_necklace.png",
    "image/item/water_shield.png", "image/item/asmic_book.png",
    "image/item/white_spirit.png", "image/item/hell_sword.png",
    "image/item/gold_sword.png", "image/item/green_soul.png",
    "image/item/golden_ring.png", "image/item/blouba.png",
    "image/item/feather.png", "image/item/dark_cross.png",
    "image/item/heart.png"};
    char **unselect_pathnames = malloc(sizeof(char *) * 12);

    for (size_t i = 0; i < 12; i++) {
        unselect_pathnames[i] = unselect_pathnames_tmp[i];
    }
    return unselect_pathnames;
}

void add_unselect_button(size_t i, scene_t *scene)
{
    const int x[12] = {64, 320, 624, 880, 64, 320, 624, 880,
    64, 320, 624, 880};
    const int y[12] = {320, 320, 320, 320, 576, 576,
    576, 576, 832, 832, 832, 832};
    sfVector2f pos = (sfVector2f){x[i], y[i] - 32};
    char **unselect_pathnames = get_unselect_pathnames();
    char *pathnames[] = {unselect_pathnames[i], unselect_pathnames[i],
    unselect_pathnames[i]};

    scene->buttons[i] = create_button(pathnames,
    pos, &select_callback);
    free(unselect_pathnames);
}