/*
** EPITECH PROJECT, 2023
** my_sort_int_array.c
** File description:
** my_sort_int_array
*/

int conditional_branche(int *tab, int i)
{
    int temporaryVar;

    if (tab[i] > tab[i + 1]) {
        temporaryVar = tab[i];
        tab[i] = tab[i + 1];
        tab[i + 1] = temporaryVar;
    }
}

void my_sort_int_array(int *tab, int size)
{
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < (size - 1); i++) {
            conditional_branche(tab, i);
        }
    }
}
