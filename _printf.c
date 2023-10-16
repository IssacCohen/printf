#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            /*Parse and handle flags (0, -, +, space, #)*/
            while (*format == '0' || *format == '-' || *format == '+' || *format == ' ' || *format == '#')
            {
                if (*format == ' ')
                {
                    /* Handle space character (ignore it)*/
                }
                else if (*format == '+')
                {
                    /* Handle + character (ignore it)*/
                }
                else if (*format == '#')
                {
                    /* Handle # character (ignore it)*/
                }
                format++;
            }

            /* Parse and handle field width*/
            if (*format >= '1' && *format <= '9')
            {
                while (*format >= '0' && *format <= '9')
                {
                    format++;
                }
            }

            /* Parse and handle precision*/
            if (*format == '.')
            {
                format++;
                while (*format >= '0' && *format <= '9')
                {
                    format++;
                }
            }

            if (*format == 'l')
            {
                format++;
            }
            else if (*format == 'h')
            {
                format++;
            }

            /* Handle conversion specifiers*/
            if (*format == 'c')
            {
                char c = va_arg(args, int);
                write(1, &c, 1);
                count++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                if (!str)
                    str = "(null)";
                while (*str)
                {
                    write(1, str, 1);
                    str++;
                    count++;
                }
            }
            else if (*format == 'd' || *format == 'i')
            {
                int num = va_arg(args, int);
                if (num < 0)
                {
                    write(1, "-", 1);
                    count++;
                    num = -num;
                }
                count += handle_integer(num);
            }
            else if (*format == 'u')
            {
                unsigned int num = va_arg(args, unsigned int);
                count += handle_unsigned(num);
            }
            else if (*format == 'o')
            {
                unsigned int num = va_arg(args, unsigned int);
                count += handle_octal(num);
            }
            else if (*format == 'x' || *format == 'X')
            {
                unsigned int num = va_arg(args, unsigned int);
                count += handle_hex(num, (*format == 'X'));
            }
            else if (*format == 'p')
            {
                void *ptr = va_arg(args, void *);
                count += handle_pointer(ptr);
            }
            else if (*format == 'S')
            {
                char *str = va_arg(args, char *);
                count += handle_string_custom(str);
            }
            else if (*format == 'r')
            {
                char *str = va_arg(args, char *);
                count += handle_reverse(str);
            }
            else if (*format == 'R')
            {
                char *str = va_arg(args, char *);
                count += handle_rot13(str);
            }
	    else if (*format == 'b') {
                unsigned int num = va_arg(args, unsigned int);
                count += handle_binary(num);
            }
	    else if (*format == '%')
            {
                    write(1, "%", 1);
                    count++;
                    format++;
            }

            format++;
        }
        else
        {
            write(1, format, 1);
            count++;
            format++;
        }
    }

    va_end(args);
    return count;
}

/**
 * handle_integer - Helper function to print integers
 * @num: The integer to print
 * Return: The number of characters printed
 */
int handle_integer(int num)
{
    int count = 0;
    if (num / 10)
    {
        count += handle_integer(num / 10);
    }
    write(1, &num, 1);
    count++;
    return count;
}

/**
 * handle_binary - Helper function to print integers in binary
 * @num: The unsigned integer to print in binary
 * Return: The number of characters printed
 */
int handle_binary(unsigned int num)
{
    int count = 0;
    char digit ;
    if (num == 0) {
        return count; 
    }
    
    count += handle_binary(num / 2);

    digit = (num % 2 == 0) ? '0' : '1';
    write(1, &digit, 1);
    count++;

    return count;
}

/**
 * handle_unsigned - Helper function to print unsigned integers
 * @num: The unsigned integer to print
 * Return: The number of characters printed
 */
int handle_unsigned(unsigned int num)
{
    int count = 0;
    if (num / 10)
    {
        count += handle_unsigned(num / 10);
    }
    write(1, &num, 1);
    count++;
    return count;
}

/**
 * handle_octal - Helper function to print integers in octal
 * @num: The unsigned integer to print in octal
 * Return: The number of characters printed
 */
int handle_octal(unsigned int num)
{
    int count = 0;
    char digit;
    if (num / 8)
    {
        count += handle_octal(num / 8);
    }
    digit = num % 8 + '0';
    write(1, &digit, 1);
    count++;
    return count;
}

/**
 * handle_hex - Helper function to print integers in hexadecimal
 * @num: The unsigned integer to print in hexadecimal
 * @uppercase: Whether to print in uppercase or lowercase
 * Return: The number of characters printed
 */
int handle_hex(unsigned int num, int uppercase)
{
    int count = 0;
    char digit;
    if (num / 16)
    {
        count += handle_hex(num / 16, uppercase);
    }
    digit = num % 16;
    if (digit < 10)
    {
        digit += '0';
    }
    else
    {
        if (uppercase)
        {
            digit += 'A' - 10;
        }
        else
        {
            digit += 'a' - 10;
        }
    }
    write(1, &digit, 1);
    count++;
    return count;
}

/**
 * handle_pointer - Helper function to print pointers
 * @ptr: The pointer to print
 * Return: The number of characters printed
 */
int handle_pointer(void *ptr)
{
    int count = 0;
    write(1, "0x", 2);
    count += 2;
    if ((unsigned long)ptr == 0)
    {
        write(1, "0", 1);
        count++;
    }
    else
    {
        count += handle_hex((unsigned long)ptr, 1);
    }
    return count;
}

/**
 * handle_string_custom - Helper function to print custom string format
 * 
*/
int handle_string_custom(char *str)
{
    int count = 0;
    write(1, "0x", 2);
    count += 2;
    if ((unsigned long)str == 0)
    {
        write(1, "0", 1);
        count++;
    }
    else
    {
        count += handle_hex((unsigned long)str, 1);
    }
    return count;
}
/**
 * handle_reverse - Reverses and prints a string
 * @str: The string to reverse and print
 *
 * Return: The number of characters printed
 */

int handle_reverse(char *str)
{
    int i;
    int count = 0;
    int length;
    if (!str)
    {
        str = "(null)";
    }
    
    length = 0;
    while (str[length] != '\0')
    {
        length++;
    }

    for (i = length - 1; i >= 0; i--)
    {
        write(1, &str[i], 1);
        count++;
    }

    return count;
}

/**
 * handle_rot13 - Applies ROT13 encoding to a string and prints it
 * @str: The string to apply ROT13 to and print
 *
 * Return: The number of characters printed
 */

int handle_rot13(char *str)
{
    int count = 0;
    if (!str)
    {
        str = "(null)";
    }
    while (*str)
    {
        if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z'))
        {
            char offset = (*str >= 'A' && *str <= 'Z') ? 'A' : 'a';
            char encoded = (*str - offset + 13) % 26 + offset;
            write(1, &encoded, 1);
        }
        else
        {
            write(1, str, 1);
        }
        str++;
        count++;
    }
    return count;
}
