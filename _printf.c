#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - Produces output according to a format.
 * @format: Format string containing characters and specifiers.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;
    int length_modifier;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            /* Parse and handle flags (0, -, +, space, #) */
            while (*format == '0' || *format == '-' || *format == '+' || *format == ' ' || *format == '#')
            {
                if (*format == ' ')
                {
                    /* Handle space character (ignore it) */
                }
                else if (*format == '+')
                {
                    /* Handle + character (ignore it) */
                }
                else if (*format == '#')
                {
                    /* Handle # character (ignore it) */
                }
                format++;
            }

            /* Parse and handle field width */
            if (*format >= '1' && *format <= '9')
            {
                while (*format >= '0' && *format <= '9')
                {
                    format++;
                }
            }

            /* Parse and handle precision */
            if (*format == '.')
            {
                format++;
                while (*format >= '0' && *format <= '9')
                {
                    format++;
                }
            }

            /* Handle length modifiers */
            length_modifier = 0;
            while (*format == 'l' || *format == 'h')
            {
                if (*format == 'l')
                    length_modifier++;
                else if (*format == 'h')
                    length_modifier--;
                format++;
            }

            /* Handle conversion specifiers */
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
                if (length_modifier == 0)
                {
                    int num = va_arg(args, int);
                    count += handle_integer(num);
                }
                else if (length_modifier == 1)
                {
                    short num = va_arg(args, int);
                    count += handle_integer(num);
                }
                else if (length_modifier == 2)
                {
                    long num = va_arg(args, long);
                    count += handle_long_integer(num);
                }
            }
            else if (*format == 'u')
            {
                if (length_modifier == 0)
                {
                    unsigned int num = va_arg(args, unsigned int);
                    count += handle_unsigned(num);
                }
                else if (length_modifier == 1)
                {
                    unsigned short num = va_arg(args, unsigned int);
                    count += handle_unsigned(num);
                }
                else if (length_modifier == 2)
                {
                    unsigned long num = va_arg(args, unsigned long);
                    count += handle_unsigned_long(num);
                }
            }
            else if (*format == 'o' || *format == 'x' || *format == 'X')
            {
                if (length_modifier == 0)
                {
                    unsigned int num = va_arg(args, unsigned int);
                    count += handle_base(num, *format, 1);
                }
                else if (length_modifier == 1)
                {
                    unsigned short num = va_arg(args, unsigned int);
                    count += handle_base(num, *format, 1);
                }
                else if (length_modifier == 2)
                {
                    unsigned long num = va_arg(args, unsigned long);
                    count += handle_base(num, *format, 1);
                }
                else if (length_modifier == -1)
                {
                    unsigned char num = va_arg(args, unsigned int);
                    count += handle_base(num, *format, 1);
                }
                else if (length_modifier == -2)
                {
                    unsigned char num = va_arg(args, unsigned int);
                    count += handle_base(num, *format, 1);
                }
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
 * handle_integer - Helper function to print integers.
 * @num: The integer to print.
 * Return: The number of characters printed.
 */
int handle_integer(long num)
{
    int count = 0;
    char digit;
    if (num < 0)
    {
        write(1, "-", 1);
        count++;
        num = -num;
    }
    if (num / 10)
    {
        count += handle_integer(num / 10);
    }
    digit = num % 10 + '0';
    write(1, &digit, 1);
    count++;
    return count;
}

/**
 * handle_long_integer - Helper function to print long integers.
 * @num: The long integer to print.
 * Return: The number of characters printed.
 */
int handle_long_integer(long num)
{
    int count = 0;
    char digit;
    if (num < 0)
    {
        write(1, "-", 1);
        count++;
        num = -num;
    }
    if (num / 10)
    {
        count += handle_long_integer(num / 10);
    }
    digit = num % 10 + '0';
    write(1, &digit, 1);
    count++;
    return count;
}

/**
 * handle_unsigned - Helper function to print unsigned integers.
 * @num: The unsigned integer to print.
 * Return: The number of characters printed.
 */
int handle_unsigned(unsigned long num)
{
    int count = 0;
    if (num / 10)
    {
        count += handle_unsigned(num / 10);
    }
    char digit;
    digit = num % 10 + '0';
    write(1, &digit, 1);
    count++;
    return count;
}

/**
 * handle_unsigned_long - Helper function to print long unsigned integers.
 * @num: The long unsigned integer to print.
 * Return: The number of characters printed.
 */
int handle_unsigned_long(unsigned long num)
{
    int count = 0;
    if (num / 10)
    {
        count += handle_unsigned_long(num / 10);
    }
    char digit;
    digit = num % 10 + '0';
    write(1, &digit, 1);
    count++;
    return count;
}

/**
 * handle_base - Helper function to print integers in different bases.
 * @num: The unsigned integer to print.
 * @base: The base (8, 10, or 16).
 * @uppercase: Whether to print in uppercase or lowercase.
 * Return: The number of characters printed.
 */
int handle_base(unsigned long num, char base, int uppercase)
{
    int count = 0;
    const char *digits = (uppercase) ? "0123456789ABCDEF" : "0123456789abcdef";

    if (num / base)
    {
        count += handle_base(num / base, base, uppercase);
    }
    
    char digit = digits[num % base];
    write(1, &digit, 1);
    count++;
    
    return count;
}

/**
 * handle_pointer - Helper function to print pointers.
 * @ptr: The pointer to print.
 * Return: The number of characters printed.
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
        count += handle_base((unsigned long)ptr, 16, 1);
    }
    return count;
}

/**
 * handle_string_custom - Helper function to print custom string format.
 * @str: The custom string to print.
 * Return: The number of characters printed.
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
        count += handle_base((unsigned long)str, 16, 1);
    }
    return count;
}

/**
 * handle_reverse - Reverses and prints a string.
 * @str: The string to reverse and print.
 * Return: The number of characters printed.
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
 * handle_rot13 - Applies ROT13 encoding to a string and prints it.
 * @str: The string to apply ROT13 to and print.
 * Return: The number of characters printed.
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
