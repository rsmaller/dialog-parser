# Dialog Parser Project

## Overview
This is Jason's birthday present. Happy birthday Jason!!!

## What This Is All About
This is a digital story game/project written entirely in C partially for the purpose of understanding how nodes, pointers, and GitHub work.
The other half of this was for me to be funny and make a few laughs.

This project has a tree somewhere in the order of 80 dialog nodes. It took many hours of work to make the node parsing functionality and of course the nodes themselves. Enjoy!

## Usage
Firstly, after obtaining the binary either via release or compiling, the program can be run as follows:
```
./jameson.exe
```
The program does not take any arguments.

When the program is first run, you will be prompted to enter your name. Any open-ended questions like this will take a wide range of characters. The input will be recorded when you press `Enter`.

Closed-ended questions, however, will show a `[y\n]?:` prompt. Input is similarly recorded when you press `Enter`, but these questions will not record input unless the character `y` or the character `n` are given as input.

Be careful! Some dialog options will be closed off if you make the wrong choices.

Normally, dialog and questions are printed out character-by-character to perform a sort of typing animation on-screen. The `Space` key will skip the typing animation for a piece of dialog or a question.

After the typing animation is complete, either by pressing `Space` to skip it or simply waiting, pressing `Enter` will progress any dialog.

## Compatibility
This project uses the Windows.h and conio.h headers, which are exclusive to windows. Unless you somehow find a way to compile dialog-parser using these headers on Linux or macOS, this project is Windows-exclusive.

## Compiling
Assuming you have `make` installed, dialog-parser can be compiled to the binary `jameson.exe` via Makefile:
```
make
```
The binary can be quickly removed with:
```
make clean
```

If not, this project can be easily compiled with `gcc`:
```
gcc -o jameson.exe .\dialog_parser.c
```
