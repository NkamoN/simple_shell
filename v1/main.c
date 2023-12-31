#include "main.h"
/**
 * main - Function handles main arguments 
 * @ac:count of arguments
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
 * main - function handles main arguments 
 * @ac: count of arguments
 * @av: arguments
 * @env: environment
 * Return: _exit = 0.
 */
int main(int ac, char **av, char **env)
{
char *getcommand = NULL, **user_command = NULL;
int pathValue = 0, _exit = 0, n = 0;
(void)ac;

welcome();

while (1)
{
getcommand = _getline_command();
if (getcommand)
{
pathValue++;
user_command = _get_token(getcommand);
if (!user_command)
{
free(getcommand);
continue;
}
if ((!_strcmp(user_command[0], "exit")) && user_command[1] == NULL)
_exit_command(user_command, getcommand, _exit);
if (!_strcmp(user_command[0], "env"))
_getenv(env);
else
{
n = _values_path(&user_command[0], env);
_exit = _fork_fun(user_command, av, env, getcommand, pathValue, n);
if (n == 0)
free(user_command[0]);
}
free(user_command);
}
else
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n", 1);
exit(_exit);
}
free(getcommand);
}
return (_exit);
}


