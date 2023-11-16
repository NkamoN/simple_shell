#include "main.h"

/**
 * handle_builtin - function to handle builtin commands
 * @args: pointer to pointer for args
 * Return: 0 or 1
 */
int handle_builtin(char **args)
{
if (args == NULL || args[0] == NULL)
{
return (1);
}
if (strcmp(args[0], "cd") == 0)
{
if (args[1] == NULL)
{
fprintf(stderr, "cd: missing argument\n");
}
else
{
if (chdir(args[1]) != 0)
{
perror("cd");
}
}
return (1);
}
else if (strcmp(args[0], "exit") == 0)
{
exit(0);
}
else if (strcmp(args[0], "help") == 0)
{
printf("MyShell Help:\n");
printf("  cd [directory]  Change the current directory\n");
printf("  exit            Exit the shell\n");
printf("  help            Display this help message\n");
return (1);
}
return (0);
}
