# Corewar

Corewar is a programming game where players write warriors in assembly language to battle in a virtual arena called "The Memory". This project provides a Corewar environment written in C. A first year project made in Epitech.

## Features

- **Assembler:** Converts assembly code into machine code.
- **Virtual Machine/Arena:** Executes the machine code instructions.
- **Champions:** Sample warrior programs to compete.

## Installation

1. Clone the repository:
```sh
    git clone https://github.com/mathisbukowski/Corewar.git
```
2. Navigate to the project directory:
```sh
    cd Corewar
```
3. Compile the project:
```sh
    make
```

## Usage

- **Assembler:** Converts `.s` files to `.cor` files.
```sh
    ./asm champion.s
```
- **Virtual Machine:** Executes the battle between champions. (2 --> 4)
```sh
    ./corewar champ1.cor champ2.cor
```

## Directory Structure

- `include/`: header files.
- `lib/my/`: Library functions.
- `src/`: Source code files.

## Contributing

Contributions are welcome ! Please fork the repository and create a pull request to contribute.

## Authors

- Mathis Bukowski
- Rafael Drouart

For questions, open an [issue](https://github.com/mathisbukowski/Corewar/issues) !