PROJECT DEVELOPERS
1. Nana Ramaboea
2. Josh Myles Karamuzi

Project checklist:
1. Display a prompt
2. Take user commands, commands always end with a new line
3. The prompt is displayed again each time a command has been executed
4. Simple, no semicolons, no pipes, no redirections
5. Commands are made of only one word and no arguments will be passed to programs
6. If an executable cannot be found, print an error message and display the prompt again.
7. Handle Errors as well as the "end of file" condition

Project Breakdown
1. Command Parsing:
When you type a command, the shell parses the input to understand the command and its arguments. It breaks down the input into tokens, separating them based on spaces or other delimiters.

2. Path Resolution:
If the command includes a path (like /usr/bin/ls), the shell directly executes the specified program. If not, the shell searches for the command in the directories listed in the system's PATH environment variable. It looks through each directory in order, trying to find an executable file with the specified name.

3. Forking a Process:
Once the shell determines the path of the executable, it creates a new process using the fork() system call. The child process is an exact copy of the shell process at this point.

4. Loading the Program:
The child process loads the executable program into its memory using the exec() family of system calls (such as execve() in Unix-like systems). The exec() system call replaces the child process's memory with the memory of the new program.

5. Execution:
The operating system's scheduler determines when and for how long the CPU executes the child process. The program runs, performing the specified task.

6. Waiting for Completion:
If the shell needs to wait for the command to complete (for example, in the case of interactive shells or when using the wait() system call), the parent shell process waits until the child process finishes executing.

7. Returning Control:
Once the command completes its execution, the shell regains control and may display the prompt again, allowing the user to enter another command.

This process continues as long as the user interacts with the shell.

*****************************************************************************

## Task 0 : Betty would be proud
Write a beautiful code that passes the Betty checks

## Task 1 :  Simple shell 0.1
Write a UNIX command line interpreter.

## Task 2 :Simple shell 0.2
Simple shell 0.1 +
Handle command lines with arguments

## Task 3 : Simple shell 0.3
Simple shell 0.2 +
Handle the PATH fork must not be called if the command doesn’t exist

## Task 4 : Simple shell 0.4
Simple shell 0.3 +
Implement the exit built-in, that exits the shell
Usage: exit
You don’t have to handle any argument to the built-in exit

## Task 5
Simple shell 0.4 +
Implement the env built-in, that prints the current environment
