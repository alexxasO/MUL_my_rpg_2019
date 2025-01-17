/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** copy a string
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));

    for (int i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[my_strlen(src)] = '\0';
    return dest;
}
