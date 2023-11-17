<<<<<<< HEAD
#ifndef MAIN_HEADER
#define MAIN_HEADER
=======
#ifndef MAIN_H
#define MAIN_H
>>>>>>> 68e8cf898335383f31220d817c8bd0b0d62504bd
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
<<<<<<< HEAD

extern char **environ;

=======
#include <stdarg.h>

#define clear() printf("\033[H\033[J")

extern char **environ;

/**
 * functions for main.c
 */
void welcome(void);

/**
 * functions for _str_utils.c
 */
>>>>>>> 68e8cf898335383f31220d817c8bd0b0d62504bd
int _strcmp(char *s1, char *s2);
size_t _strncmp(char *s1, char *s2, size_t n);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _putchar(char c);

<<<<<<< HEAD
=======
/**
 * functions for _strtok.c
 */
>>>>>>> 68e8cf898335383f31220d817c8bd0b0d62504bd
char *_get_path(char **env);
int _values_path(char **arg, char **env);
char *_getline_command(void);
void _getenv(char **env);
char **_get_token(char *lineptr);
void _exit_command(char **args, char *lineptr, int _exit);
int _fork_fun(char **arg, char **av, char **env,
char *lineptr, int np, int c);
char *_strtok(char *str, const char *delim);

<<<<<<< HEAD

#endif 

=======
/**
 * functions for functions_1.c
 */
void handle_format_specifier(char specifier, va_list args, size_t *count);
void handle_hex(unsigned int num, int is_upper, size_t *count);
void handle_octal(unsigned int num, size_t *count);
void handle_unsign(unsigned int num, size_t *count);
void handle_bin(unsigned int num, size_t *count);
void handle_str(char *s, size_t *count);
void handle_char(char c, size_t *count);
void handle_int(unsigned int num, size_t *count);

/**
 * other functions
 */
int _printf(const char *format, ...);
void print_unknown_specifier(char specifier, size_t *count);
void print_null_or_str(char *s, size_t *count);
void print_unsigned(unsigned int num, size_t *count);
void print_octal(unsigned int num, size_t *count);
void print_hex(unsigned int num, int uppercase, size_t *count);
void print_binary(unsigned int num, size_t *count);
void print_integer(int num, size_t *count);

#endif /** MAIN_H **/
>>>>>>> 68e8cf898335383f31220d817c8bd0b0d62504bd
