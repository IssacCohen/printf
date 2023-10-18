#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
/**
 * convert - converts number to str
 * @num: number
 * @base: base
 * @lowercase: hexa lowercase
 * Return:  str
 */
char *convert(unsigned long int num, int base, int lowercase)
{
	static char *rep;
	static char buffer[50];
	char *ptr;

	rep = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}
/**
 * _puts - prints a string
 * @str: pointer to the str
 * Return: ascii code for char
 */
int _puts(char *str)
{
	register int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}

/**
 * handleP - loops through a string and prints
 * every character
 * @form: va_list arguments from _printf
 * @f: argument
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int handleP(va_list form, flags_t *f)
{
	unsigned long int p = va_arg(form, unsigned long int);
	char *str;
	register int count = 0;
	(void)f;

	if (!p)
		return (_puts("(nil)"));
	str = convert(p, 16, 1);
	count += _puts("0x");
	count += _puts(str);
	return (count);
}

/**
 * rot13 - encodes a string into rot13
 * @form: string to encode
 * @f: argument
 *
 * Return: address of s
 */

int rot13(va_list form, flags_t *f)
{
	int i, j;
	char rot[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *s = va_arg(form, char *);
	(void)f;
	for (j = 0; s[j]; j++)
	{
		if (s[j] < 'A' || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z')
			_putchar(s[j]);
		else
		{
			for (i = 0; i <= 52; i++)
			{
				if (s[j] == rot[i])
					_putchar(rot13[i]);
			}
		}
	}

	return (j);
}

/**
 * print_rev - reverse str
 * @form: argument
 * @f: argument
 * Return: length string
 */
int print_rev(va_list form, flags_t *f)
{
	int i = 0, j;
	char *s = va_arg(form, char*);

	(void)f;

	if (!s)
		s = "(null)";

	while (s[i])
		i++;

	for (j = i - 1; j >= 0; j--)
		_putchar(s[j]);

	return (i);
}
