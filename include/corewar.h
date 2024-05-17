/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** corewar.h
*/

#ifndef COREWAR_COREWAR_H
    #define COREWAR_COREWAR_H
    #include "op.h"
    #include "my.h"
    #include "my_printf.h"

/**
 * @brief Structure representing an instruction.
 */
typedef struct instruction_s {
    int opcode;         /**< Opcode of the instruction */
    int num_args;       /**< Number of arguments of the instruction */
    int args[3];        /**< Arguments of the instruction */
    char types[3];      /**< Types of the arguments */
    int encoding_byte;  /**< Encoding byte of the instruction */
} instruction_t;

/**
 * @brief Structure representing a champion.
 */
typedef struct champion_s {
    int id;                     /**< Identifier of the champion */
    char *name;                 /**< Name of the champion */
    char *comment;              /**< Comment of the champion */
    int prog_size;              /**< Program size of the champion */
    int pc;                     /**< Program counter */
    int start_pc;               /**< Starting position the program counter */
    int reg[REG_NUMBER];        /**< Registers of the champion */
    int carry;                  /**< Carry flag */
    int is_alive;               /**< Alive flag */
    int last_live;              /**< Cycle of the last live signal */
    int cycle;                  /**< Current cycle of the champion */
    int cycle_to_wait;          /**< Cycles to wait before next instruction */
    instruction_t *instruct;    /**< Pointer to the current instruction */
    struct champion_s *next;    /**< Pointer to the next champion */
} champion_t;

/**
 * @brief Structure representing the arena.
 */
typedef struct arena_s {
    unsigned char *memory;  /**< Memory of the arena */
    int cycle_to_die;       /**< Number of cycles before inactivechampionsdie*/
    int live;               /**< Number of live signals received */
    int last_live;          /**< Identifier of the last champion to
    * send a live signal */
} arena_t;

/**
 * @brief Main structure representing the Corewar game.
 */
typedef struct corewar_s {
    int dump;               /**< Cycle at which the memory is dumped*/
    arena_t *arena;         /**< Pointer to the arena structure */
    int cycle;              /**< Current cycle of the game */
    int nb_champs;          /**< Number of champions in the game */
    int *fd;                /**< File descriptors of the champions */
    int n_value[4];         /**< Values of the -n parameters */
    char *champ_names[4];   /**< Names of the champion files */
    champion_t *champs;     /**< Pointer to the list of champions */
} corewar_t;

/**
 * @brief Array of function pointers for executing commands.
 *
 * Each element of the array corresponds to a function that
 * *executes a specific instruction,
 * taking as parameters an instruction structure, a champion
 * structure, and a corewar structure.
 */
extern int (* const run_commands[])(instruction_t *,
    champion_t *, corewar_t *);


/**
 * @brief Print the usage message for the program.
 */
void print_usage(void);

/**
 * @brief Initialize the corewar structure.
 * @param av Argument vector from the command line.
 * @return Pointer to the initialized corewar structure.
 */
corewar_t *init_corewar(char **av);

/**
 * @brief Initialize a champion structure.
 * @param corewar Pointer to the corewar structure.
 * @return Pointer to the initialized champion structure.
 */
champion_t *init_champ(corewar_t *corewar);

/**
 * @brief Free the memory allocated for the corewar structure.
 * @param corewar Pointer to the corewar structure to free.
 */
void free_corewar(corewar_t *corewar);

/**
 * @brief Check the command line arguments.
 * @param av Argument vector from the command line.
 * @param corewar Pointer to the corewar structure.
 * @return 0 if arguments are valid, else 1.
 */
int check_args(char **av, corewar_t *corewar);

/**
 * @brief Check for the dump flag in the arguments.
 * @param corewar Pointer to the corewar structure.
 * @param av Argument vector from the command line.
 * @return 0 if the dump flag is found and valid, else 1.
 */
int check_dump(corewar_t *corewar, char **av);

/**
 * @brief Check for the champion files in the arguments.
 * @param corewar Pointer to the corewar structure.
 * @param av Argument vector from the command line.
 * @return 0 if the champion files are valid, else 1.
 */
int check_champion(corewar_t *corewar, char **av);


// Loading Instructions
/**
 *  @brief Exec the ld instruction (load)
 *  This function loads a value in a register or a memory address.
 *  @param instr Pointer to the structure of instructions.
 *  @param champ Pointer to the entity in exec.
 *  @param corewar Pointer to the global structure.
 *  @return Return 0 if the exec is all good else return 1.
**/
int ld_command(instruction_t *instr, champion_t *champ, corewar_t *corewar);

