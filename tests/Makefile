##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## makefile test
##

NAME=	test_of_printf

TEST =	../include/my.h		\
	test_my_printf.c		\
	../lib/my_printf.c		\
	../lib/print1.c			\
	../lib/print2.c			\
	../lib/printm.c			\
	../lib/utils.c			\
	../lib/utils2.c			\
	../lib/utils3.c			\
	../lib/utils4.c			\
	../lib/utils5.c

unit_tests:
	make all -C ../lib
	make clean -C ../lib
	gcc -o $(NAME) $(TEST) --coverage -lcriterion -I ../include -L ../lib -lmy

clean:
	rm -f *.gcno
	rm -f *.gcda

fclean:
	rm -f test_of_printf

re:
	make unit_tests
	make clean

tests_run:
	./$(NAME) || true
