/*
** EPITECH PROJECT, 2024
** corewar-dev
** File description:
** get_instructions.c
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "corewar.h"
#include "op.h"

static int get_nbr_args(unsigned char opcode, instruction_t *instr)
{
    int i;

    for (i = 0; instr->types[i] != '\0' && i < 3; i++);
    return 1;
}

int get_instr_normal(corewar_t *corewar, champion_t *champ)
{
    unsigned char code = corewar->arena->memory[champ->pc];
    int ac;
    instruction_t instruction = {.opcode = code};

    if (code < 1 || code > 16)
        return 1;
    get_coding_byte(corewar->arena->memory[(champ->pc + 1) % MEM_SIZE], &instruction);
    ac = get_nbr_args(code, &instruction);
}

int get_instructions(corewar_t *corewar, champion_t *champ)
{

}