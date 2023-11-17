#include "main.h"
<<<<<<< HEAD
/**
 * _get_path -Functions gets variable PATH.
 * @env: enviroment
 * Return: value of PATH.
 */

char *_get_path(char **env)
{
size_t index = 0, var = 0, count = 5;
char *path = NULL;

for (index = 0; _strncmp(env[index], "PATH=", 5); index++)
;
if (env[index] == NULL)
return (NULL);

for (count = 5; env[index][var]; var++, count++)
;
path = malloc(sizeof(char) * (count + 1));

if (path == NULL)
return (NULL);

for (var = 5, count = 0; env[index][var]; var++, count++)
path[count] = env[index][var];

=======

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
>>>>>>> 68e8cf898335383f31220d817c8bd0b0d62504bd
path[count] = '\0';
return (path);
}
