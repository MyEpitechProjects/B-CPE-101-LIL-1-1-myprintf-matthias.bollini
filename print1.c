/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** print_str
*/

#include "my.h"
#include <stdarg.h>

int print_str(char *val, char *flag, int *data)
{
    int size;
    int tmps = my_strlen(val);
    int value = 0;

    if (data[1] < tmps && data[1] > -1)
        size = data[0] - data[1];
    else
        size = data[0] - my_strlen(val);
    if (size < 0)
        size = 0;
    if (flag[0] == '0')
        value += draw_line(' ', size);
    if (data[1] < 0)
        value += my_putstr(val);
    else
        value += my_putstrn(val, data[1]);
    if (flag[0] == '1')
        value += draw_line(' ', size);
    return value;
}

int print_char(char val, char *flag, int *data)
{
    int size = data[0]-1;
    int value = 0;

    if (size < 0)
        size = 0;
    if (flag[0] == '0')
        value += draw_line(' ', size);
    value += my_putchar(val);
    if (flag[0] == '1')
        value += draw_line(' ', size);
    return value;
}

int print_int(long long val, char *flag, int *data, char c2)
{
    int size = data[0] - calc_int_len(val);
    int value = 0;

    if (size < 0)
        size = 0;
    if (flag[0] == '0')
        value += draw_line(c2, size);
    value += my_put_nbr(val);
    if (flag[0] == '1')
        value += draw_line(' ', size);
    return value;
}

int print_int_uns(unsigned long long val, char *flag, int *data, char c2)
{
    int size = data[0] - calc_int_len_uns(val);
    int value = 0;

    if (size < 0)
        size = 0;
    if (flag[0] == '0')
        value += draw_line(c2, size);
    value += my_put_nbr_uns(val);
    if (flag[0] == '1')
        value += draw_line(' ', size);
    return value;
}
int print_hex_sub(unsigned long long val, char *flag, int *data, char c2)
{
    int value = 0;

    if (c2 == ' ' && flag[0] == '0')
        value += draw_line(c2, data[3]);
    if (flag[2] == '1'){
        if (data[2] == 0)
            value += my_putstr("0x");
        else
            value += my_putstr("0X");
    }
    if (c2 == '0' && flag[0] == '0')
        value += draw_line(c2, data[3]);
    value += print_hex_val(val, data[2]);
    if (flag[0] == '1')
        value += draw_line(' ', data[3]);
    return value;
}
int print_hex(unsigned long long val, char *flag, int *data, char c2)
{
    int size;
    int value = 0;
    unsigned long long number;

    if (val < 0)
        number = 4294967295 - ((val * -1) - 1);
    else
        number = val;
    if (flag[2] == '1')
        size = data[0] - (calc_division_num(number)+2);
    else
        size = data[0] - (calc_division_num(number));
    if (size < 0)
        size = 0;
    data[3] = size;
    value += print_hex_sub(number, flag, data, c2);
    return value;
}
