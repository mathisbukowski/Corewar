/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** get_file_data.c
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "corewar.h"
#include "op.h"

int swap_endian(int value)
{
    int leftmost_byte;
    int left_middle_byte;
    int right_middle_byte;
    int rightmost_byte;
    int result;

    leftmost_byte = (value & 0x000000FF) >> 0;
    left_middle_byte = (value & 0x0000FF00) >> 8;
    right_middle_byte = (value & 0x00FF0000) >> 16;
    rightmost_byte = (value & 0xFF000000) >> 24;
    leftmost_byte <<= 24;
    left_middle_byte <<= 16;
    right_middle_byte <<= 8;
    rightmost_byte <<= 0;
    result = (leftmost_byte | left_middle_byte
        | right_middle_byte | rightmost_byte);
    return result;
}

int read_header(int fd, header_t *header, champion_t *champ)
{
    int size = sizeof(header_t);

    if (fd == -1) {
        my_putstr("Error: File not found\n");
        return 84;
    }
    if (read(fd, header, size) == -1) {
        my_putstr("Error: File is empty\n");
        close(fd);
        return 84;
    }
    champ->prog_size = swap_endian(header->prog_size);
    champ->comment = my_strdup(header->comment);
    champ->name = my_strdup(header->prog_name);
    return 0;
}

static int get_data(int fd, header_t *header, champion_t *champ,
    corewar_t *corewar)
{
    if (read_header(fd, header, champ) == 84)
        return 84;
    return 0;
}

int get_file_data(corewar_t *corewar)
{
    header_t header;
    champion_t *champ = NULL;
    int fd;

    for (int i = 0; i < corewar->nb_champs; i++) {
        fd = corewar->fd[i];
        if (champ != NULL)
            free_champion(champ);
        champ = init_champion();
        if (get_data(fd, &header, champ, corewar) != 0) {
            free_champion(champ);
            return 84;
        }
        if (add_champion(corewar, champ) != 0) {
            free_champion(champ);
            return 84;
        }
    }
    return 0;
}
