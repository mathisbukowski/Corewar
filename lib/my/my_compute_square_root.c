/*
** EPITECH PROJECT, 2023
** my_compute_square_root.c
** File description:
** Day 05 Task 05
*/

int my_compute_square_root(int nb)
{
    int i = 1;
    int result = 0;

    while (result < nb) {
        result = i * i;
        if (result == nb) {
            return i;
        }
        i++;
    }
    return 0;
}
