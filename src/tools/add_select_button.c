/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Add select button
*/

#include "header.h"

static char **get_select_pathnames(void)
{
    char *select_pathnames_tmp[] = {"image/item/green_necklace_sel.png",
    "image/item/water_shield_sel.png", "image/item/asmic_book_sel.png",
    "image/item/white_spirit_sel.png", "image/item/hell_sword_sel.png",
    "image/item/gold_sword_sel.png", "image/item/green_soul_sel.png",
    "image/item/golden_ring_sel.png", "image/item/blouba_sel.png",
    "image/item/feather_sel.png", "image/item/dark_cross_sel.png",
    "image/item/heart_sel.png"};
    char **select_pathnames = malloc(sizeof(char *) * 12);

    for (size_t i = 0; i < 12; i++) {
        select_pathnames[i] = select_pathnames_tmp[i];
    }
    return select_pathnames;
}

void add_select_button(size_t i, scene_t *scene)
{
    const int x[12] = {64, 320, 624, 880, 64, 320, 624, 880,
    64, 320, 624, 880};
    const int y[12] = {320, 320, 320, 320, 576, 576,
    576, 576, 832, 832, 832, 832};
    sfVector2f pos = (sfVector2f){x[i], y[i] - 32};
    char **select_pathnames = get_select_pathnames();
    char *pathnames[] = {select_pathnames[i], select_pathnames[i],
    select_pathnames[i]};

    scene->buttons[i] = create_button(pathnames,
    pos, &unselect_callback);
    free(select_pathnames);
}