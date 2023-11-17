#include "main.h"
<<<<<<< HEAD
/**
 * _getline_command - Function displays prompt and gets user input.
 * Return: line of string input for user
 */

=======

/**
 * _getline_command - function to display prompt, get user input.
 * Return: user input
 */
>>>>>>> 68e8cf898335383f31220d817c8bd0b0d62504bd
char *_getline_command(void)
{
	char *lineptr = NULL;
	size_t charter_user = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	if (getline(&lineptr, &charter_user, stdin) == -1)
	{
		free(lineptr);
		return (NULL);
	}

	return (lineptr);
}
<<<<<<< HEAD

=======
>>>>>>> 68e8cf898335383f31220d817c8bd0b0d62504bd
