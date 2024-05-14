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
    printf("Name : %s \nComment : %s\nProg Size: %d \n",
    champ->name, champ->comment, champ->prog_size);
    return 0;
}

void write_to_memory(unsigned char *memory, char const *buffer,
    champion_t *champ)
{
    for (int i = 0; i < champ->prog_size; i++)
        memory[(champ->pc + i) % MEM_SIZE] = buffer[i];
}

int read_context(int fd, corewar_t *corewar, champion_t *champion)
{
    char *buffer = malloc(champion->prog_size);
    ssize_t bytes = 0;

    if (buffer == NULL)
        return 84;
    bytes = read(fd, buffer, champion->prog_size);
    if (bytes == -1) {
        free(buffer);
        close(fd);
        return 84;
    }
    write_to_memory(corewar->arena->memory, buffer, champion);
    free(buffer);
    return 0;
}

static int get_data(int fd, header_t *header, champion_t *champ,
    corewar_t *corewar)
{
    if (read_header(fd, header, champ) == 84)
        return 84;
    if (read_context(fd, corewar, champ) == 84)
        return 84;
    return 0;
}

static int get_op_index(int fd,
    champion_t *champ, corewar_t *corewar)
{
    header_t header;

    if (get_data(fd, &header, champ, corewar) != 0) {
        free_champion(champ);
        return 84;
    }
    if (add_champion(corewar, champ) != 0) {
        free_champion(champ);
        return 84;
    }
    return 0;
}

int get_file_data(corewar_t *corewar)
{
    champion_t *champ = NULL;
    int fd;

    for (int i = 0; i < corewar->nb_champs; i++) {
        fd = corewar->fd[i];
        if (champ != NULL) {
            free_champion(champ);
            champ = NULL;
        }
        champ = init_champion();
        if (champ == NULL)
            return 84;
        champ->pc = (i * MEM_SIZE) / corewar->nb_champs;
        if (get_op_index(fd, champ, corewar) != 0)
            return 84;
    }
    if (champ != NULL)
        free_champion(champ);
    return 0;
}
