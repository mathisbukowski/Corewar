/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** check_dump.c
*/

#include "corewar.h"
#include "my.h"

int check_dump(corewar_t *corewar, char **av)
{
    if (my_strcmp(av[1], "-dump") == 0) {
        if (my_str_isnum(av[2]) == 0) {
            corewar->vm->dump = my_getnbr(av[2]);
            return 0;
        }
        return 84;
    }
    return 0;
}
