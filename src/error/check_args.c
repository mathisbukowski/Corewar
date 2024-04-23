/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** check_argv.c
*/


#include <fcntl.h>
#include "my.h"
#include "corewar.h"

int check_args(char **av, corewar_t *corewar)
{
    corewar->fd1 = open(av[1], O_RDONLY);
    corewar->fd2 = open(av[2], O_RDONLY);
    if (corewar->fd1 == -1 || corewar->fd2 == -1)
        return 84;
    return 0;
}
