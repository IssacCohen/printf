#include <stdio.h>  /* Include standard I/O for comparison */
#include <limits.h> /* Include limits.h for INT_MAX definition */
#include "main.h"

int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    /* Test format specifiers */
    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;

    /* Test various format specifiers */
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);

    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);

    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);

    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);

    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);

    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');

    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");

    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);

    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");

    /* Custom format specifier 'r' */
    _printf("Unknown:[%r]\n");

    return (0);
}
