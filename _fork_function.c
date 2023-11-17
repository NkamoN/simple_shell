#include "main.h"

/**
 * _fork_fun -function 4 creating a fork
 *@arg: command, values path
 *@av: name
 *@env: environment
 *@lineptr: command line
 *@np: process id
 *@c: Checker add new test
 *Return: 0 success
 */
int _fork_fun(char **arg, char **av, char **env, char *lineptr, int np, int c)
{
pid_t child;
int status;
char *format = "%s: %d: %s: not found\n";
child = fork();

if (child == 0)
{
if (execve(arg[0], arg, env) == -1)
{
fprintf(stderr, format, av[0], np, arg[0]);
if (!c)
free(arg[0]);
free(arg);
free(lineptr);
exit(errno);
}
}
else
{
wait(&status);
if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
return (WEXITSTATUS(status));
}
return (0);
}
