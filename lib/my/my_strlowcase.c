/*
** EPITECH PROJECT, 2023
** my_strlowcase.c
** File description:
** my_strlowcase
*/

#include <stdlib.h>
#include "../../include/my.h"

char *my_strlowcase(char *str)
{
    int size = my_strlen(str);
    char *result = malloc(sizeof(char) * size);

    for (int i = 0; i < size; i++) {
        if (str[i] <= 90 && str[i] >= 65) {
            result[i] = str[i] + 32;
        } else {
            result[i] = str[i];
        }
    }
    return result;
}
