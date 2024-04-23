/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** my_strchr.c
*/

int my_strchr(char *str, char c)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}
