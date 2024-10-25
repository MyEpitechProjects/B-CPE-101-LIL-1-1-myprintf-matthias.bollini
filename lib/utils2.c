/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** utils2
*/


#include "../include/my.h"
#include <unistd.h>
#include <stdarg.h>

int is_num(char c)
{
    if ((c < 48 || c > 57))
        return 0;
    return 1;
}

int is_flg(char c)
{
    if (c == '-' || c == '#'
        || c == ' ' || c == '+'
        || c == '0')
        return 1;
    return 0;
}

long long power(long long nb, int p)
{
    if (p < 0)
        return 0;
    if (p == 0)
        return 1;
    if (p == 1)
        return nb;
    return nb * power(nb, p - 1);
}

int my_strlen(char const *str)
{
    int index = 0;

    while (str[index] != '\0'){
        index += 1;
    }
    return index;
}

int my_putstr(char const *str)
{
    int index = 0;
    int value = 0;

    while (str[index] != '\0'){
        value += 1;
        my_putchar(str[index]);
        index += 1;
    }
    return value;
}
