/*
** EPITECH PROJECT, 2024
** corewar-dev
** File description:
** has_idx.c
*/

int has_idx(int code, int ac)
{
    switch (code) {
        case 9:
            return 1;
        case 10:
        case 14:
            return (ac < 3);
        case 11:
            return (ac > 1);
        case 12:
        case 15:
            return 1;
        default:
            return 0;
    }
}
