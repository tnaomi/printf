#include "../main.h"

/**
 * _prrrintf - printf function
 * @format : format string
 * Description: _printf takes several arguments starting with a format string
 * it's a variadic function and can therefore take any list size
 * Code has the following specifiers:
 *  c - character
 *  s - array of characters
 *  d - integers
 *  p - pointer
 *  x -hexadecimal
 * Return: returns number of output char
 * (null terminating character isn't considered)
 */

int _prrrintf(const char *format, ...)
{
	char *str, ch;
	int output_char = 0; /*string_length = 0; tracks characters length*/
	va_list arg_list;

	if (format == NULL) /*Terminate the program if the format string is empty*/
		return (-1);
	va_start(arg_list, format); /*format string is last function argument*/
	while (*format) /* iterates through all characters of our format string*/
	{
		if (*format != '%')
		{
			write(1, format, 1); /*only 1 byte is needed to print a char*/
			output_char++; /* increament by 1*/
		}
		else /* handles the case where there is % special character*/
		{
			format++; /*skips the % character*/
			if (*format == '\0')
				break;
			if (*format == '%') /* applies when %% is encountered*/
			{	write(1, format, 1);
				output_char++;
			}
			else if (*format == 'c') /* character handling*/
			{
				ch = va_arg(arg_list, int);
				write(1, &ch, 1);
				output_char++;
			}
			else if (*format == 's') /* string handling*/
			{
				str = va_arg(arg_list, char*);
				output_char = strlen(str);
				write(1, str, output_char); /* writing the string to STDOUT*/
			}
		}
		format++;
	}
	va_end(arg_list);
	return (output_char);
}
