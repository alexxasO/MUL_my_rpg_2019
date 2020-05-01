/*
** EPITECH PROJECT, 2020
** create_save.c
** File description:
** Update save file
*/

#include "header.h"

static char *get_filename(int save_id)
{
    char *path = malloc(sizeof(char) * 11);

    path[0] = '\0';
    path = my_strcat(path, "file/save");
    path[9] = save_id + '0';
    path[10] = '\0';
    return path;
}

void update_save_file(game_manager_t *gm)
{
    char *filename = NULL;
    int fd = 0;

    for (size_t i = 0; i < 3; i++) {
        filename = get_filename(i + 1);
        if (gm->saves[i] == NULL) {
            fd = open(filename, O_RDWR);
            write(fd, "NO\n", 3);
            close(fd);
        } else
            fulfill_save(gm->saves[i], filename);
    }
}
