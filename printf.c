#include "main.h"

int _strlen(char *str);
int _putchar(char c, unsigned int size);
int print_string(char *str);
/**
* _printf - printf function
* @format : format string
* Return: returns length
* (null terminating character isn't considered)
*/

int _printf(const char *format, ...)
{
	char *str, ch;
	int len = 0; /*string_length = 0; tracks characters length*/
	va_list arg_list;

	if (format == NULL) /*Terminate the program if the format string is empty*/
		return (-1);
	va_start(arg_list, format); /*format string is last function argument*/
	while (*format && *format != '\0')
	{
		_putchar(*format, 1);
		if (*format == '%')
		{
			format++; /*skips the % character*/
			if (*format == '%')
			{
				_putchar(37, 1);
				len++;
			}
			else if (*format == 'c')
			{
				ch = va_arg(arg_list, int);
				_putchar(ch, 1);
				len++;
			}
			else if (*format == 's')
			{
				str = va_arg(arg_list, char*);
				print_string(str);
			}
			format++;
		}
		_putchar(*(format), 1);
		++format;
	}

	va_end(arg_list);
	return (len);
}

