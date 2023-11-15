#include "main.h"

/**
 * welcome - function that loads on running shell program
 */
void welcome(void)
{
clear();
printf("\n\n **************************************************************");
printf("\n\n\t ***************Shell Program*****************");
printf("\n\n\t\t\t Designed by:");
printf("\n\n\t\t Nana Ramaboea & Josh Myles");
printf("\n\n\t\t\t ALX PROGRAM");
printf("\n\n ************************************************************\n");
}

/**
 * main - the main funtion
 * Return: all input
 */
int main(void)
{
char input[MAXCOM];
char **args;
int i;

setup_signal_handlers();

while (1)
{
welcome();
fgets(input, sizeof(input), stdin);

if (input[strlen(input) - 1] == '\n')
{
input[strlen(input) - 1] = '\0';
}

args = parse_input(input);
if (args[0] != NULL)
{
if (handle_builtin(args) == 0)
{
execute_command(args);
}
}
for (i = 0; args[i] != NULL; i++)
{
free(args[i]);
}
free(args);
}
return (0);
}
