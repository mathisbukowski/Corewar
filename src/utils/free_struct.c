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
    if (champion->name != NULL) {
        free(champion->name);
        champion->name = NULL;
    }
    if (champion->comment != NULL) {
        free(champion->comment);
        champion->comment = NULL;
    }
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
    free_champions(corewar->champs);
    free(corewar);
}
