/*
** EPITECH PROJECT, 2023
** my_compute_power_rec.c
** File description:
** Day 05 Task 04
*/

int my_compute_power_rec(int nb, int p)
{
    if (p < 0) {
        return 0;
    } else if (p == 0) {
        return 1;
    } else {
        return nb * my_compute_power_rec(nb, p - 1);
    }
}
