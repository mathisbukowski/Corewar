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
    if (champion->infos)
        free(champion->infos);
    if (champion->instructs)
        free(champion->instructs);
    if (champion->name)
        free(champion->name);
    if (champion->comment)
        free(champion->comment);
    champion->infos = NULL;
    champion->instructs = NULL;
    champion->name = NULL;
    champion->comment = NULL;
    free(champion);
    champion = NULL;
}

void free_champions(champion_t *champion)
{
    champion_t *current = champion;
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
    free(corewar);
}
