/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** free_struct.c
*/

#include <stdlib.h>
#include "corewar.h"

void free_champion(champion_t *champion)
{
    if (champion == NULL)
        return;
    free(champion->instructs);
    if (champion->name != NULL)
        free(champion->name);
    if (champion->comment != NULL)
        free(champion->comment);
    free(champion);
}

void free_champions(champion_t *champions)
{
    champion_t *current = champions;
    champion_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        free_champion(current);
        current = next;
    }
}

void free_corewar(corewar_t *corewar)
{
    if (corewar == NULL)
        return;
    free(corewar->fd);
    if (corewar->arena != NULL) {
        free(corewar->arena->memory);
        free(corewar->arena);
    }
    if (corewar->champs)
        free_champions(corewar->champs);
    free(corewar);
}
