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
 * takeInput - function to take input
 * @str: string
 * Return: 0 or 1
 */
int takeInput(char *str)
{
char *buf;
buf = readline("\n>>> ");
if (strlen(buf) != 0)
{
add_history(buf);
strcpy(str, buf);
return (0);
}
else
{
return (1);
}
}

/**
 * printDirectory - function to print new shell line
 */
void printDirectory(void)
{
char cwd[1024];
getcwd(cwd, sizeof(cwd));
printf("\nDir: %s, cwd");
}

/**
 * main - the main funtion
 * Return: all input
 */
int main(void)
{
char inputString[MAXCOM], *parsedArgs[MAXLIST];
char *parsedArgsPiped[MAXLIST];
int execFlag = 0;

welcome();

while (1)
{
printDirectory();
if (takeInput(inputString))
{
continue;
}
execFlag = processString(inputString, parsedArgs, parsedArgsPiped);
if (execFlag == 1)
{
execArgs(parsedArgs);
}
if (execFlag == 2)
{
execArgsPiped(parsedArgs, parsedArgsPiped);
}
}
return (0);
}
