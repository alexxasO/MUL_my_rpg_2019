/*
** EPITECH PROJECT, 2020
** random.c
** File description:
** generate random int or color
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Export.h>
#include <time.h>

int random_int(int max)
{
    int i = rand() % max;
    return i;
}

sfColor rand_colors(void)
{
    sfColor color;

    color.r = rand() % 256;
    color.g = rand() % 256;
    color.b = rand() % 256;
    color.a = rand() % 256;
    return color;
}
