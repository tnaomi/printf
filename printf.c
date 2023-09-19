#include "../main.h"

/**
 * _printf - printf function
 * @format : format string
 * Description: _printf takes several arguments starting with a format string
 * it's a variadic function and can therefore take any list size
 * Code has the following specifiers:
 *  c - character
 *  s - array of characters
 *  d - integers
 *  p - pointer
 *  x -hexadecimal
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
	while (*format) 
	{
		if (*format == '%')
		{
			format++; /*skips the % character*/
			if (*format == '\0')
				break;
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

