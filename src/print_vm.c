/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** print_vm.c
*/

#include "corewar.h"
#include "my.h"
#include "my_printf.h"

void print_vm(corewar_t *corewar)
{
    int i = 0;

    my_printf("0x%08x", i);
    my_printf(" : ");
    for (i = 0; i < MEM_SIZE; i++) {
        if (i % 32 == 0 && i != 0) {
            my_printf("\n");
            my_printf("0x%08x", i);
            my_printf(" : ");
        }
        my_printf("%02x", corewar->arena->memory[i]);
        if (i % 32 != 31)
            my_printf(" ");
    }
    my_printf("\n");
}