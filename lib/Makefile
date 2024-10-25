##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## makefile my_printf
##

NAME =  libmy.a

NAME_TEST = test_of_printf

SRC =   $(wildcard *.c)

SRC2 =	$(wildcard *.gcno)

TEST =	../tests/test_my_printf.c	\
	../include/my.h			\
	my_printf.c			\
	print1.c			\
	print2.c			\
	printm.c			\
	utils.c				\
	utils2.c			\
	utils3.c			\
	utils4.c

OBJ =   $(SRC:.c=.o)

all:    $(NAME)

$(NAME):        $(OBJ)
	ar rc $(NAME) $(OBJ)

test:
	gcc $(NAME_TEST) $(TEST) --coverage -lcriterion

clean:
	rm -f $(OBJ)
	rm -f $(SRC2)

fclean: clean
	rm -f libmy.a
	rm -f test_of_printf

re: all clean

copy:
	cp my.h ../../include
	cp libmy.a ../
