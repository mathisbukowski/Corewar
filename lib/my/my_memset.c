/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** my_memset.c
*/

#include "../../include/my.h"

#include <stddef.h> // Pour size_t

void *my_memset(void *ptr, int size, size_t n)
{
    unsigned char *p = ptr;
    unsigned char value = (unsigned char)size;

    for (size_t i = 0; i < n; i++)
        p[i] = value;
    return ptr;
}
