/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** Random number generator
*/

int randomize(int min, int max)
{
    int nb = rand() % (max - min + 1) + min;
    return nb;
}