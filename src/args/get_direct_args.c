/*
** EPITECH PROJECT, 2024
** corewar-dev
** File description:
** get_direct_argument.c
*/

#include "corewar.h"
#include <stdio.h>

int get_direct_argument(corewar_t *corewar, int pc, int size)
{
    int arg = 0;
    int byte = 0;

    for (int i = 0; i < size; i++) {
        byte = (unsigned char)corewar->arena->memory[(pc + i) % MEM_SIZE];
        arg = (arg << 8) | byte;
    }
    return arg;
}
