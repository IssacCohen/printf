#include "main.h"
#include <stdio.h>
#include <unistd.h>


/**
** print_unsigned - Prints an unsigned integer
** @form: The unsigned integer to be printed
* @f: argument
**
** Return: Number of digits printed
*/
int print_unsigned(va_list form,  flags_t *f)
{
	char buffer[20];
	unsigned int num = va_arg(form, unsigned int);
	int len = sprintf(buffer, "%u", num);

	(void)f;
	write(1, buffer, len);
	return (len);
}

/**
** print_octal - Prints an unsigned integer in octal notation
** @form: The unsigned integer to be printed
* @f: argument
**
** Return: Number of octal digits printed
*/
int print_octal(va_list form, flags_t *f)
{
	unsigned int num = va_arg(form, unsigned int);
	char *str = convert(num, 8, 0);
	int count = 0;

	if (f->hash == 1 && str[0] != '0')
		count += _putchar('0');
	count += _puts(str);
	return (count);
}

/**
** print_hex - Prints an unsigned integer in hexadecimal notation
** @form: The unsigned integer to be printed
* @f: argument
**
** Return: Number of hexadecimal digits printed
*/
int print_hex(va_list form, flags_t *f)
{
	unsigned int num = va_arg(form, unsigned int);
	char *str = convert(num, 16, 1);
	int count = 0;

	if (f->hash == 1 && str[0] != '0')
		count += _puts("0x");
	count += _puts(str);
	return (count);
}

/**
** print_hex1 - Prints an unsigned integer in hexadecimal notation
** @form: The unsigned integer to be printed
* @f: argument
**
** Return: Number of hexadecimal digits printed
*/
int print_hex1(va_list form, flags_t *f)
{
	unsigned int num = va_arg(form, unsigned int);
	char *str = convert(num, 16, 0);
	int count = 0;

	if (f->hash == 1 && str[0] != '0')
		count += _puts("0X");
	count += _puts(str);
	return (count);
}
