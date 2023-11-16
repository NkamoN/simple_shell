#include "main.h"

/**
 * execute_command - function
 * @args: input pointer to pointer
 * Return: status
 */
int execute_command(char **args)
{
pid_t pid;
int status;

pid = fork();

if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
perror("execvp");
exit(EXIT_FAILURE);
}
exit(EXIT_SUCCESS);
}
else if (pid < 0)
{
perror("fork");
exit(EXIT_FAILURE);
}
else
{
if (waitpid(pid, &status, 0) == -1)
{
perror("waitpid");
exit(EXIT_FAILURE);
}
if (WIFEXITED(status))
{
return (WEXITSTATUS(status));
}
}
return (1);
}
