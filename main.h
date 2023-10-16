#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* _printf */
int _printf(const char *format, ...);

/* write functions */
int _putchar(char c);

/* Custom conversion specifiers */
int handle_string_custom(char *str);
int handle_reverse(char *str);
int handle_rot13(char *str);

/* Helper functions for other conversion specifiers */
int handle_integer(int num);
int handle_binary(unsigned int num);
int handle_unsigned(unsigned int num);
int handle_octal(unsigned int num);
int handle_hex(unsigned int num, int uppercase);
int handle_pointer(void *ptr);

#endif /* !MAIN_H */
