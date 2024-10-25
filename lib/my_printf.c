/*
** EPITECH PROJECT, 2024
** mini_printf
** File description:
** mini_printf
*/

#include <stdarg.h>
#include "../include/my.h"
#include <stdio.h>

static int handler_size(const char *format, int *idx, va_list list)
{
    int size = 0;
    int old_idx = *idx;
    int sz = 0;

    while (is_num(format[*idx])){
        sz += 1;
        *idx += 1;
    }
    *idx = old_idx;
    while (is_num(format[*idx])){
        size += (format[*idx] - 48) * power(10, sz - 1);
        sz -= 1;
        *idx += 1;
    }
    return size;
}

static char handler_flag(const char *format, int *idx, char *neg)
{
    while (is_flg(format[*idx])) {
        if (format[*idx] == '-')
            neg[0] = '1';
        if (format[*idx] == ' ')
            neg[1] = '1';
        if (format[*idx] == '#')
            neg[2] = '1';
        if (format[*idx] == '+')
            neg[3] = '1';
        if (format[*idx] == '0')
            neg[4] = '1';
        *idx += 1;
    }
    return (0);
}

static int handler_spe2(const char *format, va_list list, int *idx, int *data)
{
    if (format[*idx] == '*'){
        data[0] = va_arg(list, int);
        *idx += 1;
    } else if (is_num(format[*idx]))
        data[0] = handler_size(format, idx, list);
    if (format[*idx] == '.' && format[*idx + 1] != '*'){
        *idx += 1;
        data[1] = handler_size(format, idx, list);
    } else if (format[*idx] == '.' && format[*idx + 1] == '*'){
        *idx += 2;
        data[1] = va_arg(list, int);
    }
    return 0;
}

static int handler_len_modif3(const char *format, int *idx, char *flag)
{
    if (format[*idx] == 'z' || format[*idx] == 'Z'){
        flag[5] = 7;
        *idx += 1;
        return 0;
    }
    if (format[*idx] == 't'){
        flag[5] = 8;
        *idx += 1;
        return 0;
    }
    return 0;
}

static int handler_len_modif2(const char *format, int *idx, char *flag)
{
    if (format[*idx] == 'L') {
        flag[5] = 5;
        *idx += 1;
        return 0;
    }
    if (format[*idx] == 'j') {
        flag[5] = 6;
        *idx += 1;
        return 0;
    }
    handler_len_modif3(format, idx, flag);
    return 0;
}

static int handler_len_modif(const char *format, int *idx, char *flag)
{
    if (format[*idx] == 'h'){
        if (format[*idx + 1] == 'h'){
            flag[5] = 1;
            *idx += 1;
        } else
            flag[5] = 2;
        *idx += 1;
        return 0;
    }
    if (format[*idx] == 'l' || format[*idx] == 'q'){
        if (format[*idx + 1] == 'l' || format[*idx] == 'q'){
            flag[5] = 4;
            *idx += 1;
        } else
            flag[5] = 3;
        *idx += 1;
        return 0;
    }
    handler_len_modif2(format, idx, flag);
    return 0;
}

static int handler_spe(const char *format, va_list list, int *idx)
{
    char flag[] = "000000000";
    int data[5] = {-1, -1, 0, 0};
    int value = 0;

    flag[6] = ' ';
    *idx += 1;
    handler_flag(format, idx, flag);
    handler_spe2(format, list, idx, data);
    handler_len_modif(format, idx, flag);
    value += print_formatted(format[*idx], list, data, flag);
    return value;
}

static int my_printf_sub2(const char *format, va_list list, int *idx, int nm)
{
    int *n;

    if (format[*idx] == '%' && format[*idx + 1] == '%'){
        *idx += 1;
        return my_putstr("%");
    }
    if (format[*idx] == '%' && format[*idx + 1] != 'n'){
        return handler_spe(format, list, idx);
    }
    if (format[*idx] == '%' && format[*idx + 1] == 'n'){
        *idx += 1;
        n = va_arg(list, int *);
        *n = nm;
        return 0;
    }
    return my_putchar(format[*idx]);
}

static int my_printf_sub1(const char *format, va_list list, int idx, int f)
{
    int num = 0;

    while (format[idx] != '\0') {
        num += my_printf_sub2(format, list, &idx, num);
        idx += 1;
    }
    va_end(list);
    return num;
}

int my_printf(const char *format, ...)
{
    va_list list;
    int idx = 0;

    va_start(list, format);
    return my_printf_sub1(format, list, idx, 0);
}
