/*
** EPITECH PROJECT, 2024
** corewar-dev
** File description:
** decode_instructions.c
*/

#include "corewar.h"

void decode_arguments(corewar_t *corewar, champion_t *champ,
    instruction_t *instr, int nb)
{
    int pc = (champ->pc + 2) % MEM_SIZE;
    int size = 0;

    for (int i = 0; i < nb; i++) {
        size = get_arg_size(instr->opcode, i, instr->types);
        if (instr->types[i] == 'r')
            instr->args[i] = get_register_argument(corewar, pc);
        if (instr->types[i] == 'i')
            instr->args[i] = get_indirect_argument(corewar, pc);
        if (instr->types[i] == 'd')
            instr->args[i] = get_direct_argument(corewar, pc, size);
        pc = (pc + size) % MEM_SIZE;
    }
}

void decode_no_coding_byte(corewar_t *corewar, champion_t *champ,
    instruction_t *instr, int nb)
{
    int pc = (champ->pc + 1) % MEM_SIZE;
    int size = 1;

    for (int i = 0; i < nb; i++) {
        size = get_arg_size(instr->opcode, i, instr->types);
        if (instr->types[i] == 'r')
            instr->args[i] = get_register_argument(corewar, pc);
        if (instr->types[i] == 'i')
            instr->args[i] = get_indirect_argument(corewar, pc);
        if (instr->types[i] == 'd')
            instr->args[i] = get_direct_argument(corewar, pc, size);
        pc = (pc + size) % MEM_SIZE;
    }
}
