#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * struct flags - struct for flags
 * @plus:  for the '+' character
 * @space:  for the ' ' character
 * @hash:  for the '#' character
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

/**
 * struct printHandler - struct to choose the right function depending
 * on the format specifier passed to _printf()
 * @spec: format specifier
 * @func: pointer to the correct printing function
 */
typedef struct printHandler
{
	char *spec;
	int (*func)(va_list, flags_t *f);
} specify_t;



/** 
 * _printf - Custom printf function
 * @format: The format string
 * @...: Variable number of arguments
 * Return: Number of characters printed
 */
int _printf(const char *format, ...);

/**
 * handleInt - Handle integer conversion specifier
 * @form: Argument list
 * @f: Flags
 * Return: Number of characters printed
 */
int handleInt(va_list form, flags_t *f);

/**
 * _putchar - Custom putchar function
 * @c: Character to print
 * Return: Number of characters printed
 */
int _putchar(char c);

/**
 * print_string - Print a string
 * @form: Argument list
 * @f: Flags
 * Return: Number of characters printed
 */
int print_string(va_list form, flags_t *f);

/**
 * print_binary - Print a binary number
 * @form: Argument list
 * @f: Flags
 * Return: Number of characters printed
 */
int print_binary(va_list form, flags_t *f);

/**
 * print_unsigned - Print an unsigned integer
 * @form: Argument list
 * @f: Flags
 * Return: Number of characters printed
 */
int print_unsigned(va_list form, flags_t *f);

/**
 * print_octal - Print an octal number
 * @form: Argument list
 * @f: Flags
 * Return: Number of characters printed
 */
int print_octal(va_list form, flags_t *f);

/**
 * print_hex - Print a hexadecimal number (lowercase)
 * @form: Argument list
 * @f: Flags
 * Return: Number of characters printed
 */
int print_hex(va_list form, flags_t *f);

/**
 * handleP - Handle pointer conversion specifier
 * @form: Argument list
 * @f: Flags
 * Return: Number of characters printed
 */
int handleP(va_list form, flags_t *f);

/**
 * rot13 - Encode a string using the ROT13 algorithm
 * @form: Argument list
 * @f: Flags
 * Return: Number of characters printed
 */
int rot13(va_list form, flags_t *f);

/**
 * print_rev - Print a string in reverse
 * @form: Argument list
 * @f: Flags
 * Return: Number of characters printed
 */
int print_rev(va_list form, flags_t *f);

/**
 * print_bigS - Print a string with non-printable characters
 * @form: Argument list
 * @f: Flags
 * Return: Number of characters printed
 */
int print_bigS(va_list form, flags_t *f);

/**
 * convert - Convert a number to a given base
 * @num: The number to convert
 * @base: The base to convert to
 * @lowercase: 1 for lowercase, 0 for uppercase
 * Return: The converted number as a string
 */
char *convert(unsigned long int num, int base, int lowercase);

/**
 * _puts - Custom puts function
 * @str: String to print
 */
int _puts(char *str);

/**
 * print_hex1 - Print a hexadecimal number (uppercase)
 * @form: Argument list
 * @f: Flags
 * Return: Number of characters printed
 */
int print_hex1(va_list form, flags_t *f);

/**
 * print_cent - Print the percent character
 * @form: Argument list
 * @f: Flags
 * Return: Number of characters printed
 */
int print_cent(va_list form, flags_t *f);

/**
 * print_char - Print a character
 * @form: Argument list
 * @f: Flags
 * Return: Number of characters printed
 */
int print_char(va_list form, flags_t *f);

/**
 * get_flag - Get a flag based on the given specifier
 * @s: The specifier character
 * @f: Flags
 * Return: The corresponding flag value
 */
int get_flag(char s, flags_t *f);




#endif
