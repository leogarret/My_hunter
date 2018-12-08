##
## EPITECH PROJECT, 2018
## Made by Léo Garret
## File description:
## Makefile
##

SRC		=	src/main.c \
			src/bird.c \
			src/event_manager.c \
			src/functions.c \
			src/game_init.c \
			src/graphics.c \
			src/hunter.c \
			src/init.c

OBJ     =       $(SRC:.c=.o)

CC	=	gcc

WFLAGS	=	-W -Wall -Werror -Wextra -pedantic

CFLAGS	=	-I./include

NAME	=	my_hunter

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(WFLAGS) $(OBJ) -o $(NAME) $(CFLAGS) -lcsfml-graphics -lcsfml-window -lcsfml-system
clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
