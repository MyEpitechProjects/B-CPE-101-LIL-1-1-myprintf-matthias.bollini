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

Test(my_printf, test_du_d, .init = redirect_all_std)
{
    my_printf("%05d",123);
    cr_assert_stdout_eq_str("00123");
}

Test(my_printf, test_du_i, .init = redirect_all_std)
{
    my_printf("%15i\n",50);
    cr_assert_stdout_eq_str("             50\n");
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

Test(my_printf, test_impossible2, .init = redirect_all_std)
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
Test(my_printf, test_printf36, .init = redirect_all_std)
{
    my_printf("%ho",1250000000);
    cr_assert_stdout_eq_str("76200");
}
Test(my_printf, test_printf37, .init = redirect_all_std)
{
    my_printf("%hu",36500);
    cr_assert_stdout_eq_str("36500");
}
Test(my_printf, test_printf38, .init = redirect_all_std)
{
    my_printf("%x",789000);
    cr_assert_stdout_eq_str("c0a08");
}
Test(my_printf, test_h_all_len_modif, .init = redirect_all_std)
{
    long int b = 12500000000000000;
    long long int a = 1250000000000000000;
    my_printf("%hhd\n,%hd\n,%ld\n,%lld\n,%jd\n,%zd\n,%td\n",1250000000,1250000000, b, a, b, b, b);
    cr_assert_stdout_eq_str("-128\n,31872\n,12500000000000000\n,1250000000000000000\n,12500000000000000\n,12500000000000000\n,12500000000000000\n");
}
Test(my_printf, test_printf40, .init = redirect_all_std)
{
    my_printf("%c",70);
    cr_assert_stdout_eq_str("F");
}
Test(my_printf, test_printfi, .init = redirect_all_std)
{
    long int d = 12500000000000000;
    long long int c = 1250000000000000000;
    my_printf("%hhi\n,%hi\n,%li\n,%lli\n,%ji\n,%zi\n,%ti\n",1250000000,1250000000, d, c, d, d, d);
    cr_assert_stdout_eq_str("-128\n,31872\n,12500000000000000\n,1250000000000000000\n,12500000000000000\n,12500000000000000\n,12500000000000000\n");
}
Test(my_printf, tests_of_o, .init = redirect_all_std)
{
    long int e = 12500000000000000;
    long long int f = 1250000000000000000;
    my_printf("%hho\n,%ho\n,%lo\n,%jo\n,%zo\n,%to\n",1250000000,1250000000, e, e, e, e);
    cr_assert_stdout_eq_str("200\n,76200\n,543212741354240000\n,543212741354240000\n,543212741354240000\n,543212741354240000\n");
}
Test(my_printf, tests_of_u, .init = redirect_all_std)
{
    int g = 12500000;
    long int u = 46164516166544;
    long long int h = 5432164;
    my_printf("%hhu\n,%hu\n,%lu\n,%llu\n,%ju\n,%zu\n,%tu\n", 8456187, g, u, h, u, u, u);
    cr_assert_stdout_eq_str("251\n,48160\n,46164516166544\n,5432164\n,46164516166544\n,46164516166544\n,46164516166544\n");
}
Test(my_printf, tests_of_x, .init = redirect_all_std)
{
    long int i = 12500000000000000;
    long long int j = 1250000000000000000;
    my_printf("%hhx\n,%hx\n,%lx\n,%llx\n,%jx\n,%zx\n,%tx\n",1250000000,1250000000, i, j, i, i, i);
    cr_assert_stdout_eq_str("80\n,7c80\n,2c68af0bb14000\n,1158e460913d0000\n,2c68af0bb14000\n,2c68af0bb14000\n,2c68af0bb14000\n");
}
Test(my_printf, tests_of_e, .init = redirect_all_std)
{
    my_printf("%e\n", 15876556.688464698);
    cr_assert_stdout_eq_str("1.587656e+07\n");
}
Test(my_printf, tests_of_f, .init = redirect_all_std)
{
    my_printf("%f\n", 15876556.688464698);
    cr_assert_stdout_eq_str("15876556.688465\n");
}
Test(my_printf, flag_test, .init = redirect_all_std)
{
    void *a = "bonjour";
    my_printf("%d\n%i\n%o\n%u\n%x\n%e\n%f\n%c\n%s\n%p\n%%\n", 125, 250, 1254, 4587, 5698, 458.652, 478.619, 78, "bonjour", a);
    cr_assert_stdout_eq_str("125\n250\n2346\n4587\n1642\n4.586520e+02\n478.619000\nN\nbonjour\n0x5a411c599008\n%\n");
}