/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** main.c
*/

#include "corewar.h"
#include "my.h"

int parse_arguments(int argc, char **argv, corewar_t *corewar)
{
    corewar->nb_champs = check_args(argv, corewar);
    if (corewar->nb_champs < 1 || corewar->nb_champs > 4)
        return 84;
    if (check_dump(corewar, argv))
        return 84;
    if (check_champion(corewar, argv))
        return 84;
    return 0;
}

int load_champions(corewar_t *corewar, char **argv)
{
    if (get_file_data(corewar) != 0)
        return 84;
    return 0;
}

int main(int argc, char **argv)
{
    corewar_t *corewar = init_corewar(argv);

    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        print_usage();
        free_corewar(corewar);
        return 0;
    }
    if (parse_arguments(argc, argv, corewar) != 0) {
        free_corewar(corewar);
        return 84;
    }
    if (load_champions(corewar, argv) != 0) {
        free_corewar(corewar);
        return 84;
    }
    print_vm(corewar);
    free_corewar(corewar);
    return 0;
}
