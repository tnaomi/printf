#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

/**
*struct printf_args - for format specifiers
* @spec: individual specifier
* @f: function pointer
*/
typedef struct printf_args
{
	char *spec;
	int (*f)();
} p_args;

int _printf(const char *format, ...);

/*COMPONENT FXNS*/
int printf_str(va_list str);
int printf_char(va_list c);
int printf_own(void);

/*MISC FXNS*/
int _strlen(char *str);
int _putchar(char c);

#endif /* MAIN_H */
