##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## makefile test
##

NAME=	test_of_printf

TEST =	test_my_printf.c	\
	../include/my.h		\
	../lib/my_printf.c	\
	../lib/print1.c		\
	../lib/print2.c		\
	../lib/printm.c		\
	../lib/utils.c		\
	../lib/utils2.c		\
	../lib/utils3.c		\
	../lib/utils4.c		\
	../lib/utils5.c

unit_tests:
	make all -C ../lib
	make clean -C ../lib
	gcc -o $(NAME2) $(TEST) --coverage -lcriterion -I ../include -L ../lib -lmy

clean:
	rm -f *.gcno
	rm -f *.gcda

fclean:
	rm -f test_of_printf

re:
	unit_tests
	clean

tests_run:
	./$(NAME)
