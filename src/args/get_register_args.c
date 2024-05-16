/*
** EPITECH PROJECT, 2024
** corewar-dev
** File description:
** get_register_arg.c
*/

#include "corewar.h"

int get_register_argument(corewar_t *corewar, int pc)
{
    return (int)corewar->arena->memory[pc % MEM_SIZE];
}
