/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** free_struct.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "corewar.h"

void free_champion(champion_t *champion)
{
    free(champion->infos);
    free(champion->instructs);
    free(champion->name);
    free(champion->comment);
    free(champion);
}

void free_champions(champion_t *champion)
{
    champion_t *current = champion;
    champion_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current->infos);
        free(current->instructs);
        free(current->name);
        free(current->comment);
        free(current);
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
