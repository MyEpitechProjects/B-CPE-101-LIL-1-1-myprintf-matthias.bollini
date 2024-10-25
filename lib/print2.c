/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** utils2
*/


#include "../include/my.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int print_float(double val, char *flag, int *data, char c2)
{
    int size = data[0] - calc_float_len(val, data[1], flag);
    int value = 0;

    if (flag[3] == '1' && val > -1)
        size -= my_putchar('+');
    else if (flag[1] == '1' && val > -1)
        size -= my_putchar(' ');
    if (flag[0] == '0'){
        if (val < 0 && flag[4] == '1'){
            value += my_putchar('-');
            val = val * -1;
        }
        value += draw_line(c2, size);
    }
    value += my_put_float(val, data[1], flag);
    if (flag[0] == '1')
        value += draw_line(' ', size);
    return value;
}

int print_float_sc(double val, char *flag, int *data, char c2)
{
    int size = data[0] - my_put_science_float_len(val, data[1], flag);
    int value = 0;

    if (flag[3] == '1' && val > -1)
        size -= my_putchar('+');
    else if (flag[1] == '1' && val > -1)
        size -= my_putchar(' ');
    if (flag[0] == '0'){
        if (val < 0 && flag[4] == '1'){
            value += my_putchar('-');
            val = val * -1;
        }
        value += draw_line(c2, size);
    }
    value += my_put_science_float(val, data[1], flag);
    if (flag[0] == '1')
        value += draw_line(' ', size);
    return value;
}
