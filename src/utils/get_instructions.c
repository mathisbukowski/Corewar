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
    int size = 2;

    if (code < 1 || code > 16)
        return 1;
    champ->instruct->opcode = code;
    get_coding_byte(coding_byte, champ->instruct);
    champ->instruct->num_args = get_nbr_args(code, champ->instruct);
    champ->cycle_to_wait = op_tab[code - 1].nbr_cycles;
    decode_arguments(corewar, champ, champ->instruct,
        champ->instruct->num_args);
    for (int i = 0; i < champ->instruct->num_args; i++)
        size += get_arg_size(code, i, champ->instruct->types);
    return size;
}

int get_no_coding_byte_instruction(corewar_t *corewar, champion_t *champion,
    int code)
{
    int size = 1;
    op_t *op = NULL;

    for (int i = 0; op_tab[i].mnemonique != 0; i++)
        if (op_tab[i].code == code) {
            op = &op_tab[i];
            break;
        }
    if (!op)
        return size;
    champion->instruct->opcode = op->code;
    for (int i = 0; i < op->nbr_args; i++)
        champion->instruct->types[i] = 'd';
    champion->cycle_to_wait = op->nbr_cycles;
    decode_no_coding_byte(corewar, champion, champion->instruct, op->nbr_args);
    for (int i = 0; i < op->nbr_args; i++)
        size += get_arg_size(code, i, champion->instruct->types);
    return size;
}

int get_instructions(corewar_t *corewar, champion_t *champ)
{
    int code;
    int size = 0;

    if (champ->instruct != NULL)
        free(champ->instruct);
    champ->instruct = malloc(sizeof(instruction_t));
    my_memset(champ->instruct, 0, (sizeof(instruction_t)));
    code = (int)corewar->arena->memory[(champ->pc) % MEM_SIZE];
    if (!has_coding_byte(code))
        size += get_instr_normal(corewar, champ, code);
    else
        size += get_no_coding_byte_instruction(corewar, champ, code);
    champ->instruct->encoding_byte = size;
    return 0;
}