/**
 *  @brief Exec the ld instruction (load index)
 *  This function loads a value from an address calculated by
 *  adding a register and an immediate value,
 *  and stores this value in a register
 *  @param instr Pointer to the structure of instructions.
 *  @param champ Pointer to the entity in exec.
 *  @param corewar Pointer to the global structure.
 *  @return Return 0 if the exec is all good else return 1.
**/
int ldi_command(instruction_t *instr, champion_t *champ, corewar_t *corewar);

/**
 *  @brief Exec the ld instruction (long load)
 *  This function loads a value into a register or a memory address,
 *  without interpreting the first parameter as an index.
 *  @param instr Pointer to the structure of instructions.
 *  @param champ Pointer to the entity in exec.
 *  @param corewar Pointer to the global structure.
 *  @return Return 0 if the exec is all good else return 1.
**/
int lld_command(instruction_t *instr, champion_t *champ, corewar_t *corewar);

/**
 *  @brief Exec the ld instruction (long load index)
 *  This function loads a value from an address calculated by
 *  adding a register and an immediate value,
 *  without interpreting the first parameter as an index,
 *  and stores this value in a register.
 *  @param instr Pointer to the structure of instructions.
 *  @param champ Pointer to the entity in exec.
 *  @param corewar Pointer to the global structure.
 *  @return Return 0 if the exec is all good else return 1.
**/
int lldi_command(instruction_t *instr, champion_t *champ, corewar_t *corewar);

/**
 *  @brief Exec the st instruction (store)
 *  This function stores the first param value into the second
 *  @param instr Pointer to the structure of instructions.
 *  @param champ Pointer to the entity in exec.
 *  @param corewar Pointer to the global structure.
 *  @return Return 0 if the exec is all good else return 1.
**/
int st_command(instruction_t *instr, champion_t *champ, corewar_t *corewar);

/**
 *  @brief Exec the sti instruction (store index)
 *  This function copies the content of the first param (register)
 *  into a new address made off the two others params
 *  @param instr Pointer to the structure of instructions.
 *  @param champ Pointer to the entity in exec.
 *  @param corewar Pointer to the global structure.
 *  @return Return 0 if the exec is all good else return 1.
**/
int sti_command(instruction_t *instr, champion_t *champ, corewar_t *corewar);

int add_champion(corewar_t *corewar, champion_t *new_champ);
int check_arguments(instruction_t *instr);

/**
 * @brief Open a file .cor read the header and
 * read the instructions
 * @param corewar  pointer to the corewar structure
 * @return
 */
int get_file_data(corewar_t *corewar);

/**
 * @brief Execute the add instruction.
 * @param instr Pointer to the structure of instructions.
 * @param champ Pointer to the champion executing the instruction.
 * @param corewar Pointer to the global corewar structure.
 * @return 0 if the execution is successful, else 1.
 */
int add_command(instruction_t *instr, champion_t *champ, corewar_t *corewar);

/**
 * @brief Execute the sub instruction.
 * @param instr Pointer to the structure of instructions.
 * @param champ Pointer to the champion executing the instruction.
 * @param corewar Pointer to the global corewar structure.
 * @return 0 if the execution is successful, else 1.
 */
int sub_command(instruction_t *instr, champion_t *champ, corewar_t *corewar);

/**
 * @brief Execute the aff instruction (affichage).
 * @param instr Pointer to the structure of instructions.
 * @param champ Pointer to the champion executing the instruction.
 * @param corewar Pointer to the global corewar structure.
 * @return 0 if the execution is successful, else 1.
 */
int aff_command(instruction_t *instr, champion_t *champ, corewar_t *corewar);

/**
 * @brief Execute the fork instruction.
 * @param instr Pointer to the structure of instructions.
 * @param champ Pointer to the champion executing the instruction.
 * @param corewar Pointer to the global corewar structure.
 * @return 0 if the execution is successful, else 1.
 */
int fork_command(instruction_t *instr, champion_t *champ, corewar_t *corewar);

/**
 * @brief Execute the lfork instruction (long fork).
 * @param instr Pointer to the structure of instructions.
 * @param champ Pointer to the champion executing the instruction.
 * @param corewar Pointer to the global corewar structure.
 * @return 0 if the execution is successful, else 1.
 */
int lfork_command(instruction_t *instr, champion_t *champ, corewar_t *corewar);

/**
 * @brief Execute the zjmp instruction (jump if zero).
 * @param instr Pointer to the structure of instructions.
 * @param champ Pointer to the champion executing the instruction.
 * @param corewar Pointer to the global corewar structure.
 * @return 0 if the execution is successful, else 1.
 */
int zjmp_command(instruction_t *instr, champion_t *champ, corewar_t *corewar);

/**
 * @brief Execute the and instruction.
 * @param instr Pointer to the structure of instructions.
 * @param champ Pointer to the champion executing the instruction.
 * @param corewar Pointer to the global corewar structure.
 * @return 0 if the execution is successful, else 1.
 */
