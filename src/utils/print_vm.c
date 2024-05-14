/*
** EPITECH PROJECT, 2024
** corewar-dev
** File description:
** print_vm.c
*/

#include "corewar.h"
#include "my.h"
#include "my_printf.h"
#include <unistd.h>
#include <stdint.h>

void write_hex(uint32_t num, int fd)
{
    char buffer[9];
    char const *hex = "0123456789abcdef";

    for (int i = 0; i < 8; ++i) {
        buffer[7 - i] = hex[num % 16];
        num /= 16;
    }
    buffer[8] = '\0';
    write(fd, buffer, 8);
}

void write_byte(uint8_t byte, int fd)
{
    char const *hex = "0123456789abcdef";
    char buffer[2];

    buffer[0] = hex[byte >> 4];
    buffer[1] = hex[byte & 0x0F];
    write(fd, buffer, 2);
}

void write_string(const char *str, int fd)
{
    for (int i = 0; str[i] != '\0'; i++)
        write(fd, &str[i], 1);
}

void print_vm(corewar_t *corewar)
{
    int fd = STDOUT_FILENO;
    uint32_t i = 0;

    write_string("0x", fd);
    write_hex(i, fd);
    write_string(" : ", fd);
    for (i = 0; i < MEM_SIZE; i++) {
        if (i % 32 == 0 && i != 0) {
            write_string("\n0x", fd);
            write_hex(i, fd);
            write_string(" : ", fd);
        }
        write_byte(corewar->arena->memory[i], fd);
        if (i % 32 != 31)
            write(fd, " ", 1);
    }
    write(fd, "\n", 1);
}
