/*
** EPITECH PROJECT, 2024
** corewar-dev
** File description:
** add_champion.c
*/

#include "corewar.h"


int add_champion(corewar_t *corewar, champion_t *new_champ)
{
    champion_t *current = NULL;

    if (!corewar || !new_champ)
        return -1;
    new_champ->next = NULL;
    if (corewar->champs == NULL)
        corewar->champs = new_champ;
    else {
        current = corewar->champs;
        while (current->next != NULL)
            current = current->next;
        current->next = new_champ;
    }
    return 0;
}
