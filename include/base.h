/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** Basic Header
*/

#ifndef BASE_H
#define BASE_H

#define READ_SIZE 12345
#define UN __attribute__((unused))
#define BLACK "\e[1;30m"
#define RED "\e[1;31m"
#define GREEN "\e[1;32m"
#define YELLOW "\e[1;33m"
#define BLUE "\e[1;34m"
#define MAGENTA "\e[1;35m"
#define CYAN "\e[1;36m"
#define WHITE "\e[1;37m"
#define SHELL "\e[;m"
#define RODE "\e[9;30m"
#define BOLD "\e[01;30m"
#define FLASH "\e[5;30m"

int my_strlen(char const *str);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_putstr_error(char const *str);
void my_putchar(char c);
int starts_with(char const *str, char *comp);
char *my_strcat_malloc(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char **my_explode(char *str, char sep);
char *my_strdup(char const *src);
char *my_strcat(char *dest, char const *src);
int str_contain(char *str_to_check, char char_to_find);

#endif