/*
** EPITECH PROJECT, 2024
** corewar-dev
** File description:
** exec_instructions.c
*/

#include "corewar.h"
#include <stdio.h>

void execute_instructions(corewar_t *corewar, champion_t *champ)
{
    run_commands[champ->instruct->opcode](champ->instruct, champ, corewar);
    champ->cycle_to_wait = -1;
    champ->cycle = 0;
    champ->pc = (champ->pc + champ->instruct->encoding_byte) % MEM_SIZE;
}
