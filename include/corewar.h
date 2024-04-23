/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** corewar.h
*/

#ifndef COREWAR_COREWAR_H
    #define COREWAR_COREWAR_H

typedef struct champion_s {
    int id;
    int pc;
    int carry;
    int reg[16];
    int cycle;
    int live;
    int last_live;
    int prog_size;
    char *name;
    char *comment;
    char *prog;
} champion_t;

typedef struct vm_s {
    int dump;
    int cycle_to_die;
    int cycle;
    int live;
    int last_live;
    int nb_champs;
    champion_t **champs;
    char *mem;
} vm_t;

typedef struct corewar_s {
    int fd1;
    int fd2;
    vm_t *vm;
} corewar_t;

void print_usage(void);
corewar_t *init_corewar(void);
void free_corewar(corewar_t *corewar);
int check_args(char **av, corewar_t *corewar);
#endif //COREWAR_COREWAR_H
