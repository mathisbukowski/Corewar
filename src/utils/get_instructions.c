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

static int get_nbr_args(unsigned char opcode, instruction_t *instr)
{
    int i;

    for (i = 0; instr->types[i] != '\0' && i < 3; i++);
    return 1;
}

int get_instr_normal(corewar_t *corewar, champion_t *champ, int code)
{
    int coding_byte = (int)corewar->arena->memory[(champ->pc + 1) % MEM_SIZE];
    int ac;
    instruction_t instruction = {.opcode = code};
    int size = 1;

    if (code < 1 || code > 16)
        return 1;
    get_coding_byte(coding_byte, &instruction);
    for (int i = 0; i < 3; i++) {
        if (instruction.types[i] == T_REG) {
            printf("REG\n");
//            instruction.args[i] = get_register_argument(corewar, champ);
            size += 1;
        }
        else if (instruction.types[i] == T_DIR) {
            printf("DIR\n");
//            instruction.args[i] = get_direct_argument(corewar, champ);
            size += 2;
        }
        else if (instruction.types[i] == T_IND) {
            printf("IND\n");
//            instruction.args[i] = get_indirect_argument(corewar, champ);
            size += 2;
        }
        else
            instruction.args[i] = 0;
    }
    printf("OPCODE %d\n", instruction.opcode);

//    for (int i = 0; i < 3; i++) {
//        printf("ARG %d: %d\n", i+1, instruction.args[i]);
//    }

    printf("SIZE: %d\n", size);
    return size;
}

int get_no_coding_byte_instruction(corewar_t *corewar, champion_t *champion, int code)
{
    int size = 1;
    instruction_t instruction;
    op_t *op = NULL;

    for (int i = 0; op_tab[i].mnemonique != 0; i++) {
        if (op_tab[i].code == code) {
            op = &op_tab[i];
            break;
        }
    }
    if (!op)
        return size;
    instruction.opcode = op->code;
    for (int i = 0; i < op->nbr_args; i++)
        instruction.types[i] = op->type[i];
    for (int i = 0; i < op->nbr_args; i++) {
        if (op->type[i] == T_DIR) {
            instruction.args[i] = get_direct_argument(corewar, champion);
            size += 4;
        } else if (op->type[i] == T_IND) {
            instruction.args[i] = get_indirect_argument(corewar, champion);
            size += 2;
        } else if (op->type[i] == T_REG) {
            instruction.args[i] = get_register_argument(corewar, champion);
            size += 1;
        }
    }
    printf("OPCODE NON CODING BYTE%d\n", instruction.opcode);
    for (int i = 0; i < 3; i++) {
        printf("ARG %d: %d\n", i+1, instruction.args[i]);
    }
    return size;
}

int get_instructions(corewar_t *corewar, champion_t *champ)
{
    int code;
    int size = 1;

    //print_vm(corewar);
    while (champ->pc < MEM_SIZE) {
        if (champ->pc > 50)
            return 0;
        printf("ENDROIT BOUCLE %x \n", corewar->arena->memory[(champ->pc) % MEM_SIZE]);
        code = (int)corewar->arena->memory[(champ->pc) % MEM_SIZE];
        if (!has_coding_byte(code)) {
            size += get_instr_normal(corewar, champ, code);
        } else {
            size += get_no_coding_byte_instruction(corewar, champ, code);
        }
        champ->pc += size;
        size = 1;
    }
    return 0;
}