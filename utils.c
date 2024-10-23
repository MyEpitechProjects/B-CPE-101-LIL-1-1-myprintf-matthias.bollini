/*
** EPITECH PROJECT, 2024
** C Pool Day 03
** File description:
** print number
*/

#include "my.h"
#include <stdarg.h>

static int print_num(unsigned long long nb, unsigned long long nb2, int count, int special)
{
    for (int i = count; i > 0; i--){
        nb2 = nb;
        for (int t = 0; t < i - 1; t++){
            nb2 = nb2 / 10;
        }
        my_putchar(48 + nb2 % 10);
    }
    if (special == 1){
        my_putchar(48 + 8);
    }
}

int my_put_nbr(long long nb)
{
    long long nb2 = nb;
    int count = 1;
    int special = 0;

    if (nb < 0) {
        my_putchar('-');
        if (nb == -2147483648){
            nb = 214748364;
            special = 1;
        } else {
            nb = nb * -1;
        }
        nb2 = nb;
    }
    while (nb2 > 9){
        nb2 = nb2 / 10;
        count = count + 1;
    }
    print_num(nb, nb2, count, special);
    return count + special;
}

int my_put_nbr_uns(unsigned long long nb)
{
    unsigned long long nb2 = nb;
    int count = 1;

    while (nb2 > 9){
        nb2 = nb2 / 10;
        count = count + 1;
    }
    print_num(nb, nb2, count, 0);
    return count;
}

int calc_int_len(unsigned long long val)
{
    int n = 0;

    if (n < 0){
        n += 1;
        val = val * -1;
    }
    while (val > 0){
        n += 1;
        val = val / 10;
    }
    return n;
}

int calc_int_len_uns(unsigned long long val)
{
    int n = 0;

    while (val > 0){
        n += 1;
        val = val / 10;
    }
    return n;
}

int draw_line(char c, int val)
{
    int value = 0;

    for (int i = 0; i < val; i++)
        value += my_putchar(c);
    return value;
}
