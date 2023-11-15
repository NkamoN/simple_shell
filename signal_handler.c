#include "main.h"

/**
 * sigint_handler - function to handle sign
 * @sig: input
 * Return: nothing
 */
void sigint_handler(int sig)
{
printf("\nReceived Ctrl+C (SIGINT)\n");
}

/**
 * sigtstp_handler - function
 * @sig: input
 * Return: nothing
 */
void sigtstp_handler(int sig)
{
printf("\nReceived Ctrl+Z (SIGTSTP)\n");
}

/**
 * setup_signal_handlers - function
 * Return: info
 */
void setup_signal_handlers(void)
{
struct sigaction sa_int;
sa_int.sa_handler = sigint_handler;
sa_int.sa_flags = 0;
sigemptyset(&sa_int.sa_mask);
if (sigaction(SIGINT, &sa_int, NULL) == -1)
{
perror("sigaction(SIGINT) failed");
exit(EXIT_FAILURE);
}

struct sigaction sa_tstp;
sa_tstp.sa_handler = sigtstp_handler;
sa_tstp.sa_flags = 0;
sigemptyset(&sa_tstp.sa_mask);
if (sigaction(SIGTSTP, &sa_tstp, NULL) == -1)
{
perror("sigaction(SIGTSTP) failed");
exit(EXIT_FAILURE);
}
}
