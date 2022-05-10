# Mips Emulator

A program that lets you run a subset of MIPS assembly code and view the final state of the environment. 

## Overview

Since I plan on creating my own programming language as well as a compiler as a personal challenge in the near future, I started off with a MIPS assembly emulator to dip my toes into the water. It takes assembly instructions as input and will output what the environment looks like at the end (registers, memory, etc.). 

The goal of this was to learn finite automatas, parsing algorithms (munching), symbol tables and how assembly works behind the hood. 

I had a lot of fun with this project, especially since I tried to make it easy to convert into an ARM emulator in the future if I needed.

In theory, you could convert this to an arm emulator by changing/adding command files which inherit the abstract `Command.h` class to follow arm format. And change the MIPS DFA to properly tokenize ARM syntax instead of MIPS!

There are also other differences in ARM such as the number of registers which can all be easily changed in the `MipsClient.h` file.

## Implemented Commands

Below are all the commands that this emulator supports. You can easily add more commands by creating the command file in `src/commands/` and adding the logic there, follow the format in `Command.h`. The *Command Factory* will handle the rest of the logic.

| Command | Syntax         | Purpose                      |
|---------|----------------|------------------------------|
| add     | add $d, $s, $t | $d = $s + $t                 |
| addi    | addi $d, $s, i | $d = $s + i                  |
| sub     | sub $d, $s, $t | $d = $s - $t                 |
| mfhi    | mfhi $d        | $d = hi                      |
| mflo    | mflo $d        | $d = lo                      |
| mult    | mult $d, $s    | $hi:$lo = $d * $s            |
| div     | div $s, $t     | $hi = $s % $t, $lo = $s / $t |
| jr      | jr $s          | pc = $s                      |
| beq     | beq $d, $s, i  | if $s = $d, pc = pc + i      |
| bne     | bne $d, $s, i  | if $s != $d, pc = pc + i     |
| lw      | lw $s, i($t)   | $s = M[i + $t]               |
| sw      | sw $s, i($t)   | M[i + $t] = $s               |
| slt     | slt $d, $s, $t | if $s < $t then $d = 1       |
| pri     | slt $d         | print $d to stdout           |
| mem     | slt i          | print M\[i\] to stdout       |


## Compiling / Running

Compile the program with `make`. Run it using `./emulator [initialconfig] < [yourmipsfile]`.

The initial configuration file is an optional argument and simply initializes the registers and memory slots that you specify. An example is included in `/examples`.

## Next Steps

In the future I want to make it possible to link assembly files together, convert to binary and have the emulator run using the binary file rather than the command file directly.

