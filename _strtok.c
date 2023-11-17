#include "main.h"

size_t _strspn(const char *s1, const char *s2);
char *_strchr(const char *s, int c);
size_t _strcspn(const char *s1, const char *s2);

/**
* _strtok - function 2 break string s1 into tokens & null-terminates them.
* delimiter - characters at beginning & end
* of str are skipped. On each subsequent call delim can change.
* @str: string 2 tokenize
* @delim: string character that delimit str.
* Return: the first/next token where possible else null-pointer.
**/
char *_strtok(char *str, const char *delim)
{
static char *p;
if (str)
p = str;
else if (!p)
return (0);
str = p + _strspn(p, delim);
p = str + _strcspn(str, delim);
if (p == str)
return (p = 0);
p = *p ? *p = 0, p + 1 : 0;
return (str);
}

/**
* _strcspn - function to compute length of max initial segment of string
* pointed 2 by s1 which consists entirely of characters not from the
* string pointed 2 by s2.
* @s1: string to check
* @s2: string to compare
* Return: length of segment.
**/
size_t _strcspn(const char *s1, const char *s2)
{
size_t ret = 0;
while (*s1)
{
if (_strchr(s2, *s1))
return (ret);
s1++, ret++;
}
return (ret);
}

/**
* _strspn - function computes length of maximum initial segment of string
* pointed 2 by s1 which consists entirely of characters from string
* pointed 2 by s2.
* @s1: string to compute length
* @s2: string delimit
* Return: length of segment.
**/
size_t _strspn(const char *s1, const char *s2)
{
size_t ret = 0;
while (*s1 && _strchr(s2, *s1++))
ret++;
return (ret);
}

/**
* _strchr - function 2 locate first occurrence of c (converted to char) in
* string pointed by s. The terminating null character is considered to be
* part of @s.
* @s: string
* @c: character
* Return: pointer to located character, or null pointer
* if character does not occur in string.
**/
char *_strchr(const char *s, int c)
{
while (*s != (char)c)
if (!*s++)
return (0);
return ((char *)s);
}
