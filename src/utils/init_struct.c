/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** init_struct.c
*/


#include "corewar.h"

/*instruction_t *init_instruction(void)
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
}*/

void init_id(const corewar_t *corewar, champion_t *champ)
{
    for (int i = 0; i < corewar->nb_champs; i++) {
        if (corewar->champ_names[i] != NULL &&
            my_strcmp(corewar->champ_names[i], champ->name) == 0) {
            champ->id = corewar->n_value[i];
            break;
        }
    }
}

void get_champion_id(const corewar_t *corewar, champion_t *champ, int id)
{
    if (corewar->champ_names[id] != NULL) {
        champ->name = corewar->champ_names[id];
        init_id(corewar, champ);
    } else
        champ->id = id;
}

champion_t *init_champ(corewar_t *corewar)
{
    champion_t *champ = malloc(sizeof(champion_t));
    static int id = 0;

    if (champ == NULL)
        return NULL;
    champ->name = corewar->champ_names[id];
    get_champion_id(corewar, champ, id);
    id++;
    champ->name = NULL;
    champ->comment = NULL;
    champ->prog_size = 0;
    champ->pc = 0;
    my_memset(champ->reg, 0, sizeof(champ->reg));
    champ->carry = 0;
    champ->live = 0;
    champ->last_live = 0;
    champ->infos = NULL;
    champ->instructs = NULL;
    return champ;
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

static void init_n_value_array(corewar_t *corewar)
{
    corewar->n_value[0] = 0;
    corewar->n_value[1] = 0;
    corewar->n_value[2] = 0;
    corewar->n_value[3] = 0;
}

corewar_t *init_corewar(char **av)
{
    corewar_t *corewar = malloc(sizeof(corewar_t));

    if (corewar == NULL)
        return NULL;
    corewar->dump = 0;
    corewar->cycle = 0;
    corewar->fd = NULL;
    corewar->nb_champs = 0;
    corewar->champs = NULL;
    init_n_value_array(corewar);
    corewar->arena = init_arena(CYCLE_TO_DIE);
    if (corewar->arena == NULL) {
        free_corewar(corewar);
        return NULL;
    }
    return corewar;
}
