/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** array_function.c
*/

#include "corewar.h"

typedef int (*array_function_t)(instruction_t *instr, champion_t *champ,
    corewar_t *corewar);

array_function_t instruction_functions[] = {
        NULL,
        &live_command,
        &ld_command,
        &st_command,
        &add_command,
        &sub_command,
        &and_command,
        &or_command,
        &xor_command,
        &zjmp_command,
        &ldi_command,
        &sti_command,
        &fork_command,
        &lld_command,
        &lldi_command,
        &lfork_command,
        &aff_command,
};