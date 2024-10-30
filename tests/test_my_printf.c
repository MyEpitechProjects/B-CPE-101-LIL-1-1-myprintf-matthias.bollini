/*
** EPITECH PROJECT, 2024
** test_my_printf.c
** File description:
** test my_printf
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, complex_string, .init = redirect_all_std)
{
    my_printf("\n\nTextes afficher avec my_printf et printf pour comparer : \n\n");
    cr_assert_stdout_eq_str("\n\nTextes afficher avec my_printf et printf pour comparer : \n\n");
}

Test(my_printf, test_du_d, .init = redirect_all_std)
{
    my_printf("%05d\n",50);
    cr_assert_stdout_eq_str("00050\n");
}

Test(my_printf, test_du_d2, .init = redirect_all_std)
{
    int a = my_printf("%05d\n",50);
    int b = my_printf("(005) Value : %-*dM\n",3,5);
    
    my_printf("\n%d\n%d\n",a,b);
    cr_assert_stdout_eq_str("00050\n(005) Value : 5  M\n\n6\n19\n");
}

Test(my_printf, test_du_n_plus_s, .init = redirect_all_std)
{
    int n2 = 50;
    my_printf("%s: %nFoo\n", "hello", &n2);
    my_printf("%*sBar\n", n2, "");
    cr_assert_stdout_eq_str("hello: Foo\n       Bar\n");
}

Test(my_printf, test_du_star, .init = redirect_all_std)
{
    int number =  5;
    char *pointer = "little";
    
    my_printf("Here is a number-%*d-and a-%*s-word.\n",4, number,10, pointer);
    cr_assert_stdout_eq_str("Here is a number-   5-and a-    little-word.\n");
}

Test(my_printf, test_impossible, .init = redirect_all_std)
{
    my_printf("%#.0f", -123.456);
    cr_assert_stdout_eq_str("-123.");
}

Test(my_pritnf, test_impossible2, .init = redirect_all_std)
{
    my_printf("%#.0f", 123.456);
    cr_assert_stdout_eq_str("123.");
}

Test(my_printf, test_impossible3, .init = redirect_all_std)
{
    my_printf("%.0f", -123.456);
    cr_assert_stdout_eq_str("-123");
}

Test(my_printf, test_impossible4, .init = redirect_all_std)
{
    my_printf("%.0f", 123.456);
    cr_assert_stdout_eq_str("123");
}

Test(my_printf, test_impossible5, .init = redirect_all_std)
{
    my_printf("%056d%s%010i", 1257, "bonjour", 568687);
    cr_assert_stdout_eq_str("00000000000000000000000000000000000000000000000000001257bonjour0000568687");
}
