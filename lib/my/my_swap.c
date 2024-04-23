/*
** EPITECH PROJECT, 2023
** my_swap.c
** File description:
** Day 04 Task 01
*/

void my_swap(int *a, int *b)
{
    int temporaryVar;

    temporaryVar = *a;
    *a = *b;
    *b = temporaryVar;
}
