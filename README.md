0x16. C - Simple Shell
# Simple Shell Project by Imane Benammou and Kenny Chukwuebuka

Welcome to our Simple Shell project repository! This project involves creating a basic UNIX command interpreter (shell) using the C programming language. This README file provides an overview of the project, its functionalities, and how to use our shell.

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Supported Commands](#supported-commands)
- [Contributors](#contributors)

## Description
Our Simple Shell project aims to recreate the functionality of a basic UNIX command interpreter. It can execute commands, manage environment variables, handle built-in commands, and execute basic shell operators.

## Features
- Displays a custom prompt for user input.
- Executes commands using the `execve` system call.
- Handles command lines with arguments.
- Implements built-in commands like `exit`, `env`, `setenv`, and more.
- Supports basic shell operators like `;`, `&&`, and `||`.
- Handles variable replacement for special variables like `$?` and `$$`.
- Allows reading commands from a file.

## Getting Started
To compile and run our shell, follow these steps:
1. Clone this repository to your local machine.
2. Open a terminal window and navigate to the repository directory.
3. Compile the shell using the following command:
 gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
4. Run the shell using the command:
 ./hsh

## Usage
After running the shell, you will see a custom prompt where you can enter commands. Our shell supports various functionalities, including executing external programs, built-in commands, managing environment variables, and more.

## Supported Commands
Our shell supports the following commands and functionalities:
- Basic external program execution.
- Built-in commands:
- `exit`: Exit the shell.
- `env`: Print the current environment variables.
- `setenv VARIABLE VALUE`: Initialize or modify an environment variable.
- `unsetenv VARIABLE`: Remove an environment variable.
- `cd [DIRECTORY]`: Change the current directory.
- `alias [name[='value'] ...]`: Define or list aliases.
- Shell operators:
- `;`: Separate and execute multiple commands.
- `&&` and `||`: Execute commands conditionally.
- Variable replacement:
- `$?`: Replaced by the exit status of the last executed command.
- `$$`: Replaced by the shell's process ID.
## Contributors
- Imane Benammou
- Kenny Chukwuebuka
