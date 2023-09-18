#include "main.h"
/**
 * _printf - printf function
 * @format : format string
 * Return : return output char
 */

int _printf(const char *format, ...)
{
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
				char ch = va_arg(arg_list, int);

				write(1, &ch, 1);
				output_char++;
			}
			else if (*format == 's') /* string handling*/
			{
				char *str = va_arg(arg_list, char*);

				/*while (str[string_length] != '\0') * string length calculation *
				{
					string_length++; * increament the string length*
				}*/
				write(1, str, strlen(str)); /* writing the string to STDOUT*/
				output_char += string_length;
			}
		}
		format++;
	}
	va_end(arg_list);
	return (output_char);
}
