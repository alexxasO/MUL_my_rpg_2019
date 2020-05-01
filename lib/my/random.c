/*
** EPITECH PROJECT, 2020
** random.c
** File description:
** generate random int or color
*/

#include "../../include/header.h"
/*
int random_int(int max)
{
    int i = rand() % max;

    if (i < 0)
        i *= -1;
    return i;
}*/

int random_int(int max)
{
    char buf[5];
    int fd = open("/dev/urandom", O_RDONLY);
    int random_number = 1;

    read(fd, buf, 5);
    for (size_t i = 0; i < 5; i++)
        random_number *= buf[i];
    if (random_number < 0)
        random_number *= -1;
    random_number = random_number % max;
    close(fd);
    return random_number;
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
