#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * print_cent - Prints a string using a local buffer.
 * @form: The string to be printed.
 * @f: argument
 *
 * Return: The number of characters printed.
 */
int print_cent(va_list form, flags_t *f)
{
	(void)form;
	(void)f;
	write(1, "%", 1);
	return (1);
}

/**
 * print_string - Prints a string using a local buffer.
 * @form: The string to be printed.
 * @f: argument
 *
 * Return: The number of characters printed.
 */
int print_string(va_list form, flags_t *f)
{
	char buffer[BUFFER_SIZE];
	int count = 0, i = 0;
	char *str = va_arg(form, char *);
	(void)f;

	if (str == NULL)
	{
		str = "(null)";
	}

	while (*str)
	{
		if (i == BUFFER_SIZE - 1)
		{
			write(1, buffer, i);
			i = 0;
		}
		buffer[i] = *str;
		i++;
		count++;
		str++;
	}

	if (i > 0)
	{
		write(1, buffer, i);
	}

	return (count);
}

/**
* print_bigS - Non printable char
* @form: va_list arguments
* @f: argument
* Return: number of char
*/
int print_bigS(va_list form, flags_t *f)
{
	int i, count = 0;
	char *s = va_arg(form, char *);
	char *res;
	(void)f;

	if (!s)
		return (_puts("(null)"));

	for (i = 0; s[i]; i++)
	{
		if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
		{
			_puts("\\x");
			count += 2;
			res = convert(s[i], 16, 0);
		if (!res[1])
			count += _putchar('0');
		count += _puts(res);
		}
		else
			count += _putchar(s[i]);
	}
	return (count);
}
