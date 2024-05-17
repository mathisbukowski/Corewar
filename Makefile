##
## EPITECH PROJECT, 2024
## navy
## File description:
## Makefile for navy project
##

SRC = src/main.c \
		src/op.c \
		src/run_vm.c \
		src/utils/print_usage.c \
		src/utils/init_struct.c \
		src/utils/free_struct.c \
		src/utils/check_dump.c \
		src/utils/print_vm.c \
		src/error/check_champions.c \
		src/error/check_args.c \
		src/instructions/load_inst.c \
		src/instructions/store_inst.c \
		src/instructions/fork_inst.c \
		src/instructions/add_inst.c \
		src/instructions/logical_inst.c \
		src/instructions/live_inst.c \
		src/instructions/check_arguments.c \
		src/instructions/aff_inst.c \
		src/instructions/array_function.c \
		src/champion/add_champion.c \
		src/file/get_file_data.c \
		src/utils/get_coding_byte.c \
		src/utils/has_coding_byte.c \
		src/utils/has_idx.c \
		src/utils/get_instructions.c \
		src/args/get_direct_args.c \
		src/args/get_indirect_args.c \
		src/args/get_register_args.c \
		src/utils/decode_instructions.c \

OBJ = $(SRC:.c=.o)

NAME = corewar

LIB = -L./lib/my -lmy

CFLAGS = -g -I./include -Wall -Wextra

all : $(NAME) post_build_clean

$(NAME) : $(OBJ)
	if [ ! -f "lib/my/libmy.a" ]; then make -C lib/my; fi
	gcc $(CFLAGS) $(SRC) -o $(NAME) $(LIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

post_build_clean:
	rm -f $(OBJ)
