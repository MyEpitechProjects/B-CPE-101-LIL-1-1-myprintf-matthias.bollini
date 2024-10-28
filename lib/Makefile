##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## makefile lib
##

NAME =  libmy.a

SRC =   my_printf.c	\
	print1.c	\
	print2.c	\
	printm.c	\
	utils.c		\
	utils2.c	\
	utils3.c	\
	utils4.c	\
	utils5.c

OBJ =   $(SRC:.c=.o)

all:    $(NAME)

$(NAME):        $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f libmy.a

re: all clean
