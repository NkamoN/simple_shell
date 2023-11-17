#include "main.h"

/**
 * handle_command_with_args - function
 * @args: input pointer to pointer
 * @num_args: count of number of args
 * Return: nothing
 */
void handle_command_with_args(char **args,
int num_args)
{
int i;
if (access(args[0], X_OK) == 0)
{
if (fork() == 0)
{
execve(args[0], args, NULL);
}
else
{
wait(NULL);
}
}
else
{
_printf("%s\n", args[0]);
if (num_args > 1)
{
for (i = 1; i < num_args; i++)
{
_printf("%s ", args[i]);
}
_printf("\n");
}
}
}

