#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define TOTAL_HEX 16

/* FLAGS */
/* FLAGS */
#define flag_plus 2
#define flag_minus 1
#define flag_hashtag 8
#define flag_zero 4
#define flag_space 16

/**
 * struct arguments - a defined structure of arguments
 *
 * @flag_plus: set when flag_plus is selected
 * @flag_minus: set when flag_minus is selected
 * @flag_zero: set when flag_zero is selected
 * @flag_hashtag: set when flag_hashtag is selected
 * @flag_space: set when flag_space is selected
 */
typedef struct arguments
{
        unsigned int flag_plus  : 1;
        unsigned int flag_minus : 1;
        unsigned int flag_zero  : 1;
        unsigned int flag_hashtag: 1;
        unsigned int flag_space : 1;
} parameter;

/* struct arguments - a defined structure of arguments
 *
 * @flag_plus: set when flag_plus is selected
 * @flag_minus: set when flag_minus is selected
 * @flag_zero: set when flag_zero is selected
 * @flag_hashtag: set when flag_hashtag is selected
 * @flag_space: set when flag_space is selected
 */
typedef struct arguments
{
        unsigned int flag_plus  : 1;
        unsigned int flag_minus : 1;
        unsigned int flag_zero  : 1;
        unsigned int flag_hashtag: 1;
        unsigned int flag_space : 1;
} parameter;

int _printf(const char *format, ...);
int select_f(const char *format, va_list arg_list, unsigned int len);
int binary(unsigned int num, unsigned int len);
int address(va_list arg_list, unsigned int len);
int octal(int num);

/*HELPER FUNCTIONS*/
int _strlen(char *str);
int _putchar(char c, unsigned int size);
int print_string(va_list arg_list, unsigned int len);
int print_integer(va_list arg_list, unsigned int len);

/* FLAG FUNCTIONS */
int set_flags(const char *format, int *i);
int _flag(char *str, parameter *parameters);
void _parameters(parameter *parameters, va_list n);

#endif /* MAIN_H */
