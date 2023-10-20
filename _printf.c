#include "main.h"

/**
 * get_specifier - checks if specifier is valid
 *		and prints it with appropriate function
 * @format: pointer to specifier
 *
 * Return: pointer to appropriate function when successful
 *		or NULL when not successful
 */

int (*get_specifier(const char *format))(va_list,  flags_t *) {
	int i;

	specify_t arr[15] = {{"c", print_char}, {"s", print_string},
		{"%", print_cent}, {"d", handleInt}, {"i", handleInt},
		{"b", print_binary}, {"u", print_unsigned}, {"o", print_octal},
		{"X", print_hex1}, {"x", print_hex}, {"p", handleP},
		{"R", rot13}, {"r", print_rev}, {"S", print_bigS}, {NULL, NULL}};


	for (i = 0; arr[i].spec != NULL; i++)
	{
		if (*(arr[i].spec) == *format)
			return (arr[i].func);
	}
	return (NULL);
}

/**
 * _printf - Function to handle formatted char
 * @format: formatted char
 * @...: args to print
 *
 * Return: count of args printed
 */

int _printf(const char *format, ...)
{
	register int len = 0;
	int (*f)(va_list, flags_t *);
	flags_t flags = {0, 0, 0};

	va_list form;

	va_start(form, format);

	if (!format || (format[0] == '%' && !format[1]) ||
	    (format[0] == '%' && format[1] == ' ' && !format[2]))
		return (-1);
	while (*format)
	{
		if (*format != '%')
		{
			len += write(1, format, 1);
			format++;
		}
		if (*format == '%')
		{
			format++;
			while (get_flag(*format, &flags))
				format++;
			f = get_specifier(format);
			if (f != NULL)
			{
				len += f(form, &flags);
				format++;
			}
			else if (*format != '\0')
			{
				len += _putchar('%');
				len += _putchar(*format);
				format++;
			}
		}
	}
	va_end(form);
	return (len);
}
