/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** utils2
*/


#include "my.h"
#include <unistd.h>
#include <stdarg.h>

static int fix_tab(int pre, int *tab)
{
    for (int i = pre-1; i > -1; i--){
        if (tab[i] < 10)
            return 0;
        if (tab[i] > 9 && i != 0){
            tab[i] = 0;
            tab[i-1] += 1;
        }
        if (tab[i] > 9 && i == 0){
            tab[i] = 0;
            return 1;
        }
    }
    return 0;
}
/*static int calc_integer_len(long long nb)
{
    int val = 0;

    while (nb > 0){
        val+=1
        nb = nb / 10;
    }
    return val;
}*/
static int my_put_float_len_sub(double dec, int pre, int *tab, int *tab2)
{
    int fixed_len;
    int number = 0;
    int int_dec;
    
    for (int i = 0; i < pre; i++){
        int_dec = (dec*10)/1;
	tab[i] = int_dec;
        dec = (dec*10)-int_dec;
	if (i == pre-1 && ((int) (dec*10)) >= 5){
            tab[i] += 1;
            fixed_len = fix_tab(pre, tab);
        }
    }
    number += calc_int_len(tab2[0]+fixed_len * -tab2[1]);
    if (pre > 0){
        number += 1;
        for (int i = 0; i < pre; i++)
            number += 1;
    }
    return number;
}
static int my_put_float_sub(double dec, int pre, int *tab, int *tab2)
{
    int fixed_len;
    int number = 0;
    int int_dec;
    
    for (int i = 0; i < pre; i++){
        int_dec = (dec*10)/1;
	tab[i] = int_dec;
        dec = (dec*10)-int_dec;
	if (i == pre-1 && ((int) (dec*10)) >= 5){
            tab[i] += 1;
            fixed_len = fix_tab(pre, tab);
        }
    }
    number += my_put_nbr(tab2[0]+fixed_len * -tab2[1]);
    if (pre > 0){
        number += my_putchar('.');
        for (int i = 0; i < pre; i++)
            number += my_putchar(48+tab[i]);
    }
    return number;
}
int calc_float_len(double nbr, unsigned int pre)
{
    int number = 0;
    int idx = pre;
    int tab[pre+1];
    int tab2[3];
    int value;
    double dec;
    int minus = 0;
    
    if (nbr < 0){
        nbr = nbr * -1;
        minus = 1;
    }
    value = (int) nbr;
    dec = ((double) nbr)-value;
    tab2[0]=value;
    tab2[1]=minus;
    number += my_put_float_len_sub(dec, pre, tab, tab2);
    return number;
}

int my_put_float(double nbr, int pre)
{
    int number = 0;
    int int_dec;
    int idx = pre;
    int tab[pre+1];
    int tab2[3];
    int value;
    double dec;
    int minus = 0;
    
    if (nbr < 0){
        nbr = nbr * -1;
        minus = 1;
    }
    value = (int) nbr;
    dec = ((double) nbr)-value;
    tab2[0]=value;
    tab2[1]=minus;
    number += my_put_float_sub(dec, pre, tab, tab2);
    return number;
}
