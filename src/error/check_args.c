/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** check_argv.c
*/


#include <fcntl.h>
#include "my.h"
#include "corewar.h"

void open_file(char **av, corewar_t *corewar, int i)
{
    if (corewar->fd1 < 0)
        corewar->fd1 = open(av[i], O_RDONLY);
    else if (corewar->fd2 < 0)
        corewar->fd2 = open(av[i], O_RDONLY);
}

int check_args(char **av, corewar_t *corewar)
{
    corewar->fd1 = -1;
    corewar->fd2 = -1;
    for (int i = 1; av[i]; i++)
        open_file(av, corewar, i);
    if (corewar->fd1 <= 0 || corewar->fd2 <= 0)
        return 84;
    return 0;
}
