/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** my_memcpy.c
*/

#include <stdlib.h>

void *my_memcpy(void *dest, const void *src, size_t n)
{
    char *copy_src = (char *)src;
    char *copy_dest = (char *)dest;

    for (int i = 0; i < n; i++)
        copy_dest[i] = copy_src[i];
    return dest;
}
