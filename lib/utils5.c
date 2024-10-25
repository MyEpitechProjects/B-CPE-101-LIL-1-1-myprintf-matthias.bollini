/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** utils2
*/

#include "../include/my.h"
#include <unistd.h>
#include <stdarg.h>

static double fix_double(double val)
{
    if (val < 1)
        return val * 10;
    else {
        while (val > 10)
            val = val / 10;
    }
    return val;
}

static int calc_int_len_science(long long val)
{
    int n = 0;

    if (val == 0)
        return -1;
    if (val < 0){
        val = val * -1;
    }
    while (val > 0){
        n += 1;
        val = val / 10;
    }
    return n - 1;
}

static int my_put_float_sub3_scl(int *tab, int tab2[], int pre, int padding)
{
    int number = 0;

    if (pre > 0){
        number += 1;
        for (int i = 0; i < pre; i++)
            number += 1;
    }
    if (tab2[3] == 49 && (pre == 0))
        number += 1;
    number += 1;
    if (padding > -1)
        number += 1;
    else {
        number += 1;
        padding = padding * -1;
    }
    if (padding < 10)
        number += 1;
    number += calc_int_len(padding);
    return number;
}

static int my_put_float_sub3_sc(int *tab, int tab2[], int pre, int padding)
{
    int number = 0;

    if (pre > 0){
        number += my_putchar('.');
        for (int i = 0; i < pre; i++)
            number += my_putchar(48 + tab[i]);
    }
    if (tab2[3] == 49 && (pre == 0))
        number += my_putchar('.');
    if (tab2[6] == 0)
        number += my_putchar('e');
    else if (tab2[6] == 1)
        my_putchar('E');
    return number;
}

static int my_put_float_sub2_scl(double dec, int pre, int *tab, int *tab2)
{
    int int_dec;
    int fixed_len = 0;
    int number = 0;

    for (int i = 0; i <= pre; i++){
        int_dec = (dec * 10) / 1;
        tab[i] = int_dec;
        dec = (dec * 10) - int_dec;
        if (((i == pre - 1) || (i == 0 && pre == 0))
            && ((int) (dec * 10)) >= 5){
            tab[i] += 1;
            fixed_len = (int) fix_tab(pre, tab);
        }
    }
    number += calc_int_len((tab2[0]+fixed_len) * tab2[1]);
    return number;
}

static int my_put_float_sub2_sc(double dec, int pre, int *tab, int *tab2)
{
    int int_dec;
    int fixed_len = 0;
    int number = 0;

    for (int i = 0; i <= pre; i++){
        int_dec = (dec * 10) / 1;
        tab[i] = int_dec;
        dec = (dec * 10) - int_dec;
        if (((i == pre - 1) || (i == 0 && pre == 0))
            && ((int) (dec * 10)) >= 5){
            tab[i] += 1;
            fixed_len = (int) fix_tab(pre, tab);
        }
    }
    number += my_put_nbr((tab2[0]+fixed_len) * tab2[1]);
    return number;
}

static int my_put_float_sub_scl(double dec, int pre, int *tab, int tab2[])
{
    int number = 0;
    int padding = calc_int_len_science(tab2[5]);

    number += my_put_float_sub2_scl(dec, pre, tab, tab2);
    number += my_put_float_sub3_scl(tab, tab2, pre, padding);
    return number;
}

static int my_put_float_sub_sc(double dec, int pre, int *tab, int tab2[])
{
    int number = 0;
    int padding = calc_int_len_science(tab2[5]);

    number += my_put_float_sub2_sc(dec, pre, tab, tab2);
    number += my_put_float_sub3_sc(tab, tab2, pre, padding);
    if (padding > -1)
        number += my_putchar('+');
    else {
        number += my_putchar('-');
        padding = padding * -1;
    }
    if (padding < 10)
        number += my_putchar('0');
    number += my_put_nbr(padding);
    return number;
}

int my_put_science_float(double nbr, int pre, char *flag)
{
    int number = 0;
    int tab[pre + 1];
    int tab2[7];
    int value;
    int minus = 1;

    if (nbr < 0){
        nbr = nbr * - 1;
        minus = - 1;
    }
    value = (int) (fix_double(nbr) / 1);
    tab2[5] = (int) ((nbr) / 1);
    nbr = ((double) fix_double(nbr) - value);
    tab2[0] = value;
    tab2[1] = minus;
    tab2[3] = flag[2];
    tab2[6] = (int) flag[6];
    number += my_put_float_sub_sc(nbr, pre, tab, tab2);
    return number;
}

int my_put_science_float_len(double nbr, int pre, char *flag)
{
    int number = 0;
    int tab[pre + 1];
    int tab2[6];
    int value;
    int minus = 1;

    if (nbr < 0){
        nbr = nbr * - 1;
        minus = - 1;
    }
    value = (int) (fix_double(nbr) / 1);
    tab2[5] = (int) ((nbr) / 1);
    nbr = ((double) fix_double(nbr) - value);
    tab2[0] = value;
    tab2[1] = minus;
    tab2[3] = flag[2];
    number += my_put_float_sub_scl(nbr, pre, tab, tab2);
    return number;
}
