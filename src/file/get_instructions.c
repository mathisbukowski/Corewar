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

int calculate_instruction_length(unsigned char opcode)
{
    op_t *current_op = &op_tab[opcode - 1];
    int instruction_length = 1; // 1 byte for the opcode

    if (opcode < 1 || opcode > 16)
        return -1;

    for (int i = 0; i < current_op->nbr_args; i++) {
        switch (current_op->type[i]) {
            case T_REG:
                instruction_length += 1; // 1 byte for a register argument
                break;
            case T_DIR:
                instruction_length += DIR_SIZE; // DIR_SIZE bytes for a direct argument
                break;
            case T_IND:
                instruction_length += IND_SIZE; // IND_SIZE bytes for an indirect argument
                break;
        }
    }
    return instruction_length;
}

static int get_infos(int fd, corewar_t *corewar, int *i)
{
    unsigned char opcode;
    int instruction_length;

    if (read_opcode(fd, &opcode) != 0) {
        close(fd);
        return 1;
    }
    print_instruction((*i), opcode);
    instruction_length = calculate_instruction_length(opcode);
    printf("opcode: %d\n", opcode);
    printf("Instruction length: %d\n", instruction_length );
    if (instruction_length == -1) {
        printf("Error: Invalid opcode %d at instruction %d\n", opcode, *i);
        return -1;
    }
    if (lseek(fd, instruction_length - 1, SEEK_CUR) == -1) {
        printf("Error: Failed to skip over arguments for instruction %d\n", *i);
        return -1;
    }
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
