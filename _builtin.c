#include "main.h"

/**
 * _exit_command - function to exit
 * @arg: pointer with the direction argument.
 * @lineptr: input string
 * @_exit: value
 * Return: nothing
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
 *_getenv - function 2 get env
 *@env: environment
 *Return: nothing
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
