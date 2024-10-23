#include "my.h"
#include <stdio.h>

int main(void)
{
    my_printf("\n\nTextes afficher avec my_printf et printf pour comparer : \n\n");
    int a = my_printf("%05d\n",50);
    int b = my_printf("(005) Value : %-*dM\n",3,5);
    my_printf("\n%d\n%d\n",a,b);
    my_putstr("\n\n");
    int a2 = printf("%05d\n",50);
    int b2 = printf("(005) Value : %-*dM\n",3,5);
    printf("\n%d\n%d\n",a2,b2);
    
    my_putstr("\n\n");
    int n;
    printf("%s: %nFoo\n", "hello", &n);
    printf("%*sBar\n", n, "");
    my_putstr("\n\n");
    int n2;
    my_printf("%s: %nFoo\n", "hello", &n2);
    my_printf("%*sBar\n", n2, "");

    my_putstr("\n\n");
    int number    =  5;
    char *pointer = "little";
    printf("Here is a number-%*d-and a-%*s-word.\n",4, number,10, pointer);

    my_putstr("\n\n");
    int number2    =  5;
    char *pointer2 = "little";

    my_printf("Here is a number-%*d-and a-%*s-word.\n",4, number,10, pointer);
    my_printf("\nTest : %-*.*soh",5,2,"bonjour");
    my_printf("\nTest : %-*.*soh",5,0,"bonjour");
    my_printf("\nTest : %-*.*soh",5,80,"bonjour");
    my_printf("\nTest : %-*.*soh",5,-1,"bonjour");

    my_putstr("\n\n");
    printf("\nTest : %-*.*soh",5,2,"bonjour");
    printf("\nTest : %-*.*soh",5, 0,"bonjour");
    printf("\nTest : %-*.*soh",5,80,"bonjour");
    printf("\nTest : %-*.*soh\n",5,-1,"bonjour");
    my_putchar('\n');
    my_putstr("\n\n");
    int number3=5;
    printf("---%*d----\n", 6, number3);
    my_putstr("\n\n");
    int number4=5;
    my_printf("---%*d----\n", 6, number4);
    int val2 = my_printf("%-#05xd",16);
    my_printf("\nhello%05d",10);
    my_printf("\nsq%hh",99999999548);
    printf("\n%",50);
}
