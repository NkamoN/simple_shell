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
#define MAXCOM 1000
#define MAXLIST 100

void welcome(void);
int takeInput(char *str);
void printDirectory(void);

#endif /** MAIN.h **/
