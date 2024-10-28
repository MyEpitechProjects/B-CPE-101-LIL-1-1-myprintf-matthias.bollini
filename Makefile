##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## makefile my_printf
##

all:
	make -C lib/

unit_tests:
	make unit_tests -C tests/

clean:
	make clean -C lib/
	make clean -C tests/

tests_run:
	make tests_run

fclean:
	make fclean -C lib/
	make fclean -C tests/

re:
	make all -C lib/
	make unit_tests -C tests/
	make clean -C lib/
	make clean -C tests/
