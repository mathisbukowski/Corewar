/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** check_champions.c
*/

#include "corewar.h"
#include "my.h"

#include "corewar.h"
#include "my.h"

#include "corewar.h"
#include "my.h"

#include "corewar.h"
#include "my.h"

int add_champion_to_list(champion_t **list)
{
    champion_t *new_champion = init_champion();
    champion_t *current = NULL;

    if (new_champion == NULL)
        return 84;
    if (*list == NULL) {
        *list = new_champion;
    } else {
        current = *list;
        while (current->next != NULL)
            current = current->next;
        current->next = new_champion;
    }
    return 0;
}

int set_champion_id(champion_t *champion, char const *id_str)
{
    if (my_str_isnum(id_str) == 0) {
        champion->id = my_getnbr(id_str);
        return 0;
    } else {
        return 84;
    }
}

int check_options_n(char **av, int i, corewar_t *corewar)
{
    if (add_champion_to_list(&(corewar->champs)) != 0)
        return 84;
    if (av[i + 1] == NULL)
        return 84;
    if (set_champion_id(corewar->champs, av[i + 1]) == 0)
        i++;
    else
        return 84;
    corewar->nb_champs++;
    return 0;
}

int check_champion(corewar_t *corewar, char **av)
{
    int i = 1;
    int result = 0;

    corewar->nb_champs = 0;
    for (; av[i]; i++) {
        if (result == 84)
            return 84;
        if (my_strcmp(av[i], "-n") == 0) {
            result = check_options_n(av, i, corewar);
            continue;
        }
        result = add_champion_to_list(&(corewar->champs));
        if (result != 0)
            return 84;
        corewar->nb_champs++;
    }
    return 0;
}