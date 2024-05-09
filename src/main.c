/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** main.c
*/

#include "corewar.h"
#include "my.h"

int main(int ac, char **av)
{
    corewar_t *corewar = init_corewar(av);

    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        print_usage();
        return 0;
    }
    if (check_args(av, corewar))
        return 84;
    if (check_dump(corewar, av))
        return 84;
    if (check_champion(corewar, av))
        return 84;
    if (get_file_data(av[1], corewar))
        return 84;
    free_corewar(corewar);
    return 0;
}
