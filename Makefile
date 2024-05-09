##
## EPITECH PROJECT, 2024
## navy
## File description:
## Makefile for navy project
##

SRC = src/main.c \
		src/op.c \
		src/utils/print_usage.c \
		src/utils/init_struct.c \
		src/utils/free_struct.c \
		src/utils/check_dump.c \
		src/error/check_champions.c \
		src/error/check_args.c \
		src/instructions/load_inst.c \
		src/instructions/store_inst.c \
		src/instructions/fork_inst.c \
		src/instructions/add_inst.c \
		src/instructions/logical_inst.c \
		src/instructions/check_arguments.c \
		src/instructions/aff_inst.c \
		src/champion/add_champion.c \
		src/file/get_file_data.c \

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
