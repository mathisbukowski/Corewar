/*
** EPITECH PROJECT, 2023
** my_strupcase.c
** File description:
** my_strupcase
*/

#include <stdlib.h>
#include "../../include/my.h"

char *my_strupcase(char *str)
{
    int size = my_strlen(str);
    char *result = malloc(sizeof(char) * size);

    for (int i = 0; i < size; i++) {
        if (str[i] <= 122 && str[i] >= 97) {
            result[i] = str[i] - 32;
        } else {
            result[i] = str[i];
        }
    }
    return result;
}
