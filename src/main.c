/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** Main
*/

#include "header.h"

void launch_game(game_manager_t *gm)
{
    sfRenderWindow_setFramerateLimit(gm->window, 60);
    while (sfRenderWindow_isOpen(gm->window)) {
        get_mouse_pos(gm);
        handle_event(gm, gm->event);
        if (gm->scenes[gm->scene_id] != NULL) {
            gm->scenes[gm->scene_id]->func_ptr(gm);
            draw_scene(gm, gm->scenes[gm->scene_id]);
        }
    }
    destroy_game_manager(gm);
}

int main(int ac, UN char **av, UN char **env)
{
    game_manager_t *gm = create_game_manager();
    client_t client;

    if ((ac != 2) && (ac != 1)) {
        destroy_game_manager(gm);
        return 84;
    }
    if (ac == 2 && my_strcmp(av[1], "-H") == 0) {
        sfRenderWindow_close(gm->window);
        launch_serv(&client);
        return 0;
    }
    launch_game(gm);
    return 0;
}