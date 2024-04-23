/*
** EPITECH PROJECT, 2023
** my_find_prime_sup.c
** File description:
** Day 05 Task 07
*/

int my_find_is_prime(int nb)
{
    int i = 2;

    if (nb == 0 || nb == 1)
        return 0;
    while ((nb % i) != 0)
        i++;
    if ((nb % i) != 0 || i == nb)
        return 1;
    return 0;
}

int my_find_prime_sup(int nb)
{
    int i = nb;

    if (nb < 0) {
        return 0;
    }
    while (my_find_is_prime(i) != 1) {
        my_find_is_prime(i);
        i++;
    }
    return i;
}
