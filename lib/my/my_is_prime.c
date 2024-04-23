/*
** EPITECH PROJECT, 2023
** my_is_prime.c
** File description:
** Day 05 Task 06
*/

int my_is_prime(int nb)
{
    int i = 2;

    if (nb % 2 == 0 || nb <= 1) {
        return 0;
    }
    while ((nb % i) != 0) {
        i++;
    }
    if ((nb % i) != 0 || i == nb) {
        return 1;
    }
    return 0;
}
