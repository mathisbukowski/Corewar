/*
** EPITECH PROJECT, 2024
** corewar-dev
** File description:
** has_coding_byte.c
*/

int has_coding_byte(unsigned char code)
{
    if (code == 1 || code == 9 || code == 12 || code == 15)
        return 1;
    return 0;
}