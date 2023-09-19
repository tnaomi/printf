#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>


int _printf(const char *format, ...);
int binary(int num);
int octal(int num);

/*HELPER FUNCTIONS*/
int _strlen(char *str);
int _putchar(char c, unsigned int size);
int print_string(char *str);

#endif /* MAIN_H */
