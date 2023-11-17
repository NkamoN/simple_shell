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
#include <errno.h>
#include <stdarg.h>

#define clear() printf("\033[H\033[J")
#define MAXLENGTH 100
#define MAXLIST 100
#define MAX_TOKENS 64
#define TOKEN_DELIM "\t\n\r\a"
#define MAX_LINE 80
#define MAX_ARGS 10

/**
 * Functions for main.c
 */
void welcome(void);
int _putchar(char c);
int _printf(const char *format, ...);
void execute_command(char *command_line, char *simple_shell);
void display_prompt(void);
int _strcmp(char *s1, char *s2);
extern char **environ;
void print_unknown_specifier(char specifier, size_t *count);
void print_null_or_str(char *s, size_t *count);
void print_unsigned(unsigned int num, size_t *count);
void print_octal(unsigned int num, size_t *count);
void print_hex(unsigned int num, int uppercase, size_t *count);
void print_binary(unsigned int num, size_t *count);
void print_integer(int num, size_t *count);
void handle_format_specifier(char specifier, va_list args, size_t *count);
void handle_hex(unsigned int num, int is_upper, size_t *count);
void handle_octal(unsigned int num, size_t *count);
void handle_unsign(unsigned int num, size_t *count);
void handle_bin(unsigned int num, size_t *count);
void handle_str(char *s, size_t *count);
void handle_char(char c, size_t *count);
void handle_int(unsigned int num, size_t *count);

/**
 * extra functions in
 */
void handle_command_with_args(char **args, int num_args);
void execCommand(char *line, char **av);
char **split_line(char *line);

#endif /** MAIN.h **/
