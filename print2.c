/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** utils2
*/


#include "my.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int print_float(double val, char *flag, int *data, char c2)
{
    int size = data[0] - calc_float_len(val, data[1]);
    int value = 0;

    if (size < 0)
        size = 0;
    if (flag[0] == '0')
        value += draw_line(c2, size);
    value += my_put_float(val, data[1]);
    if (flag[0] == '1')
        value += draw_line(' ', size);
    return value;
}
