/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** my_itoa.c
*/

#include <stdlib.h>

char *my_itoa(int num)
{
    int len = 0;
    int temp = num;
    char *str;

    while (temp != 0) {
        temp /= 10;
        len++;
    }
    str = malloc(sizeof(char) * (len + 1));
    str[len] = '\0';
    while (num != 0) {
        len--;
        str[len] = num % 10 + '0';
        num /= 10;
    }
    return str;
}
