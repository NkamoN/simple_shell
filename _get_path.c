#include "main.h"

/**
 * _get_path - function to get PATH.
 * @env: environment
 * Return: value
 */
char *_get_path(char **env)
{
size_t i;
size_t var;
size_t count = 5;
char *path = NULL;

for (i = 0; env[i] != NULL && _strncmp(env[i], "PATH=", 5) != 0; i++)
;
if (env[i] == NULL)
return (NULL);
for (count = 5, var = 0; env[i][var]; var++, count++)
;
path = malloc(sizeof(char) * (count + 1));
if (path == NULL)
return (NULL);
for (var = 5, count = 0; env[i][var]; var++, count++)
path[count] = env[i][var];
path[count] = '\0';
return (path);
}
