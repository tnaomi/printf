#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>


int printf(const char *format, ...);
int binary(int num)
int octal(int num)

/*COMPONENT FXNS*/
int printf_str(va_list str);
int printf_char(va_list c);
int printf_own(void);

/*MISC FXNS*/
int _strlen(char *str);
int _putchar(char c);

#endif /* MAIN_H */
