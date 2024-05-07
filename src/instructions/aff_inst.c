/*
** EPITECH PROJECT, 2024
** corewar-dev
** File description:
** aff_inst.c
*/

#include "corewar.h"

int aff_command(instruction_t *instr, champion_t *champ, corewar_t *corewar)
{
    int reg = instr->args[0];
    int value = champ->reg[reg - 1];

    if (!instr || !champ || !corewar)
        return -1;
    my_putchar(value % 256);
    return 0;
}
