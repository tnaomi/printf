#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

/* SIZES */
#define STR_LONG 2
#define STR_SHORT 1

/* DEFINING A STRUCTURE */
/**
 * struct fmt - Struct type format
 *
 * @fmt: format type.
 * @fn: Associated function.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Structure type
 *
 * @fmt: format type.
 * @fm_t: Associated function.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...); /* printf function */
int print_handling(const char *fmt, int *ind, va_list list, char buff[],
	int flag, int width, int prec, int size);

/* FUNCTIONS */

/* Funtions that print characters and strings */
int percent_print(va_list type, char buffer[],
	int flags, int width, int precision, int size);
int string_print(va_list type, char buffer[],
	int flags, int width, int precision, int size);
int char_print(va_list type, char buff[],
                int flag, int width, int prec, int size);

/* Function printing numbers */

int binary_print(va_list type, char buffer[],
	int flags, int width, int prec, int size);
int hexadecimal_print(va_list type, char buff[],
	int flag, int width, int prec, int size);
int octal_print(va_list type, char buff[],
	int flag, int width, int prec, int size);
int unsigned_print(va_list type, char buff[],
	int flag, int width, int prec, int size);
int hexa_upper_print(va_list type, char buff[],
	int flag, int width, int prec, int size);
int int_print(va_list type, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list type, char map_to[], char buff[],
	int flag, char flag_char, int width, int prec, int size);

/* Function to print non printable characters */
int non_printable_print(va_list type, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int pointer_print(va_list type, char buff[],
	int flag, int width, int prec, int size);

/* Functions handling other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/*Function to print string in reverse*/
int reverse_print(va_list type, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int rot13string_print(va_list type, char buff[],
	int flag, int width, int prec, int size);

/* width handler */
int handle_write_char(char c, char buff[],
	int flag, int width, int prec, int size);
int write_number(int is_negative, int ind, char buff[],
	int flag, int width, int prec, int size);
int write_num(int ind, char buff[], int flags, int width, int prec,
	int len, char padd, char extra_c);
int write_pointer(char buff[], int ind, int len,
	int width, int flag, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buff[],
	int flag, int width, int prec, int size);

/* UTILITIES */
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
