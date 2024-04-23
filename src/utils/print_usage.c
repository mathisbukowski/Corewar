/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** print_usage.c
*/

#include "my_printf.h"

void print_usage(void)
{
    my_printf("USAGE\n");
    my_printf("./corewar [-dump nbr_cycle] [[-n prog_number] ");
    my_printf("[-a load_address] prog_name] ...\n");
    my_printf("DESCRIPTION\n");
    my_printf("-dump nbr_cycle dumps the memory after the nbr_cycle ");
    my_printf("execution (if the round isn't ");
    my_printf("already over) with the following format: 32 bytes/line ");
    my_printf("in hexadecimal (A0BCDEFE1DD3...)\n");
    my_printf("-n prog_number sets the next program's number. By default, ");
    my_printf("the first free number in the ");
    my_printf("parameter order\n");
    my_printf("-a load_address sets the next program's loading address. ");
    my_printf("When no address is ");
    my_printf("specified, optimize the addresses so that the processes ");
    my_printf("are as far away from each");
    my_printf("other as possible. The addresses are MEM_SIZE modulo.\n");
}
