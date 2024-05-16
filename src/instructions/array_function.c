/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** array_function.c
*/

#include "corewar.h"

 int (* const run_commands[NUMBER_OF_INSTRUCTIONS])(instruction_t *instr, champion_t *champ,
    corewar_t *corewar) = {
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

 int const command_number[NUMBER_OF_INSTRUCTIONS] = {
        0,
        1,
        2,
        3,
        4,
        5,
        6,
        7,
        8,
        9,
        10,
        11,
        12,
        13,
        14,
        15,
        16,
};