/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** init_struct.c
*/

#include <stdlib.h>
#include "corewar.h"
#include "op.h"

corewar_t *init_corewar(void)
{
    corewar_t *corewar = malloc(sizeof(corewar_t));

    corewar->fd1 = 0;
    corewar->fd2 = 0;
    corewar->vm = malloc(sizeof(vm_t));
    corewar->vm->dump = 0;
    corewar->vm->cycle_to_die = CYCLE_TO_DIE;
    corewar->vm->cycle = 0;
    corewar->vm->live = 0;
    corewar->vm->last_live = 0;
    corewar->vm->nb_champs = 0;
    corewar->vm->champs = malloc(sizeof(champion_t *) * 5);
    corewar->vm->mem = malloc(sizeof(char) * MEM_SIZE);
    return corewar;
}
