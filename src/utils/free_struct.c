/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** free_struct.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "corewar.h"

void free_corewar(corewar_t *corewar)
{
    free(corewar->vm->mem);
    free(corewar->fd);
    free(corewar->vm->champs);
    free(corewar->vm);
    free(corewar);
}
