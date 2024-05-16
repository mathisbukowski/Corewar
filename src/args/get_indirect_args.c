/*
** EPITECH PROJECT, 2024
** corewar-dev
** File description:
** get_indirect_args.c
*/

#include "corewar.h"

int get_indirect_argument(corewar_t *corewar, int pc)
{
    int arg = (int)corewar->arena->memory[(pc) % MEM_SIZE] << 8
    | corewar->arena->memory[(pc + 1) % MEM_SIZE];

    if (arg & 0x8000)
        arg -= 0x10000;
    return arg;
}
