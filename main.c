#include "main.h"

/**
 * welcome - function that loads on running shell program
 */
void welcome(void)
{
_printf("\n\n **************************************************************");
_printf("\n\n\t ***************Shell Program*****************");
_printf("\n\n\t\t\t Designed by:");
_printf("\n\n\t\t Nana Ramaboea & Josh Myles");
_printf("\n\n\t\t\t ALX PROGRAM");
_printf("\n\n ************************************************************\n");
}

/**
 * display_prompt - entry point
 */
void display_prompt(void)
{
_printf("#JoshNana$ ");
fflush(stdout);
}

/**
 * execute_command - function execution
 * @command_line: the command line
 * @simple_shell: simple shell
 */
void execute_command(char *command_line, char *simple_shell)
{
pid_t pid;

if (_strcmp(command_line, "exit") == 0)
{
_printf("Exit...\n");
exit(EXIT_SUCCESS);
}
if (_strcmp(command_line, "exit") == 0)
{
char **env = environ;

while (*env != NULL)
{
_printf("%s\n", *env);
env++;
}
return;
}
pid = fork();

if (pid == -1)
perror("Forking error");
else if (pid == 0)
{
char *args[MAX_ARGS];
int i = 0;
char *token = strtok(command_line, " ");

while (token != NULL && i < MAX_ARGS - 1)
{
args[i++] = token;
token = strtok(NULL, " ");
}
args[i] = NULL;
execvp(args[0], args);
perror(simple_shell);
exit(EXIT_FAILURE);
}
else
waitpid(pid, NULL, 0);
}
/**
 * main - main function
 * @argc: arg count
 * @argv: arg vector
 * Return: 0 or 1
 */
int main(int argc __attribute__((unused)), char **argv)
{
char command[MAXLENGTH];
welcome();
while (1)
{
display_prompt();

if (fgets(command, sizeof(command), stdin) == NULL)
{
_printf("\nExit...\n");
break;
}

command[strcspn(command, "\n")] = '\0';

execute_command(command, argv[0]);
}
return (0);
}