int and_command(instruction_t *instr, champion_t *champ, corewar_t *corewar);

/**
 * @brief Execute the or instruction.
 * @param instr Pointer to the structure of instructions.
 * @param champ Pointer to the champion executing the instruction.
 * @param corewar Pointer to the global corewar structure.
 * @return 0 if the execution is successful, else 1.
 */
int or_command(instruction_t *instr, champion_t *champ, corewar_t *corewar);

/**
 * @brief Execute the xor instruction.
 * @param instr Pointer to the structure of instructions.
 * @param champ Pointer to the champion executing the instruction.
 * @param corewar Pointer to the global corewar structure.
 * @return 0 if the execution is successful, else 1.
 */
int xor_command(instruction_t *instr, champion_t *champ, corewar_t *corewar);

/**
 * @brief Execute the live instruction.
 * @param instr Pointer to the structure of instructions.
 * @param champ Pointer to the champion executing the instruction.
 * @param corewar Pointer to the global corewar structure.
 * @return 0 if the execution is successful, else 1.
 */
int live_command(instruction_t *instr, champion_t *champ, corewar_t *corewar);

/**
 * @brief Get the instructions from a champion's file.
 * @param corewar Pointer to the corewar structure.
 * @param champ Pointer to the champion structure.
 * @return 0 if instructions are successfully read, else 1.
 */
int get_instructions(corewar_t *corewar, champion_t *champ);

/**
 * @brief Free the memory allocated for a champion.
 * @param champion Pointer to the champion structure to free.
 */
void free_champion(champion_t *champion);

/**
 * @brief Print the virtual machine's state.
 * @param corewar Pointer to the corewar structure.
 */
void print_vm(corewar_t *corewar);

/**
 * @brief Check if an opcode has a coding byte.
 * @param opcode The opcode to check.
 * @return 1 if the opcode has a coding byte, else 0.
 */
int has_coding_byte(int opcode);

/**
 * @brief Get the file extension from the argument.
 * @param av Argument vector.
 * @return The file extension.
 */
int get_extension(char *av);

/**
 * @brief Parse and set the coding byte of an instruction.
 * @param coding_byte The coding byte to set.
 * @param instr Pointer to the instruction structure.
 */
void get_coding_byte(int coding_byte, instruction_t *instr);

/**
 * @brief Check if the code has an index.
 * @param code The code to check.
 * @param ac The argument count.
 * @return 1 if the code has an index, else 0.
 */
int has_idx(unsigned char code, int ac);

/**
 * @brief Run the virtual machine.
 * @param corewar Pointer to the corewar structure.
 * @return 0 if the execution is successful, else 1.
 */
int run_vm(corewar_t *corewar);

/**
 * @brief Get the direct argument.
 * @param corewar Pointer to the corewar structure.
 * @param pc Program counter.
 * @param size Size of the argument.
 * @return The direct argument.
 */
int get_direct_argument(corewar_t *corewar, int pc, int size);

/**
 * @brief Get the indirect argument.
 * @param corewar Pointer to the corewar structure.
 * @param pc Program counter.
 * @return The indirect argument.
 */
int get_indirect_argument(corewar_t *corewar, int pc);

/**
 * @brief Get the register argument.
 * @param corewar Pointer to the corewar structure.
 * @param pc Program counter.
 * @return The register argument.
 */
int get_register_argument(corewar_t *corewar, int pc);

/**
 * @brief Get the size of the argument.
 * @param code The code of the argument.
 * @param i The index of the argument.
 * @param types The types of the arguments.
 * @return The size of the argument.
 */
int get_arg_size(int code, int i, char types[3]);

/**
 * @brief Decode arguments without a coding byte.
 * @param corewar Pointer to the corewar structure.
 * @param champ Pointer to the champion structure.
 * @param instr Pointer to the instruction structure.
 * @param nb The number of arguments.
 */
void decode_no_coding_byte(corewar_t *corewar,
    champion_t *champ, instruction_t *instr, int nb);

/**
 * @brief Decode the arguments of an instruction.
 * @param corewar Pointer to the corewar structure.
 * @param champ Pointer to the champion structure.
 * @param instr Pointer to the instruction structure.
 * @param nb The number of arguments.
 */
void decode_arguments(corewar_t *corewar,
    champion_t *champ, instruction_t *instr, int nb);

/**
 * @brief Execute the instructions for a champion.
 * @param corewar Pointer to the corewar structure.
 * @param champ Pointer to the champion structure.
 */
void execute_instructions(corewar_t *corewar, champion_t *champ);

/**
 * @brief Swap the endianess of a value.
 * @param value The value to swap.
 * @return The value with swapped endianess.
 */
int swap_endian(int value);

#endif //COREWAR_COREWAR_H
