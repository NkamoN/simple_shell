#define "main.h"

/**
 * parse_input - function that handles input
 * @input: pointer to input
 * Return: 0 or 1
 */
char **parse_input(char *input)
{
int bufsize = MAX_TOKENS;
int position = 0;
char **tokens = (char)malloc(sizeof(char) * bufsize);
char *token;

if (!tokens)
{
fprintf(stderr, "Allocation error\n");
exit(EXIT_FAILURE);
}
token = strtok(input, TOKEN_DELIM);

while (token != NULL)
{
tokens[position] = strdup(token);
position++;
if (position >= bufsize)
{
bufsize += MAX_TOKENS;
tokens = (char)realloc(tokens, sizeof(char) * bufsize);
if (!tokens)
{
fprintf(stderr, "Allocation error\n");
exit(EXIT_FAILURE);
}
}
token = strtok(NULL, TOKEN_DELIM);
}
tokens[position] = NULL;
return (tokens);
}

/**
 * free_tokens - function
 * @tokens: input pointer to pointer
 * Return: nothing
 */
void free_tokens(char **tokens)
{
for (int i = 0; tokens[i] != NULL; i++)
{
free(tokens[i]);
}
free(tokens);
}
