/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Game callback
*/

#include "header.h"

static void get_player_from_save(char *player_name, player_t **players)
{
    char *filename = malloc(sizeof(char) * (18 + my_strlen(player_name)));

    filename[0] = '\0';
    filename = my_strcat(filename, "image/player/");
    filename = my_strcat(filename, player_name);
    filename = my_strcat(filename, ".png");
    players[0] = create_player(filename,
    (sfVector2f){500, 500}, NULL, NULL);
    players[0]->rect = (sfIntRect){0, 0, players[0]->size.x / 7,
    players[0]->size.y / 4};
}

static sfVector2f get_random_pos(void)
{
    sfImage *limit = sfImage_createFromFile("image/other/level_limit.png");
    unsigned int x = random_int(2304);
    unsigned int y = random_int(2304);
    sfColor px_color = sfImage_getPixel(limit, x, y);
    sfVector2f pos;

    sfImage_destroy(limit);
    if (px_color.r != sfWhite.r && px_color.g != sfWhite.g &&
    px_color.b != sfWhite.b)
        return (sfVector2f){-1, -1};
    pos.x = x;
    pos.y = y;
    return pos;
}

static void set_npc(player_t **players, background_t *background)
{
    sfVector2f pos = (sfVector2f){-1, -1};

    for (size_t i = 1; i < 2; i++) {
        if (players[i] != NULL) {
            destroy_player(players[i]);
            players[i] = NULL;
        }
        while (pos.x == -1)
            pos = get_random_pos();
        players[i] = create_player("image/player/axel.png",
        pos, NULL, NULL);
        players[i]->pos.x += background->pos.x;
        players[i]->pos.y += background->pos.y;
        players[i]->rect = (sfIntRect){0, 0, players[0]->size.x / 7,
        players[i]->size.y / 4};
        pos = (sfVector2f){-1, -1};
    }
}

void game_callback(game_manager_t *gm)
{
    scene_t *scene = gm->scenes[GAME_ID];

    gm->scene_id = GAME_ID;
    get_player_from_save(gm->saves[gm->save_id]->character, scene->players);
    set_npc(scene->players, scene->backgrounds[0]);
}