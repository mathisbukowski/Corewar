/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** init_struct.c
*/

#include <stdlib.h>
#include "corewar.h"
#include "op.h"
#include "my.h"

int get_nb_champs(char **av)
{
    int nb_champs = 0;

    for (int i = 1; av[i]; i++) {
        if (my_strcmp(av[i], "-n") != 0)
            nb_champs++;
    }
    return nb_champs;
}

void init_champs_struct(corewar_t *corewar)
{
    corewar->vm->champs = malloc(sizeof(champion_t *) *
        corewar->vm->nb_champs);
    for (int i = 0; i < corewar->vm->nb_champs; i++) {
        corewar->vm->champs[i] = malloc(sizeof(champion_t));
        corewar->vm->champs[i]->id = i + 1;
        corewar->vm->champs[i]->path = NULL;
        corewar->vm->champs[i]->name = NULL;
        corewar->vm->champs[i]->comment = NULL;
        corewar->vm->champs[i]->prog_size = 0;
        corewar->vm->champs[i]->prog = NULL;
    }
}

corewar_t *init_corewar(char **av)
{
    corewar_t *corewar = malloc(sizeof(corewar_t));

    corewar->vm = malloc(sizeof(vm_t));
    corewar->vm->dump = 0;
    corewar->vm->cycle_to_die = CYCLE_TO_DIE;
    corewar->vm->cycle = 0;
    corewar->vm->live = 0;
    corewar->vm->last_live = 0;
    corewar->vm->nb_champs = get_nb_champs(av);
    corewar->fd = malloc(sizeof(int) * corewar->vm->nb_champs + 1);
    init_champs_struct(corewar);
    corewar->vm->mem = malloc(sizeof(char) * MEM_SIZE);
    return corewar;
}
