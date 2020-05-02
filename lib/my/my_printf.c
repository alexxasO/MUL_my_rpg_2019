/*
** EPITECH PROJECT, 2019
** printfff.c
** File description:
** printffff
*/

#include <stdarg.h>
#include "base.h"

int my_printf(char *s, ...)
{
    va_list va;

    va_start(va, s);
    for (int i = 0; i < my_strlen(s); i++) {
        if (s[i] == '%' && s[i + 1] != '%') {
            detect(va, i + 1, s);
            i++;
        } else if (s[i] == '%' && s[i + 1] == '%') {
            my_putchar('%');
        } else
            my_putchar(s[i]);
    }
    return 0;
}
