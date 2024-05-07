/*
** EPITECH PROJECT, 2024
** corewar-dev
** File description:
** logical_inst.c
*/

#include "corewar.h"

static void perform_logical(instruction_t *instr, champion_t *champ, int res)
{
    if (instr->types[0] == 'r' && instr->types[1] == 'r')
        champ->reg[instr->args[2]] = res;
    else
        champ->reg[instr->args[1]] = res;
    champ->carry = res == 0 ? 1 : 0;
}

int and_command(instruction_t *instr, champion_t *champ, corewar_t *corewar)
{
    int param1;
    int param2;

    if (!instr || !champ || !corewar)
        return -1;
    if (instr->types[1] == 'r')
        param1 = champ->reg[instr->args[1]];
    else
        param1 = instr->args[1];
    if (instr->types[2] == 'r')
        param2 = champ->reg[instr->args[2]];
    else
        param2 = instr->args[2];
    perform_logical(instr, champ, param1 & param2);
    return 0;
}

int or_command(instruction_t *instr, champion_t *champ, corewar_t *corewar)
{
    int param1;
    int param2;

    if (!instr || !champ || !corewar)
        return -1;
    if (instr->types[1] == 'r')
        param1 = champ->reg[instr->args[1]];
    else
        param1 = instr->args[1];
    if (instr->types[2] == 'r')
        param2 = champ->reg[instr->args[2]];
    else
        param2 = instr->args[2];
    perform_logical(instr, champ, param1 | param2);
    return 0;
}

int xor_command(instruction_t *instr, champion_t *champ, corewar_t *corewar)
{
    int param1;
    int param2;

    if (!instr || !champ || !corewar)
        return -1;
    if (instr->types[1] == 'r')
        param1 = champ->reg[instr->args[1]];
    else
        param1 = instr->args[1];
    if (instr->types[2] == 'r')
        param2 = champ->reg[instr->args[2]];
    else
        param2 = instr->args[2];
    perform_logical(instr, champ, param1 ^ param2);
    return 0;
}
