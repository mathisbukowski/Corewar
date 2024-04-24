/*
** EPITECH PROJECT, 2023
** my_strstr.c
** File description:
** Day 06 Task 05
*/

char *tmp(char *str, char const *to_find, int i, int j)
{
    if (str[i] == to_find[j]) {
        j++;
        if (to_find[j] == '\0')
            return &str[i - j + 1];
    } else
        j = 0;
    return 0;
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (tmp(str, to_find, i, j) != 0)
            return tmp(str, to_find, i, j);
        i++;
    }
    return 0;
}
