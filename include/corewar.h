/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** corewar.h
*/

#ifndef COREWAR_COREWAR_H
    #define COREWAR_COREWAR_H
    #include "op.h"
    #include "my.h"
    #include "my_printf.h"

typedef enum inst_code_s {
    ADD, SUB, AND, OR, XOR, LD, ST, LDI,
    STI, FORK, LFORK, ZJMP, LIVE, AFF
} inst_code_t;

typedef struct instruction_s {
    inst_code_t opcode;
    int num_args;
    int args[3];
    char types[3];
    int encoding_byte;
    int cycles_to_wait;
} instruction_t;

typedef struct info_champ_s {
    int nb_is_impose;
    int adress;
    int adress_impose;
} info_champ_t;

typedef struct champion_s {
    int id;
    char *name;
    char *comment;
    int prog_size;
    int pc;
    int reg[REG_NUMBER];
    int carry;
    int live;
    int last_live;
    info_champ_t *infos;
    instruction_t *instructs;
    struct champion_s *next;
} champion_t;

typedef struct arena_s {
    unsigned char *memory;
    int cycle_to_die;
    int live;
    int last_live;
} arena_t;

typedef struct corewar_s {
    int dump;
    arena_t *arena;
    int cycle;
    int nb_champs;
    int *fd;
    champion_t *champs;
} corewar_t;

void print_usage(void);
corewar_t *init_corewar(char **av);
champion_t *init_champion(void);
void free_corewar(corewar_t *corewar);
int check_args(char **av, corewar_t *corewar);
int check_dump(corewar_t *corewar, char **av);
int check_champion(corewar_t *corewar, char **av);

// Loading Instructions
/**
 *  @brief Exec the ld instruction (load)
 *  This function loads a value in a register or a memory address.
 *  @param instr Pointer to the structure of instructions.
 *  @param champ Pointer to the entity in exec.
 *  @param corewar Pointer to the global structure.
 *  @return Return 0 if the exec is all good else return 1.
**/
int ld_command(instruction_t *instr, champion_t *champ, corewar_t *corewar);

/**
 *  @brief Exec the ld instruction (load index)
 *  This function loads a value from an address calculated by
 *  adding a register and an immediate value,
 *  and stores this value in a register
 *  @param instr Pointer to the structure of instructions.
 *  @param champ Pointer to the entity in exec.
 *  @param corewar Pointer to the global structure.
 *  @return Return 0 if the exec is all good else return 1.
**/
int ldi_command(instruction_t *instr, champion_t *champ, corewar_t *corewar);

/**
 *  @brief Exec the ld instruction (long load)
 *  This function loads a value into a register or a memory address,
 *  without interpreting the first parameter as an index.
 *  @param instr Pointer to the structure of instructions.
 *  @param champ Pointer to the entity in exec.
 *  @param corewar Pointer to the global structure.
 *  @return Return 0 if the exec is all good else return 1.
**/
int lld_command(instruction_t *instr, champion_t *champ, corewar_t *corewar);

/**
 *  @brief Exec the ld instruction (long load index)
 *  This function loads a value from an address calculated by
 *  adding a register and an immediate value,
 *  without interpreting the first parameter as an index,
 *  and stores this value in a register.
 *  @param instr Pointer to the structure of instructions.
 *  @param champ Pointer to the entity in exec.
 *  @param corewar Pointer to the global structure.
 *  @return Return 0 if the exec is all good else return 1.
**/
int lldi_command(instruction_t *instr, champion_t *champ, corewar_t *corewar);

/**
 *  @brief Exec the st instruction (store)
 *  This function stores the first param value into the second
 *  @param instr Pointer to the structure of instructions.
 *  @param champ Pointer to the entity in exec.
 *  @param corewar Pointer to the global structure.
 *  @return Return 0 if the exec is all good else return 1.
**/
int st_command(instruction_t *instr, champion_t *champ, corewar_t *corewar);

/**
 *  @brief Exec the sti instruction (store index)
 *  This function copies the content of the first param (register)
 *  into a new address made off the two others params
 *  @param instr Pointer to the structure of instructions.
 *  @param champ Pointer to the entity in exec.
 *  @param corewar Pointer to the global structure.
 *  @return Return 0 if the exec is all good else return 1.
**/
int sti_command(instruction_t *instr, champion_t *champ, corewar_t *corewar);

int add_champion(corewar_t *corewar, champion_t *new_champ);
int check_arguments(instruction_t *instr);

/**
 * @brief Open a file .cor read the header and
 * read the instructions
 * @param corewar  pointer to the corewar structure
 * @return
 */
int get_file_data(corewar_t *corewar);
int get_instructions(int fd, champion_t *new, corewar_t *corewar);
void get_coding_byte(char coding_byte, instruction_t *instr);
void free_champion(champion_t *champion);
#endif //COREWAR_COREWAR_H
