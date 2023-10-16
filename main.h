#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int handle_integer(long num);
int handle_long_integer(long num);
int handle_unsigned(unsigned long num);
int handle_unsigned_long(unsigned long num);
int handle_base(unsigned long num, char base, int uppercase);
int handle_pointer(void *ptr);
int handle_string_custom(char *str);
int handle_reverse(char *str);
int handle_rot13(char *str);

#endif /* MAIN_H */
