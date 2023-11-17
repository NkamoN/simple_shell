#include "main.h"

/**
 * print_unsigned - the function
 * @num: unsigned int
 * @count: count
 */
void print_unsigned(unsigned int num, size_t *count)
{
	char num_str[12];
	int len = 0;
	int i;

	if (num == 0)
		num_str[len++] = '0';
	while (num > 0)
	{
		num_str[len++] = num % 10 + '0';
		num = num / 10;
	}

	for (i = len - 1; i >= 0; i--)
	{
		write(1, &num_str[i], 1);
		(*count)++;
	}
}

/**
 * print_octal - function
 * @num: unsigned int
 * @count: count
 */
void print_octal(unsigned int num, size_t *count)
{
	char octal_str[12];
	int len = 0;
	int i;

	while (num > 0)
	{
		octal_str[len++] = num % 8 + '0';
		num = num / 8;
	}

	if (len == 0)
		octal_str[len++] = '0';

	for (i = len - 1; i >= 0; i--)
	{
		write(1, &octal_str[i], 1);
		(*count)++;
	}
}

/**
 * print_hex - function
 * @num: unsigned int
 * @uppercase: flag for uppercase hex
 * @count: count
 */
void print_hex(unsigned int num, int uppercase, size_t *count)
{
	char hex_str[12];
	int len = 0;
	int i, remainder;

	while (num > 0)
	{
		remainder = num % 16;
		if (remainder < 10)
			hex_str[len++] = remainder + '0';
		else
			hex_str[len++] = (uppercase ? 'A' : 'a') + remainder - 10;
		num = num / 16;
	}

	if (len == 0)
		hex_str[len++] = '0';

	for (i = len - 1; i >= 0; i--)
	{
		write(1, &hex_str[i], 1);
		(*count)++;
	}
}

/**
 * handle_char - function
 * @c: character
 * @count: count
 */
void handle_char(char c, size_t *count)
{
	write(1, &c, 1);
	(*count)++;
}

/**
 * handle_format_specifier - function for format spec
 * @specifier: character
 * @args: the arg list
 * @count: count
 */
void handle_format_specifier(char specifier, va_list args, size_t *count)
{
	switch (specifier)
	{
	case 'c':
		handle_char(va_arg(args, int), count);
		break;
	case 'd':
	case 'i':
		handle_int(va_arg(args, int), count);
		break;
	case 's':
		handle_str(va_arg(args, char *), count);
		break;
	case 'b':
		handle_bin(va_arg(args, unsigned int), count);
		break;
	case 'u':
		handle_unsign(va_arg(args, unsigned int), count);
		break;
	case 'o':
		handle_octal(va_arg(args, unsigned int), count);
		break;
	case 'x':
		handle_hex(va_arg(args, unsigned int), 0, count);
		break;
	case 'X':
		handle_hex(va_arg(args, unsigned int), 1, count);
		break;
	case '%':
		write(1, "%", 1);
		(*count)++;
		break;
	default:
		print_unknown_specifier(specifier, count);
		break;
	}
}
