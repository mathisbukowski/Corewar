/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** check_champions.c
*/

#include "corewar.h"
#include "my.h"

int set_champion_id(corewar_t *corewar, char **av, int i, int j)
{
    if (my_str_isnum(av[i + 1]) == 0) {
        corewar->n_value[j] = my_atoi(av[i + 1]);
        corewar->champ_names[j] = av[i + 2];
        return 0;
    } else {
        return 84;
    }
}

int check_options_n(char **av, int *i, corewar_t *corewar, int j)
{
    if (av[(*i) + 1] == NULL)
        return 84;
    if (set_champion_id(corewar, av, (*i), j) == 0)
        (*i)++;
    else
        return 84;
    return 0;
}

int check_champion(corewar_t *corewar, char **av)
{
    int i = 1;
    int result = 0;
    static int j = 0;

    for (; av[i]; i++) {
        if (result == 84)
            return 84;
        if (my_strcmp(av[i], "-n") == 0) {
            result = check_options_n(av, &i, corewar, j);
            i++;
            j++;
            continue;
        }
        if (get_extension(av[i]) == 0)
            j++;
    }
    return 0;
}
