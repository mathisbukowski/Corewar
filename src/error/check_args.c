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
    int champions_loaded = 0;
    int j = 0;

    for (int i = 1; av[i] && champions_loaded < 4; i++)
        if (get_extension(av[i]) == 0)
            champions_loaded++;
    corewar->fd = malloc(champions_loaded * sizeof(int));
    if (corewar->fd == NULL)
        return -1;
    for (int i = 1; av[i] && j < champions_loaded; i++) {
        if (get_extension(av[i]) == 0) {
            corewar->fd[j] = open(av[i], O_RDONLY);
            j++;
        }
    }
    return champions_loaded;
}
