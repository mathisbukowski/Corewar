/*
** EPITECH PROJECT, 2024
** corewar-dev
** File description:
** fork_inst.c
*/

#include "corewar.h"

int fork_command(instruction_t *instr, champion_t *champ, corewar_t *corewar)
{
    int new_pc;
    champion_t *new;

    if (!instr || !champ || !corewar)
        return -1;
    new_pc = (champ->pc + (instr->args[0] % IDX_MOD)) % MEM_SIZE;
    if (new_pc < 0)
        new_pc += MEM_SIZE;
    new = malloc(sizeof(champion_t));
    if (!new)
        return -1;
    *new = *champ;
    new->pc = new_pc;
    if (add_champion(corewar, new) != 0) {
        free(new);
        return -1;
    }
    return 0;
}

int lfork_command(instruction_t *instr, champion_t *champ, corewar_t *corewar)
{
    int new_pc;
    champion_t *new;

    if (!instr || !champ || !corewar)
        return -1;
    new_pc = (champ->pc + instr->args[0]) % MEM_SIZE;
    if (new_pc < 0)
        new_pc += MEM_SIZE;
    new = malloc(sizeof(champion_t));
    if (!new)
        return -1;
    *new = *champ;
    new->pc = new_pc;
    if (add_champion(corewar, new) != 0) {
        free(new);
        return -1;
    }
    return 0;
}

int zjmp_command(instruction_t *instr, champion_t *champ, corewar_t *corewar)
{
    int new_pc;

    if (!instr || !champ || !corewar)
        return -1;
    if (champ->carry == 1) {
        new_pc = (champ->pc + (instr->args[0] % IDX_MOD)) % MEM_SIZE;
        if (new_pc < 0)
            new_pc += MEM_SIZE;
        champ->pc = new_pc;
    }
    return 0;
}
