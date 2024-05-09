/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** get_file_data.c
*/

#include <fcntl.h>
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

int open_file(char *file, header_t *header)
{
    int fd = open(file, O_RDONLY);
    int size = sizeof(header_t);

    if (fd == -1) {
        my_putstr("Error: File not found\n");
        return 84;
    }
    if (read(fd, header, size) == -1) {
        my_putstr("Error: File is empty\n");
        return 84;
    }
    header->prog_size = swap_endian(header->prog_size);
    header->magic = swap_endian(header->magic);
    close(fd);
    return 0;
}

int get_instructions(char *file, corewar_t *corewar)
{
    int fd = open(file, O_RDONLY);
    int size = sizeof(header_t);
    int prog_size = corewar->champs->prog_size;
    int i = 0;

    if (fd == -1)
        return 84;
    lseek(fd, size, SEEK_SET);
    corewar->champs->instructs = malloc(sizeof(instruction_t) * prog_size);
    if (corewar->champs->instructs == NULL)
        return 84;
    for (i = 0; i < prog_size; i++) {
        read(fd, &corewar->champs->instructs[i].opcode, 1);
        if (corewar->champs->instructs[i].opcode < 1
            || corewar->champs->instructs[i].opcode > 16)
            return 84;
    }
    return 0;
}

int get_file_data(char *file, corewar_t *corewar)
{
    header_t header;

    if (open_file(file, &header) == 84)
        return 84;
    corewar->champs->name = my_strdup(header.prog_name);
    corewar->champs->comment = my_strdup(header.comment);
    corewar->champs->prog_size = header.prog_size;
    if (get_instructions(file, corewar) == 84)
        return 84;
    return 0;
}
