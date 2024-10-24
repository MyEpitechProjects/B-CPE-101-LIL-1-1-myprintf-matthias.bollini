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
    if (pre == 0)
        return tab[0] >= 5;
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

static int my_put_float_len_sub(double dec, int pre, int *tab, int *tab2)
{
    int fixed_len = 0;
    int number = 0;
    int int_dec;
    
    for (int i = 0; i <= pre; i++){
        int_dec = (dec*10)/1;
	tab[i] = int_dec;
        dec = (dec*10)-int_dec;
	if (((i == pre-1) || (i == 0 && pre == 0)) && ((int) (dec*10)) >= 5){
            tab[i] += 1;
            fixed_len = fix_tab(pre, tab);
        }
    }
    number += calc_int_len((tab2[0]+fixed_len) * tab2[1]);
    if (pre > 0){
        number += 1;
        for (int i = 0; i < pre; i++)
            number += 1;
    }
    return number;
}
static int my_put_float_sub(double dec, int pre, int *tab, int tab2[])
{
    int fixed_len = 0;
    int number = 0;
    int int_dec;
    
    for (int i = 0; i <= pre; i++){
        int_dec = (dec*10)/1;
	tab[i] = int_dec;
        dec = (dec*10)-int_dec;
	if (((i == pre-1) || (i == 0 && pre == 0)) && ((int) (dec*10)) >= 5){
            tab[i] += 1;
            fixed_len = (int) fix_tab(pre, tab);
        }
    }
    number += my_put_nbr((tab2[0]+fixed_len) * tab2[1]);
    if (pre > 0){
        number += my_putchar('.');
        for (int i = 0; i < pre; i++)
            number += my_putchar(48+tab[i]);
    }
    return number;
}
int calc_float_len(double nbr, unsigned int pre, char *flag)
{
    int number = 0;
    int idx = pre;
    int tab[pre+1];
    int tab2[3];
    int value;
    double dec;
    int minus = 1;
    
    if (nbr < 0){
        nbr = nbr * -1;
        minus = -1;
    }
    value = (int) nbr;
    dec = ((double) nbr)-value;
    tab2[0]=value;
    tab2[1]=minus;
    number += my_put_float_len_sub(dec, pre, tab, tab2);
    if (flag[2] == '1')
        number += 1;
    return number;
}

int my_put_float(double nbr, int pre, char *flag)
{
    int number = 0;
    int int_dec;
    int idx = pre;
    int tab[pre+1];
    int tab2[3];
    int value;
    double dec;
    int minus = 1;
    
    if (nbr < 0){
        nbr = nbr * -1;
        minus = -1;
    }
    value = (int) (nbr/1);
    dec = ((double) nbr)-value;
    tab2[0]=value;
    tab2[1]=minus;
    number += my_put_float_sub(dec, pre, tab, tab2);
    if (flag[2] == '1')
        number += my_putchar('.');
    return number;
}
