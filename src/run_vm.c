/*
** EPITECH PROJECT, 2024
** corewar-dev
** File description:
** run_vm.c
*/

#include "corewar.h"

int reset_pos_champ(champion_t *champion)
{
    champion->pc = champion->start_pc;
    return 0;
}

int run_champions(corewar_t *corewar)
{
    champion_t *curr = corewar->champs;

    while (curr != NULL) {
        if (curr->pc >= curr->start_pc + curr->prog_size)
            reset_pos_champ(curr);
        if (get_instructions(corewar, curr) != 0)
            return 1;
        curr = curr->next;
    }
    return 0;
}

int run_vm(corewar_t *corewar)
{
    for (; corewar->dump > 0; corewar->dump--)
        run_champions(corewar);
    print_vm(corewar);
    return 0;
}
