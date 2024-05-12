/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** init_struct.c
*/


#include "corewar.h"

instruction_t *init_instruction(void)
{
    instruction_t *instruction = malloc(sizeof(instruction_t));

    if (instruction == NULL)
        return NULL;
    my_memset(instruction, 0, sizeof(instruction_t));
    for (int i = 0; i < 3; i++) {
        instruction->args[i] = 0;
        instruction->types[i] = 0;
    }
    return instruction;
}

info_champ_t *init_info_champ(void)
{
    info_champ_t *info_champ = malloc(sizeof(info_champ_t));

    if (info_champ == NULL)
        return NULL;
    my_memset(info_champ, 0, sizeof(info_champ_t));
    return info_champ;
}

champion_t *init_champion(void)
{
    champion_t *champion = malloc(sizeof(champion_t));

    if (champion == NULL)
        return NULL;
    my_memset(champion, 0, sizeof(champion_t));
    champion->infos = malloc(sizeof(info_champ_t));
    champion->instructs = NULL;
    champion->next = NULL;
    return champion;
}

arena_t *init_arena(int cycle_to_die)
{
    arena_t *arena = malloc(sizeof(arena_t));

    if (arena == NULL)
        return NULL;
    arena->cycle_to_die = cycle_to_die;
    arena->live = 0;
    arena->last_live = 0;
    arena->memory = malloc(MEM_SIZE * sizeof(unsigned char));
    if (arena->memory == NULL) {
        free(arena);
        return NULL;
    }
    for (int i = 0; i < MEM_SIZE; i++)
        arena->memory[i] = 0;
    return arena;
}

corewar_t *init_corewar(char **av)
{
    corewar_t *corewar = malloc(sizeof(corewar_t));

    if (corewar == NULL)
        return NULL;
    corewar->dump = check_dump(corewar, av);
    corewar->cycle = 0;
    corewar->fd = NULL;
    corewar->nb_champs = 0;
    corewar->champs = NULL;
    corewar->arena = init_arena(CYCLE_TO_DIE);
    if (corewar->arena == NULL) {
        free_corewar(corewar);
        return NULL;
    }
    return corewar;
}
