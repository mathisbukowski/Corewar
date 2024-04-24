/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** check_argv.c
*/

#include <fcntl.h>
#include "my.h"
#include "corewar.h"

int get_extension(char *av)
{
    char *ext = my_strstr(av, ".cor");

    if (ext == NULL)
        return 1;
    return 0;
}

int check_args(char **av, corewar_t *corewar)
{
    int j = 0;

    for (int i = 1; av[i]; i++) {
        if (!get_extension(av[i]) == 0) {
            corewar->fd[j] = open(av[i], O_RDONLY);
        }
        if (corewar->fd[j] == -1)
            continue;
        j++;
    }
    return 0;
}
