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

static int get_nbr_args(int opcode, instruction_t *instr)
{
    int i;

    for (i = 0; instr->types[i] != '\0' && i < 3; i++);
    return i;
}

int get_arg_size(int code, int i, char types[3])
{
    if (code == 9 || code == 12)
        return IND_SIZE;
    if (types[i] == 'r')
        return 1;
    if (types[i] == 'i')
        return IND_SIZE;
    if (has_idx(code, i + 1))
        return IND_SIZE;
    return DIR_SIZE;
}

int get_instr_normal(corewar_t *corewar, champion_t *champ, int code)
{
    int coding_byte = (int)corewar->arena->memory[(champ->pc + 1) % MEM_SIZE];
    instruction_t instruction = {.opcode = code};
    int size = 2;

    if (code < 1 || code > 16)
        return 1;
    get_coding_byte(coding_byte, &instruction);
    instruction.num_args = get_nbr_args(code, &instruction);
    instruction.cycles_to_wait = op_tab[code - 1].nbr_cycles;
    decode_arguments(corewar, champ, &instruction, instruction.num_args);
    for (int i = 0; i < instruction.num_args; i++)
        size += get_arg_size(code, i, instruction.types);
    return size;
}

int get_no_coding_byte_instruction(corewar_t *corewar, champion_t *champion,
    int code)
{
    int size = 1;
    instruction_t instruction;
    op_t *op = NULL;

    for (int i = 0; op_tab[i].mnemonique != 0; i++)
        if (op_tab[i].code == code) {
            op = &op_tab[i];
            break;
        }
    if (!op)
        return size;
    instruction.opcode = op->code;
    for (int i = 0; i < op->nbr_args; i++)
        instruction.types[i] = 'd';
    decode_no_coding_byte(corewar, champion, &instruction, op->nbr_args);
    for (int i = 0; i < op->nbr_args; i++)
        size += get_arg_size(code, i, instruction.types);
    return size;
}

int get_instructions(corewar_t *corewar, champion_t *champ)
{
    int code;
    int size = 0;

    code = (int)corewar->arena->memory[(champ->pc) % MEM_SIZE];
    if (!has_coding_byte(code))
        size += get_instr_normal(corewar, champ, code);
    else
        size += get_no_coding_byte_instruction(corewar, champ, code);
    champ->pc = (champ->pc + size) % MEM_SIZE;
    return 0;
}
