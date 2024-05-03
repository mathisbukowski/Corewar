##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Day 10 Task 01
##

SRC =   my_compute_power_rec.c \
	my_compute_square_root.c \
	my_find_prime_sup.c \
	my_getnbr.c \
	my_isneg.c \
	my_is_prime.c \
	my_putchar.c \
	my_put_nbr.c \
	my_putstr.c \
	my_revstr.c \
	my_showmem.c \
	my_showstr.c \
	my_sort_int_array.c \
	my_strcapitalize.c \
	my_strcat.c \
	my_strcmp.c \
	my_strcpy.c \
	my_str_isalpha.c \
	my_str_islower.c \
	my_str_isnum.c \
	my_str_isprintable.c \
	my_str_isupper.c \
	my_strlen.c \
	my_strlowcase.c \
	my_strncat.c \
	my_strncmp.c \
	my_strncpy.c \
	my_strstr.c \
	my_strupcase.c \
	my_swap.c \
	d_i_s_c_o_flags.c \
	flag_e.c \
	flag_e_maj.c \
	flag_g.c \
	my_printf.c \
	n_p_modulo_flags.c \
	x_u_f_flags.c \
	my_put_nbr_f_flag.c \
	my_str_to_word_array.c \
	my_strdup.c \
	my_memcpy.c \
	my_realloc.c \
	my_atoi.c \
	my_strchr.c \
	my_itoa.c \
	my_memset.c \

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all : $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)


clean :
	rm $(OBJ)

fclean : clean
		rm $(NAME)

re : fclean all
