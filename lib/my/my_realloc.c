/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** my_realloc.c
*/

#include <stdlib.h>
#include <string.h>
#include "../../include/my.h"

void *my_realloc(void *ptr, size_t new_size, size_t old_size)
{
    void *new_ptr;
    size_t copy_size;

    if (ptr == NULL)
        return malloc(new_size);
    if (new_size == 0) {
        free(ptr);
        return NULL;
    }
    new_ptr = malloc(new_size);
    if (new_ptr == NULL)
        return NULL;
    copy_size = (new_size < old_size) ? new_size : old_size;
    my_memcpy(new_ptr, ptr, copy_size);
    free(ptr);
    return new_ptr;
}
