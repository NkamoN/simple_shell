#include "main.h"

/**
 * handle_hex - function
 * @num: num input
 * @is_upper: 0 or 1
 * @count: count
 */
void handle_hex(unsigned int num, int is_upper, size_t *count)
{
	print_hex(num, is_upper, count);
}

/**
 * _strcmp - function for comparison
 * @s1: first string compare second
 * @s2: second string
 * Return: 0 if equal
 * negative - s1 is less than s2
 * positive - s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}

	if (*s1 == '\0' && *s2 != '\0')
		return (-1);
	else if (*s1 != '\0' && *s2 == '\0')
		return (1);
	else
		return (0);
}

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

/**
 * _putchar - writes to stdout
 * @c: character print
 * Return: 1 or -1
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}
