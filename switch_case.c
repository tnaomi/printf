#include "main.h"

/**
 * select_f- Switch case for format specifiers
 * @format: Format specifier or not
 * @arg_list: argument list generated
 * @len: length on string so far
 * Return: len
*/

int select_f(const char *format, va_list arg_list, unsigned int len)
{
	char ch;

	switch (*format)
	{
		case '%':
			_putchar(37, 1);
			len++;
			break;
		case 'c':
			ch = va_arg(arg_list, int);
			_putchar(ch, 1);
			len++;
			break;
		case 's':
			len = print_string(arg_list, len);
			break;
		case 'd':
		case 'i':
			len = print_integer(arg_list, len);
			break;
	}
	return (len);
}
