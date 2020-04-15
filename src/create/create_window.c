/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** Create the window
*/

#include "header.h"

sfRenderWindow *create_window(int width, int height)
{
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    return sfRenderWindow_create(video_mode, "MY RPG",
    sfDefaultStyle, NULL);
}