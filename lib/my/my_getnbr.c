/*
** EPITECH PROJECT, 2023
** my_getnbr.c
** File description:
** Day 04 Task 05
*/

#include <stdio.h>
#include "../../include/my.h"

/*int my_getnbr(char const *str)
{
    int length = my_strlen_getnbr(str);
    int i = 0;
    long number = 0;
    int isNeg = 0;
    while (i < length) {
        if (str[i] >= '0' && str[i] <= '9') {
            number = number * 10 + str[i] - 48;
            check_stop(str, &i, &length);
        } else if (str[i] == '-' && (str[i+1] >= '0' && str[i+1] <= '9')) {
            isNeg = 1;
        }
        i++;
        check_number(&number);
    }
    check_neg(&isNeg, &number);
    return 0;
}*/

int my_getnbr(char const *str)
{
    int result = 0;
    int i = 0;
    int isNeg = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            isNeg++;
        i++;
    }
    for (int j = i; str[j] != '\0'; j++) {
        if (str[j] >= '0' && str[j] <= '9')
            result = result * 10 + str[j] - 48;
    }
    if (isNeg % 2 != 0)
        result = -result;
    return result;
}
