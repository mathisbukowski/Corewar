/*
** EPITECH PROJECT, 2024
** corewar-dev
** File description:
** live_instr.c
*/

#include "corewar.h"
#include <unistd.h>

int live_command(instruction_t *instr, champion_t *champ, corewar_t *corewar)
{
    champion_t *curr = corewar->champs;

    while (curr != NULL) {
        if (curr->is_alive == 0) {
            my_printf("This player %d (%s) is alive.\n", curr->id, curr->name);
            corewar->arena->last_live = curr->id;
        }
        curr = curr->next;
    }
    return 0;
}
