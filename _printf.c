#include "main.h"

int _printf(const char *format, ...)
{
	char ch;
	int output_char = 0, string_length = 0; /*tracks the number of characters to be printed*/
	va_list arg_list

	if (format == NULL) /*Terminate the program if the format string is empty*/
		return (-1);
	va_start(arg_list, format); /* the last value of va_start should be the first argument of this function*/

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
			{
				write(1, format, 1);
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
				char *str = va_arg(arg_list, char*);

				while (str[string_length] != '\0') /* string length calculation*/
				{
					string_length++; /*increament the length of the string*/
				}
				write(1, str, string_length); /* writing the string to the standard library*/
				output_char += string_length;
			}
		}
		format++;
	}
	va_end(arg_list);
	return output_char;
}
