#include "main.h"

/**
* print_binary - function
* @num: unsigned int
* @count: count
*/
void print_binary(unsigned int num, size_t *count)
{
	char bin_str[32];
	int len = 0;
	int i;

	while (num > 0)
	{
		bin_str[len++] = (num % 2) + '0';
		num = num / 2;
	}

	if (len == 0)
		bin_str[len++] = '0';

	for (i = len - 1; i >= 0; i--)
	{
		write(1, &bin_str[i], 1);
		(*count)++;
	}
}

/**
* print_integer - function
* @num: int
* @count: count
*/
void print_integer(int num, size_t *count)
{
	char *num_str;
	int len = 0;
	int i;
	int max_digits;

	if (num == 0)
	{
		num_str = malloc(2);
		if (num_str == NULL)
		{
			return;
		}
		num_str[len++] = '0';
	}
	else if (num < 0)
	{
		write(1, "-", 1);
		(*count)++;
		num = -num;
	}
	max_digits = 12;

	num_str = malloc(max_digits);
	if (num_str == NULL)
	{
		return;
	}

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
	free(num_str);
}

/**
 * print_null_or_str - functin
 * @s: characters
 * @count: count
 */
void print_null_or_str(char *s, size_t *count)
{
	size_t len = 0;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		(*count) += 6;
	}
	else
	{
		while (s[len] != '\0')
			len++;
		write(1, s, len);
		(*count) += len;
	}
}

/**
 * print_unknown_specifier - fucntion
 * @specifier: unknown specifier
 * @count: character count
 */
void print_unknown_specifier(char specifier, size_t *count)
{
	write(1, "%", 1);
	write(1, &specifier, 1);
	(*count) += 2;
}

/**
 * _printf - custom printf
 * @format: a charcter string
 * Return: return type is a string
 */
int _printf(const char *format, ...)
{
	size_t count = 0;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
			write(1, format, 1), count++;
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
				write(1, format, 1), count++;
			else
				handle_format_specifier(*format, args, &count);
		}
		format++;
	}
	va_end(args);
	return (count);
}
