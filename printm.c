/*
** EPITECH PROJECT, 2024
** printm.c
** File description:
** printf fonction dictionnary
*/

#include "my.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>
static int print_formatted_sub7(char c, va_list list, int *data, char *flag)
{
    unsigned long long tmp;

    if ((c == 'o') && (flag[5] > 7 || flag[5] == 0)){
        tmp = va_arg(list, unsigned long long);
        if (flag[5] == 8)
            return print_uns(oct((ptrdiff_t) tmp), flag, data, flag[6]);
        return print_uns(oct((unsigned int) tmp), flag, data, flag[6]);
    }
    if (c == 'p'){
        flag[2] = '1';
        return print_hex(va_arg(list, unsigned long), flag, data, flag[6]);
    }
    if (c == 'f' || c == 'F'){
        if (data[1] == -1)
            data[1] = 6;
        return print_float(va_arg(list, double), flag, data, flag[6]);
    }
    return 0;
}

static int print_formatted_sub6(char c, va_list list, int *data, char *flag)
{
    unsigned long long tmp;

    if ((c == 'o') && (flag[5] != 0 && flag[5] != 5 && flag[5] < 8)){
        tmp = va_arg(list, unsigned long long);
        if (flag[5] == 1)
            return print_uns(oct((unsigned char) tmp), flag, data, flag[6]);
        if (flag[5] == 2)
            return print_uns(oct((unsigned short) tmp), flag, data, flag[6]);
        if (flag[5] == 3)
            return print_uns(oct((unsigned long) tmp), flag, data, flag[6]);
        if (flag[5] == 4)
            return print_uns(oct((unsigned long long) tmp),
                flag, data, flag[6]);
        if (flag[5] == 6)
            return print_uns(oct((uintmax_t) tmp), flag, data, flag[6]);
        if (flag[5] == 7)
            return print_uns(oct((size_t) tmp), flag, data, flag[6]);
    }
    return print_formatted_sub7(c, list, data, flag);
}

static int print_formatted_sub5(char c, va_list list, int *data, char *flag)
{
    unsigned long long tmp;

    if ((c == 'X' || c == 'x') && (flag[5] > 5 || flag[5] == 0)){
        if (c == 'X')
            data[2] = 1;
        tmp = va_arg(list, unsigned long long);
        if (flag[5] == 6)
            return print_hex((uintmax_t) tmp, flag, data, flag[6]);
        if (flag[5] == 7)
            return print_hex((size_t) tmp, flag, data, flag[6]);
        if (flag[5] == 8)
            return print_hex((ptrdiff_t) tmp, flag, data, flag[6]);
        return print_hex((unsigned int) tmp, flag, data, flag[6]);
    }
    if (c == 's')
        return print_str(va_arg(list, char *), flag, data);
    return print_formatted_sub6(c, list, data, flag);
}

static int print_formatted_sub4(char c, va_list list, int *data, char *flag)
{
    unsigned long long tmp;

    if ((c == 'X' || c == 'x') && flag[5] < 5 && flag[5] != 0){
        if (c == 'X')
            data[2] = 1;
        tmp = va_arg(list, unsigned long long);
        if (flag[5] == 1)
            return print_hex((unsigned char) tmp, flag, data, flag[6]);
        if (flag[5] == 2)
            return print_hex((unsigned short) tmp, flag, data, flag[6]);
        if (flag[5] == 3)
            return print_hex((unsigned long) tmp, flag, data, flag[6]);
        if (flag[5] == 4)
            return print_hex((unsigned long long) tmp, flag, data, flag[6]);
    }
    return print_formatted_sub5(c, list, data, flag);
}

static int print_formatted_sub3(char c, va_list list, int *data, char *flag)
{
    unsigned long long tmp;

    if (c == 'u' && (flag[5] > 2 || (flag[5] == 0 && flag[5] != 5))){
        tmp = va_arg(list, unsigned long long);
        if (flag[5] == 3)
            return print_uns((unsigned long) tmp, flag, data, flag[6]);
        if (flag[5] == 4)
            return print_uns((unsigned long long) tmp, flag, data, flag[6]);
        if (flag[5] == 6)
            return print_uns((uintmax_t) tmp, flag, data, flag[6]);
        if (flag[5] == 7)
            return print_uns((size_t) tmp, flag, data, flag[6]);
        if (flag[5] == 8)
            return print_uns((ptrdiff_t) tmp, flag, data, flag[6]);
        return print_uns((unsigned int) tmp, flag, data, flag[6]);
    }
    if (c == 'c')
        return print_char(va_arg(list, int), flag, data);
    return print_formatted_sub4(c, list, data, flag);
}

static int print_formatted_sub2(char c, va_list list, int *data, char *flag)
{
    long long tmp;
    unsigned long long tmp2;

    if ((c == 'd' || c == 'i') && (flag[5] > 6 || flag[5] == 0)){
        tmp = va_arg(list, long long);
        if (flag[5] == 7)
            return print_int((ssize_t) tmp, flag, data, flag[6]);
        if (flag[5] == 8)
            return print_int((ptrdiff_t) tmp, flag, data, flag[6]);
        return print_int((int) tmp, flag, data, flag[6]);
    }
    if (c == 'u' && (flag[5] != 0 && flag[5] < 3)){
        tmp2 = va_arg(list, unsigned long long);
        if (flag[5] == 1)
            return print_uns((unsigned char) tmp2, flag, data, flag[6]);
        if (flag[5] == 2)
            return print_uns((unsigned short) tmp2, flag, data, flag[6]);
    }
    return print_formatted_sub3(c, list, data, flag);
}

int print_formatted(char c, va_list list, int *data, char *flag)
{
    long long tmp;

    if (flag[4] == '1')
        flag[6] = '0';
    if ((c == 'd' || c == 'i') &&
        (flag[5] != 0 && flag[5] != 5 && flag[5] < 7)){
        tmp = va_arg(list, long long);
        if (flag[5] == 1)
            return print_int((signed char) tmp, flag, data, flag[6]);
        if (flag[5] == 2)
            return print_int((signed short) tmp, flag, data, flag[6]);
        if (flag[5] == 3)
            return print_int((long) tmp, flag, data, flag[6]);
        if (flag[5] == 4)
            return print_int((long long) tmp, flag, data, flag[6]);
        if (flag[5] == 6)
            return print_int((intmax_t) tmp, flag, data, flag[6]);
    }
    return print_formatted_sub2(c, list, data, flag);
}
