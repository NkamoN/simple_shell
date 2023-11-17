#include "main.h"

/**
 * handle_int - function
 * @num: num input
 * @count: count
 */
void handle_int(unsigned int num, size_t *count)
{
	print_integer(num, count);
}

/**
 * handle_str - function
 * @s: string input
 * @count: count
 */
void handle_str(char *s, size_t *count)
{
	print_null_or_str(s, count);
}

/**
 * handle_bin - function
 * @num: number input
 * @count: count
 */
void handle_bin(unsigned int num, size_t *count)
{
	print_binary(num, count);
}

/**
 * handle_unsign - function
 * @num: number input
 * @count: count
 */
void handle_unsign(unsigned int num, size_t *count)
{
	print_unsigned(num, count);
}

/**
 * handle_octal - function
 * @num: num input
 * @count: count
 */
void handle_octal(unsigned int num, size_t *count)
{
	print_octal(num, count);
}
