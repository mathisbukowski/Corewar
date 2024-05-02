/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** check_dump.c
*/

#include "corewar.h"
#include "my.h"

int get_current_arg(char **av, int i, corewar_t *corewar)
{
    if (my_strcmp(av[i], "-dump") == 0) {
        if (my_str_isnum(av[i + 1]) == 0) {
            corewar->vm->dump = my_getnbr(av[i + 1]);
            return 0;
        }
        return 84;
    }
    return 0;
}

int check_dump(corewar_t *corewar, char **av)
{
    for (int i = 0; av[i]; i++) {
        if (get_current_arg(av, i, corewar) == 84)
            return 84;
    }
    return 0;
}
