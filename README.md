# CLI Word Puzzle Engine


**Date:** November 20th, 2025

---------------------------------------------------------

This repository contains a Linux command line utility named `wordsearch`, written in C, that processes a two-dimensional
grid of characters to search for hidden words. The scripts use pointer arithmetic and memory management to store and keep 
track of multiple arrays representing rows, columns and grids of a word search game. The scripts also detect when an error
is reached and provides specific error messages, and usage strings to standard error while returning different exit codes.

## Functionality of the program:
- Inputs first a number (`Number of Columns`), and then characters (`Charcters in Grid`), and then a equal sign and words (`Words to Search`), `wordsearch`
- Inputs lines in a file as the `Number of Columns` and `Charcters in Grid`, and uses standard input for words (`Words to Search`), `wordsearch [FILE]`
- Outputs information about the program's syntax & usage, `wordsearch --help`

## Files in the repository:
- `wordsearch.c`, contains the program that the user interacts with from the command line and deals with array operations. This file is coded in C.
- `gridChecks.c`, contains the program that deals with checking the word grids for word matches. This file is coded in C.
- `main.c`, contains the main program that is initially ran, calls other functions for the program and frees all memory once program is ran. This file is coded in C.
- `.github/workflows/test.yml`, compiles the program on every push to ensure good working of the program and its files, and outputs the results in the file, `solved.txt`.
