#include "main.h"
/**
 * get_line_command - Display prompt and wait for user input.
 * Return: line of string input by user
 */
char *get_line_command(void)
{
	char *lineptr = NULL;
	size_t charter_user = 0;


	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$", 2);


	if (getline(&lineptr, &charter_user, stdin) == -1)
	{
		free(lineptr);
		return (NULL);
	}


	return (lineptr);
}

