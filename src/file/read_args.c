/*
** EPITECH PROJECT, 2024
** corewar-dev
** File description:
** read_args.c
*/

int read_arguments(int fd, unsigned char opcode, int index)
{
    op_t *current_op = &op_tab[opcode - 1];
    unsigned char coding_byte;
    ssize_t bytes_read = read(fd, &coding_byte, 1);
    if (bytes_read != 1) {
        printf("Erreur: Lecture du coding byte pour l'instruction %d échouée\n", index);
        return 84;
    }

    instruction_t args;
    get_coding_byte(coding_byte, &args);

    for (int j = 0; j < current_op->nbr_args; j++) {
        unsigned char arg[DIR_SIZE];
        int arg_size;

        switch (args.types[j]) {
            case T_REG:
                arg_size = REG_SIZE;
                break;
            case T_DIR:
                arg_size = DIR_SIZE;
                break;
            case T_IND:
                arg_size = IND_SIZE;
                break;
            default:
                printf("Type d'argument non reconnu pour l'instruction %d\n", index);
                return 84;
        }

        bytes_read = read(fd, &arg, arg_size);
        if (bytes_read != arg_size) {
            printf("Erreur: Lecture de l'argument %d pour l'instruction %d échouée\n", j + 1, index);
            return 84;
        }
        // Affichage d'un résumé de l'argument
        printf("Instruction %d - Paramètre %d: ", index, j + 1);
        for (int k = 0; k < arg_size; k++) {
            printf("%02x", arg[k]);
        }
        printf("\n");
    }
    return 0;
}