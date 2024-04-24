/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** check_champions.c
*/

#include "corewar.h"
#include "my.h"

int check_options_n(char **av, int i, corewar_t *corewar)
{
    if (my_str_isnum(av[i + 1]) == 0) {
        corewar->vm->champs[corewar->vm->nb_champs]->id = my_getnbr(av[i + 1]);
        i++;
    } else
        return 84;
    return 0;
}

int check_champion(corewar_t *corewar, char **av)
{
    int i = 1;
    int result = 0;

    corewar->vm->nb_champs = 0;
    for (; av[i]; i++) {
        if (result == 84)
            return 84;
        if (my_strcmp(av[i], "-n") == 0) {
            result = check_options_n(av, i, corewar);
            continue;
        }
        corewar->vm->champs[corewar->vm->nb_champs]->path = av[i];
        corewar->vm->nb_champs++;
    }
    return 0;
}
