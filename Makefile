##
## EPITECH PROJECT, 2024
## navy
## File description:
## Makefile for navy project
##

SRC = src/main.c \
		src/utils/print_usage.c \
		src/utils/init_struct.c \
		src/utils/free_struct.c \
		src/utils/check_dump.c \
		src/error/check_args.c \

NAME = corewar

LIB = -L./lib/my -lmy

CFLAGS = -g -I./include -Wall -Wextra

all : $(NAME)

$(NAME) :
	if [ ! -f "lib/my/libmy.a" ]; then make -C lib/my; fi
	gcc $(CFLAGS) $(SRC) -o $(NAME) $(LIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
