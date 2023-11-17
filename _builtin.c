#include "main.h"
<<<<<<< HEAD
/**
 * _exit_command - Function exits simple shell
 * @arg: pointer with the direction argument.
 * @lineptr: standard input string
 * @_exit: value of exit
 * Return: None
=======

/**
 * _exit_command - function to exit
 * @arg: pointer with the direction argument.
 * @lineptr: input string
 * @_exit: value
 * Return: nothing
>>>>>>> 68e8cf898335383f31220d817c8bd0b0d62504bd
 */
void _exit_command(char **arg, char *lineptr, int _exit)
{
int exit_status = 0;

if (!arg[1])
{
free(lineptr);
free(arg);
exit(_exit);
}
exit_status = atoi(arg[1]);

free(lineptr);
free(arg);
exit(exit_status);
}

/**
<<<<<<< HEAD
 *_getenv - Function to get all env
 *@env: environment
 *Return: 0
 */

void _getenv(char **env)
{
size_t run = 0;

=======
 *_getenv - function 2 get env
 *@env: environment
 *Return: nothing
 */
void _getenv(char **env)
{
size_t run = 0;
>>>>>>> 68e8cf898335383f31220d817c8bd0b0d62504bd
while (env[run])
{
write(STDOUT_FILENO, env[run], _strlen(env[run]));
write(STDOUT_FILENO, "\n", 1);
run++;
}
}
<<<<<<< HEAD


=======
>>>>>>> 68e8cf898335383f31220d817c8bd0b0d62504bd
