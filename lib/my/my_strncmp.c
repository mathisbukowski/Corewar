/*
** EPITECH PROJECT, 2023
** my_strncmp.c
** File description:
** Day 06 Task 07
*/

#include <stddef.h>

int my_strncmp(const char *s1, const char *s2, int n)
{
    while (n > 0) {
        n--;
        if (*s1 == '\0' || *s2 == '\0' || *s1 != *s2)
            return (int)(*s1) - (int)(*s2);
        s1++;
        s2++;
    }
    return 0;
}
