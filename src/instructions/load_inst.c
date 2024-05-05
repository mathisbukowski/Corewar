/*
** EPITECH PROJECT, 2024
** corewar-dev
** File description:
** load_inst.c
*/

#include "corewar.h"

int ld_command(instruction_t *instr, champion_t *champ, corewar_t *corewar)
{
    int value = (instr->types[0] == 'r') ?
    champ->reg[instr->args[0]] : instr->args[0];
    int address = (champ->pc + (value % IDX_MOD)) % MEM_SIZE;

    if (address < 0)
        address += MEM_SIZE;
    my_memcpy(&champ->reg[instr->args[1]],
    &corewar->arena->memory[address], REG_SIZE);
    champ->carry = (champ->reg[instr->args[1]] == 0) ? 1 : 0;
    return 0;
}

int ldi_command(instruction_t *instr, champion_t *champ, corewar_t *corewar)
{
    int a = (instr->types[0] == 'r' ?
    champ->reg[instr->args[0]] : instr->args[0]);
    int b = (instr->types[1] == 'r' ?
    champ->reg[instr->args[1]] : instr->args[1]);
    int address = (champ->pc + (a % IDX_MOD)) % MEM_SIZE;
    int mid;
    int fin_add;

    if (address < 0)
        address += MEM_SIZE;
    my_memcpy(&mid, &corewar->arena->memory[address], IND_SIZE);
    fin_add = (champ->pc + ((mid + b) % IDX_MOD)) % MEM_SIZE;
    if (fin_add < 0)
        fin_add = (fin_add + MEM_SIZE) % MEM_SIZE;
    my_memcpy(&champ->reg[instr->args[2]],
    &corewar->arena->memory[fin_add], REG_SIZE);
    champ->carry = (champ->reg[instr->args[2]] ? 0 : 1);
    return 0;
}

int lld_command(instruction_t *instr, champion_t *champ, corewar_t *corewar)
{
    int value = (instr->types[0] == 'r') ?
    champ->reg[instr->args[0]] : instr->args[0];
    int address = (champ->pc + value) % MEM_SIZE;

    if (address < 0)
        address += MEM_SIZE;
    my_memcpy(&champ->reg[instr->args[1]],
    &corewar->arena->memory[address], REG_SIZE);
    champ->carry = (champ->reg[instr->args[1]] == 0) ? 1 : 0;
    return 0;
}

int lldi_command(instruction_t *instr, champion_t *champ, corewar_t *corewar)
{
    int a = (instr->types[0] == 'r' ?
    champ->reg[instr->args[0]] : instr->args[0]);
    int b = (instr->types[1] == 'r' ?
    champ->reg[instr->args[1]] : instr->args[1]);
    int address = (champ->pc + a) % MEM_SIZE;
    int mid;
    int fin_add;

    if (address < 0)
        address += MEM_SIZE;
    my_memcpy(&mid, &corewar->arena->memory[address], IND_SIZE);
    fin_add = (champ->pc + (mid + b)) % MEM_SIZE;
    if (fin_add < 0)
        fin_add = (fin_add + MEM_SIZE) % MEM_SIZE;
    my_memcpy(&champ->reg[instr->args[2]],
    &corewar->arena->memory[fin_add], REG_SIZE);
    champ->carry = (champ->reg[instr->args[2]] ? 0 : 1);
    return 0;
}
