include "main.h"

/**
 * print_error - function
 * @message: input pointer
 */
void print_error(const char *message)
{
perror(message);
}

/**
 * free_tokens - function
 * @tokens: input pointer to pointer
 * Return: nothing
 */
void free_tokens(char **tokens)
{
if (tokens == NULL)
return;

for (int i = 0; tokens[i] != NULL; i++)
{
free(tokens[i]);
}
free(tokens);
}

