/*
** EPITECH PROJECT, 2024
** C Pool Day 07
** File description:
**  libmy.h
*/

#ifndef LIBMY_H_
    #define LIBMY_H_
#include <stdarg.h>
int my_putchar(char c);
int my_put_nbr(long long nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_put_nbr_uns(unsigned long long nb);
int calc_int_len(unsigned long long val);
int calc_int_len_uns(unsigned long long val);
int draw_line(char c, int val);
int my_putstrn(char const *str, int n);
int my_printf(const char *format, ...);
int is_num(char c);
int is_flg(char c);
long long power(long long nb, int p);
int print_str(char *val, char *flag, int *data);
int print_char(char val, char *flag, int *data);
int print_int(long long val, char *flag, int *data, char c2);
int print_uns(unsigned long long val, char *flag, int *data, char c2);
int print_hex(unsigned long long val, char *flag, int *data, char c2);
int calc_division_num(unsigned long long nb);
int print_hex_val(unsigned long long nb, int is_upper);
int print_hex_sub(unsigned long long val, char *flag, int *data, char c2);
int print_formatted(char c, va_list list, int *data, char *flag);
unsigned long long oct(unsigned long long nb);
int my_put_float(double nbr, int pre);
int calc_float_len(double nbr, unsigned int pre);
int print_float(double val, char *flag, int *data, char c2);
#endif
