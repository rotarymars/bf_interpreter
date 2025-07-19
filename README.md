# Brainfuck Interpreter

A C++ implementation of a Brainfuck interpreter with dynamic memory expansion.

## Description

This project implements a Brainfuck interpreter in C++. Brainfuck is an esoteric programming language designed to be simple and minimal, with only 8 commands that operate on a tape of memory cells.

## Features

- **Dynamic Memory Expansion**: The interpreter automatically expands memory when the pointer goes beyond the allocated bounds
- **Standard Brainfuck Commands**: Supports all 8 Brainfuck commands (`+`, `-`, `>`, `<`, `[`, `]`, `.`, `,`)
- **File Input**: Reads Brainfuck code from files
- **Memory Safety**: Uses smart pointers for memory management
- **Cross-platform**: Works on Linux, macOS, and Windows

## Brainfuck Commands

| Command | Description |
|---------|-------------|
| `+` | Increment the current memory cell |
| `-` | Decrement the current memory cell |
| `>` | Move pointer to the right |
| `<` | Move pointer to the left |
| `[` | Start of loop (jump past `]` if current cell is 0) |
| `]` | End of loop (jump back to `[` if current cell is non-zero) |
| `.` | Output the current cell's value as ASCII character |
| `,` | Input a character and store its ASCII value in current cell |

## Building

### Prerequisites

- C++ compiler with C++11 support (GCC, Clang, or MSVC)
- Make (optional, for using the Makefile)

### Compilation

```bash
# Using g++
g++ -std=c++11 -o brainfuck main.cpp

# Using clang++
clang++ -std=c++11 -o brainfuck main.cpp

# Using the provided Makefile (if available)
make
```

## Usage

```bash
./brainfuck <filename>
```

Where `<filename>` is the path to a text file containing Brainfuck code.

### Example

Create a file called `hello.bf` with the following content:

```
++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.
```

Then run:

```bash
./brainfuck hello.bf
```

This should output: `Hello World!`

## Memory Management

The interpreter uses a dynamic memory system that automatically expands when needed:

- **Initial Memory**: 30,000 cells (configurable)
- **Expansion**: Memory doubles in size when the pointer goes out of bounds
- **Memory Safety**: Uses `std::shared_ptr` for automatic memory management

## Project Structure

```
.
├── main.cpp          # Main interpreter implementation
├── .gitignore        # Git ignore rules
└── README.md         # This file
```

## Examples

### Simple Counter
```
+++++[>+++++<-]>.
```
Outputs the character with ASCII value 25.

### Hello World
```
++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.
```
Outputs "Hello World!".

### User Input Echo
```
,[.,]
```
Reads characters from input and echoes them back until EOF.

## License

This project is open source. Feel free to use, modify, and distribute as needed.

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## References

- [Brainfuck Language Specification](https://esolangs.org/wiki/Brainfuck)
- [Brainfuck Tutorial](https://gist.github.com/roachhd/dce54bec8ba55fb17d3a)