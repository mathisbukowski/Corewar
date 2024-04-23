/*
** EPITECH PROJECT, 2023
** my_strcat.c
** File description:
** Day 07 Task 02
*/

#include <stdlib.h>
#include "../../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    char *new_dest = malloc(sizeof(char) *
        (my_strlen(dest) + my_strlen(src) + 1));

    if (new_dest == NULL)
        return NULL;
    for (; dest[i] != '\0'; i++)
        new_dest[i] = dest[i];
    for (; src[j] != '\0'; j++)
        new_dest[i + j] = src[j];
    new_dest[i + j] = '\0';
    free(dest);
    return new_dest;
}
