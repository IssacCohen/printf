#include <unistd.h>
#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - writes the character c to stdout
 * @form: The character to print
 * @f: argument
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set.
 */
int print_char(va_list form,  flags_t *f)
{
	char c = va_arg(form, int);
	(void)f;

	return (write(1, &c, 1));
}
