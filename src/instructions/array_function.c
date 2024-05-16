/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** array_function.c
*/

#include "corewar.h"

int (* const run_commands[NUMBER_OF_INSTRUCTIONS])(instruction_t *,
    champion_t *, corewar_t *) = {
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
    &aff_command
};
