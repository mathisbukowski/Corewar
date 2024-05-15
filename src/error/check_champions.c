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
    if (av[i + 1] == NULL)
        return 84;
    if (set_champion_id(corewar->champs, av[i + 1]) == 0)
        i++;
    else
        return 84;
    return 0;
}

int check_champion(corewar_t *corewar, char **av)
{
    int i = 1;
    int result = 0;

    for (; av[i]; i++) {
        if (result == 84)
            return 84;
        if (my_strcmp(av[i], "-n") == 0) {
            result = check_options_n(av, i, corewar);
            continue;
        }
    }
    return 0;
}
