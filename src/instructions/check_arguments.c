/*
** EPITECH PROJECT, 2024
** corewar-dev
** File description:
** check_arguments.c
*/

#include "corewar.h"

int check_arguments(instruction_t *instr)
{
    if (!instr)
        return 1;
    if (instr->types[0] != 'r' || instr->args[0] >= REG_NUMBER)
        return 1;
    if ((instr->types[1] == 'r' && (instr->args[1] >= REG_NUMBER
        || instr->args[1] < 0)) ||
        (instr->types[1] != 'r' && (instr->args[1] >= MEM_SIZE ||
        instr->args[1] < 0)))
        return 1;
    if ((instr->types[2] == 'r' && (instr->args[2] >= REG_NUMBER ||
        instr->args[2] < 0)) ||
        (instr->types[2] != 'r' && (instr->args[2] >= MEM_SIZE ||
        instr->args[2] < 0)))
        return 1;
    return 0;
}
