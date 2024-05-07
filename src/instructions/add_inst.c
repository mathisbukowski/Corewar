/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** add_inst.c
*/

#include "corewar.h"

int add_command(instruction_t *instr, champion_t *champ, corewar_t *corewar)
{
    int reg1;
    int reg2;
    int reg3;

    if (!instr || !champ || !corewar)
        return -1;
    reg1 = instr->args[0];
    reg2 = instr->args[1];
    reg3 = instr->args[2];
    champ->reg[reg3] = champ->reg[reg1] + champ->reg[reg2];
    champ->carry = champ->reg[reg3] == 0 ? 1 : 0;
    return 0;
}

int sub_command(instruction_t *instr, champion_t *champ, corewar_t *corewar)
{
    int reg1;
    int reg2;
    int reg3;

    if (!instr || !champ || !corewar)
        return -1;
    reg1 = instr->args[0];
    reg2 = instr->args[1];
    reg3 = instr->args[2];
    champ->reg[reg3] = champ->reg[reg1] - champ->reg[reg2];
    champ->carry = champ->reg[reg3] == 0 ? 1 : 0;
    return 0;
}
