/*
** EPITECH PROJECT, 2019
** detect.c
** File description:
** detect %
*/

#include <stdarg.h>
#include "base.h"

int detect(va_list va, int i, char *s, ...)
{
    switch (s[i]) {
    case 's':
        my_putstr(va_arg(va, char *));
        break;
    case 'c':
        my_putchar(va_arg(va, int));
        break;
    case 'i':
        my_put_nbr(va_arg(va, int));
        break;
    case 'd':
        my_put_nbr(va_arg(va, int));
        break;
    default:
        break;
    }
    return 0;
}