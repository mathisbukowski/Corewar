/*
** EPITECH PROJECT, 2023
** my_strstr.c
** File description:
** Day 06 Task 05
*/

#include <stddef.h>

char *tmp(char *str, const char *to_find, size_t i)
{
    size_t j;

    for (j = 0; to_find[j] != '\0'; ++j) {
        if (str[i + j] != to_find[j])
            break;
    }
    if (!to_find[j])
        return &str[i];
    return NULL;
}

char *my_strstr(char *str, const char *to_find)
{
    if (!*to_find)
        return str;
    for (size_t i = 0; str[i] != '\0'; ++i) {
        if (str[i] == to_find[0] && tmp(str, to_find, i) != NULL)
            return tmp(str, to_find, i);
    }
    return NULL;
}
