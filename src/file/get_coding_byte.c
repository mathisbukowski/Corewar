/*
** EPITECH PROJECT, 2024
** corewar-dev
** File description:
** get_coding_byte.C
*/


#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "corewar.h"
#include "op.h"

void get_coding_byte(char coding_byte, instruction_t *instr)
{
    u_int8_t type_bits;
    char const type_map[4] = {0, 'r', 'd', 'i'};
    int index;

    for (int i = 0; i < 3; i++) {
        type_bits = (coding_byte << (2 * i)) & 0xC0;
        index = type_bits >> 6;
        instr->types[i] = type_map[index];
    }
}

int has_coding_byte(int mnemonic)
{
    if (mnemonic == 1 || mnemonic == 9 || mnemonic == 12 || mnemonic == 15)
        return 1;
    return 0;
}
