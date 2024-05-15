/*
** EPITECH PROJECT, 2024
** corewar-dev
** File description:
** get_redirect.c
*/

#include "corewar.h"

int get_register_argument(corewar_t *corewar, champion_t *champ)
{
    int arg = (int)corewar->arena->memory[(champ->pc + 2) % MEM_SIZE];

    //champ->pc += 1;
    return arg;
}