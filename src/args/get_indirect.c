/*
** EPITECH PROJECT, 2024
** corewar-dev
** File description:
** get_indirect.c
*/

#include "corewar.h"

int get_indirect_argument(corewar_t *corewar, champion_t *champ)
{
    int arg = (int)corewar->arena->memory[(champ->pc + 2) % MEM_SIZE] << 8
    | corewar->arena->memory[(champ->pc + 3) % MEM_SIZE];

    return arg;
}