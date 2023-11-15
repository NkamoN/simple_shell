#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>

#define clear() printf("\033[H\033[J")
#define MAXCOM 1024
#define MAXLIST 100
#define MAX_TOKENS 64
#define TOKEN_DELIM "\t\n\r\a"

/**
 * Functions for main.c
 */
void welcome(void);

/**
 * Functions for parser.c
 */

char **parse_input(char *input);

/**
 * Functions for executor.c
 */

int execute_command(char **args);

/**
 * Functions for builtin.c
 */

int handle_builtin(char **args);

/**
 * Functions for signals.c
 */

void setup_signal_handlers(void);

#endif /** MAIN.h **/
