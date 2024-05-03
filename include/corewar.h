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
    int types[3];
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
    unsigned char *prog;
    int pc;
    int reg[16];
    int carry;
    int live;
    int last_live;
    info_champ_t *infos;
    instruction_t *instructs;
    struct champion_s *next;
} champion_t;

typedef struct arena_s {
    unsigned char *memory;
    int size;
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
#endif //COREWAR_COREWAR_H
