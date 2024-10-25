/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** utils2
*/


#include "../include/my.h"
#include <unistd.h>
#include <stdarg.h>

static int putchar_upp(unsigned int az, int is_upper)
{
    if (is_upper == 0)
        return my_putchar(97 + (az - 10));
    else
        return my_putchar(65 + (az - 10));
}

int my_putstrn(char const *str, int n)
{
    int index = 0;
    int value = 0;

    while (str[index] != '\0' && index < n){
        value += 1;
        my_putchar(str[index]);
        index += 1;
    }
    return value;
}

int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}

int print_hex_val(unsigned long long nb, int is_upper)
{
    int nb2 = calc_division_num(nb);
    unsigned long long az;
    int idx = 0;
    int value = 0;

    for (int i = nb2; i > 0; i--){
        az = nb;
        for (int i2 = 0; i2 < i - 1; i2++){
            az = az / 16;
        }
        az = az % 16;
        if (az < 10) {
            value += my_putchar(48 + az);
        } else {
            value += putchar_upp(az, is_upper);
        }
        idx += 1;
    }
    return value;
}

int calc_division_num(unsigned long long nb)
{
    int n = 0;

    if (nb == 0)
        return 1;
    while (nb != 0) {
        nb = nb / 16;
        n += 1;
    }
    return n;
}

unsigned long long oct(unsigned long long nb)
{
    int idx = 0;
    unsigned long long val = 0;

    while (nb > 0){
        val += (nb % 8) * (power(10, idx));
        nb = nb / 8;
        idx += 1;
    }
    return val;
}
