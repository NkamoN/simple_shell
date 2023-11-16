#include "main.h"
/**
 * _exit_command - Function exits simple shell
 * @arg: pointer with the direction argument.
 * @lineptr: standard input string
 * @_exit: value of exit
 * Return: None
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
 *_getenv - Function to get all env
 *@env: environment
 *Return: 0
 */

void _getenv(char **env)
{
size_t run = 0;

while (env[run])
{
write(STDOUT_FILENO, env[run], _strlen(env[run]));
write(STDOUT_FILENO, "\n", 1);
run++;
}
}


