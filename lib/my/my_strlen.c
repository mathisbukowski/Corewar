/*
** EPITECH PROJECT, 2023
** my_strlen.c
** File description:
** Day 04 Task 03
*/

int my_strlen(char const *str)
{
    int index = 0;

    while (str[index] != '\0') {
        index++;
    }
    return (index);
}
