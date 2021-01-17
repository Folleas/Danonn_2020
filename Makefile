##
## EPITECH PROJECT, 2020
## Maths
## File description:
## Makefile
##

SRC	=	src/main.cpp

EXEC = 301dannon

all:	301dannon

$(EXEC):
		g++ -o 301dannon -g3 $(SRC)

clean:
		rm -f 301dannon

fclean: clean

re:		clean all
