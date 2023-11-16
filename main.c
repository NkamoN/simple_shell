#include "main.h"

/**
 * welcome - function that loads on running shell program
 */
void welcome(void)
{
clear();
_printf("\n\n **************************************************************");
_printf("\n\n\t ***************Shell Program*****************");
_printf("\n\n\t\t\t Designed by:");
_printf("\n\n\t\t Nana Ramaboea & Josh Myles");
_printf("\n\n\t\t\t ALX PROGRAM");
_printf("\n\n ************************************************************\n");
}

/**
 * main - main function
 * @ac: arg count
 * @av: arg vector
 * @env: NULL terminated arrays of strings
 * Return: return 0 or -1
 */
int main(int ac, char **av, char **env __attribute__((unused)))
{
int i;
if (ac > 1)
{
_printf("%s\n", av[0]);
for (i = 1; i < ac; i++)
{
_printf("%s\n", av[i]);
}
}
else
{
while (1)
{
welcome();
char *line = NULL;
size_t size;
ssize_t read;

_printf("#cisfun$ ");
read = getline(&line, &size, stdin);
if (read == -1)
{
perror("GETERROR");
return (1);
}

if (read > 1)
{
line[read - 1] = '\0';
line[read - 1] = '\n';
}
execCommand(line, av);
free(line);
handle_command_with_args(av, ac);
}
}
return (0);
}

/**
* execCommand - execute entered commands
* @line: input
* @av: argument vector
* Return: nothing
*/
void execCommand(char *line, char **av)
{
char *token, **args = malloc(MAX_ARGS * sizeof(char *));
int i = 0, executable = 0;

if (!args)
exit(1);

token = strtok(line, " \t\n");
while (token)
args[i++] = token, token = strtok(NULL, " \t\n");
args[i] = NULL;

for (i = 0; args[i]; i++)
if (access(args[i], X_OK) == 0)
executable = 1;

if (executable)
{
if (fork() == 0)
execve(args[0], args, NULL), perror("Execution error"), exit(1);
else
wait(NULL);
}
else
_printf("%s: File or directory unavailable\n", av[0]);

free(args);
}
