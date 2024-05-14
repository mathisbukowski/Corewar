/*
** EPITECH PROJECT, 2024
** corewar-dev
** File description:
** aff_inst.c
*/

#include "corewar.h"

int aff_command(instruction_t *instr, champion_t *champ, corewar_t *corewar)
{
    int reg_value;
    char output_aff;

    if (!instr || !champ || !corewar)
        return -1;
    if (instr->types[0] != 'r' || instr->args[0] >= REG_NUMBER)
        return -1;
    reg_value = champ->reg[instr->args[0]];
    output_aff = reg_value % 256;
    my_putchar(output_aff);
    return 0;
}
