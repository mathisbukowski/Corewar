/*
** EPITECH PROJECT, 2024
** corewar-dev
** File description:
** get_instructions.c
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "corewar.h"
#include "op.h"


int read_opcode(int fd, unsigned char *opcode)
{
    ssize_t bytes_read = read(fd, opcode, 1);

    if (bytes_read != 1) {
            printf("Erreur: Lecture d'opcode échouée\n");
        return 84;
    }
    return 0;
}

void print_instruction(int index, unsigned char opcode)
{
    op_t *current_op = &op_tab[opcode - 1];

    if (opcode < 1 || opcode > 16)
        return;
    printf("Instruction %d - Opcode: %d (%s)\n", index, opcode,
    current_op->mnemonique);
}

static int get_infos(int fd, corewar_t *corewar, int *i)
{
    unsigned char opcode;

    if (read_opcode(fd, &opcode) != 0) {
        close(fd);
        return 1;
    }
    print_instruction((*i), opcode);
    return 0;
}

int get_instructions(int fd, champion_t *new, corewar_t *corewar)
{
    lseek(fd, sizeof(header_t), SEEK_SET);
    new->instructs = malloc(sizeof(instruction_t) *
    new->prog_size);
    if (new->instructs == NULL) {
        close(fd);
        return 84;
    }
    for (int i = 0; i < new->prog_size; i++)
        if (get_infos(fd, corewar, &i) != 0)
            return 84;
    if (close(fd) == -1)
        return 84;
    return 0;
}
