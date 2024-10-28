##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## makefile test
##

NAME=	test_of_printf

TEST =	../include/my.h		\
	test_my_printf.c

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
	./$(NAME)
