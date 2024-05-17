/*
** EPITECH PROJECT, 2024
** corewar-dev
** File description:
** run_vm.c
*/

#include "corewar.h"
#include <stdio.h>

int reset_pos_champ(champion_t *champion)
{
    champion->pc = champion->start_pc;
    return 0;
}

void execute_instructions(corewar_t *corewar, champion_t *champ)
{
    run_commands[champ->instruct->opcode](champ->instruct, champ, corewar);
    champ->cycle_to_wait = -1;
    champ->cycle = 0;
    champ->pc = (champ->pc + champ->instruct->encoding_byte) % MEM_SIZE;
    if (champ->instruct) {
        free(champ->instruct);
        champ->instruct = NULL;
    }
}

void run_champions(corewar_t *corewar)
{
    champion_t *curr = corewar->champs;

    while (curr != NULL) {
        curr->cycle++;
        if (curr->pc < curr->start_pc ||
        curr->pc >= curr->start_pc + curr->prog_size)
            reset_pos_champ(curr);
        if (curr->cycle_to_wait == -1)
            get_instructions(corewar, curr);
        if (curr->cycle == curr->cycle_to_wait)
            execute_instructions(corewar, curr);
        curr = curr->next;
    }
}

void win_condition(corewar_t *corewar)
{
    printf("The player %d has won.\n", corewar->arena->last_live);
}

int run_vm(corewar_t *corewar)
{
    if (corewar->dump == 0)
        corewar->dump = CYCLE_TO_DIE;
    for (; corewar->dump > 0; corewar->dump--)
        run_champions(corewar);
    win_condition(corewar);
    print_vm(corewar);
    return 0;
}
