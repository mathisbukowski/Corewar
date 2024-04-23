/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** my_strdup.c
*/

#include <stdlib.h>
#include "../../include/my.h"

char *my_strdup(char const *src)
{
    char *dest = malloc(my_strlen(src) + 1);

    if (dest == NULL)
        return (NULL);
    my_strcpy(dest, src);
    return dest;
}
