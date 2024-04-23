/*
** EPITECH PROJECT, 2023
** my_put_nbr.c
** File description:
** my_put_nbr
*/

#include "../../include/my.h"

int my_put_nbr(int nb)
{
    int n;

    if (nb > 9) {
        n = nb / 10;
        nb -= 10 * n;
        my_put_nbr(n);
    }
    my_putchar('0' + nb);
}
