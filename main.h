#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>


int _printf(const char *format, ...);
int select_f(const char *format, va_list arg_list, unsigned int len);/*switch case fxn*/
int binary(unsigned int num, unsigned int len);
int octal(int num);

/*HELPER FUNCTIONS*/
int _strlen(char *str);
int _putchar(char c, unsigned int size);
int print_string(va_list arg_list, unsigned int len);
int print_integer(va_list arg_list, unsigned int len);

#endif /* MAIN_H */
