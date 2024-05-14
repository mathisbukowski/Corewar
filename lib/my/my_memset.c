/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** my_memset.c
*/

#include "../../include/my.h"

#include <stddef.h> // Pour size_t

void *my_memset(void *ptr, int value, size_t n)
{
    unsigned char *p = (unsigned char *)ptr;
    unsigned char val = (unsigned char)value;

    for (size_t i = 0; i < n; i++)
        p[i] = val;
    return ptr;
}
