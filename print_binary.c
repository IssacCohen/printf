#include "main.h"
#include <unistd.h>

/**
 ** print_binary - Prints the binary representation of an unsigned integer
 ** @form: The unsigned integer to be converted to binary and printed
 * @f: argument
 **
 ** Return: Number of digits (bits) printed
 */
int print_binary(va_list form, flags_t *f)
{
	int len = 0, i;
	unsigned int num = va_arg(form, unsigned int);
	unsigned int tmp = num;
	char str[100];

	(void)f;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (tmp)
	{
		len++;
		tmp /= 2;
	}
	tmp = num;
	for (i = len - 1; i >= 0; i--)
	{
		str[i] = (tmp % 2) + '0';
		tmp /= 2;
	}
	write(1, str, len);
	return (len);
}
