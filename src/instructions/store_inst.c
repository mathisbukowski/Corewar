/*
** EPITECH PROJECT, 2024
** corewar-dev
** File description:
** store_inst.c
*/

#include "corewar.h"

int st_command(instruction_t *instr, champion_t *champ, corewar_t *corewar)
{
    int register_val;
    int dest_value;
    int address;

    if (instr->types[0] != 'r')
        return 1;
    register_val = champ->reg[instr->args[0]];
    if (instr->types[1] == 'r')
        champ->reg[instr->args[1]] = register_val;
    else {
        address = instr->args[1];
        if (address < 0 || address >= MEM_SIZE)
            return 1;
        corewar->arena->memory[address] = register_val;
    }
}

int sti_command(instruction_t *instr, champion_t *champ, corewar_t *corewar)
{
    int reg_value = champ->reg[instr->args[0]];
    int param1;
    int param2;
    int address;

    if (instr->types[1] == 'r')
        param1 = champ->reg[instr->args[1]];
    else
        param1 = instr->args[1];
    if (instr->types[2] == 'r')
        param2 = champ->reg[instr->args[2]];
    else
        param2 = instr->args[2];
    address = (champ->pc + (param1 + param2) % IDX_MOD) % MEM_SIZE;
    if (address < 0)
        address += MEM_SIZE;
    corewar->arena->memory[address] = reg_value;
    return 0;
}
