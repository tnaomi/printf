#include "main.h"

/**
 * get_width - Function calculates the width
 * @format: Formatted string.
 * @i: Argument list.
 * @list: Argument list.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curry;
	int width = 0;

	for (curry = *i + 1; format[curry] != '\0'; curry++)
	{
		if (is_digit(format[curry]))
		{
			width *= 10;
			width += format[curry] - '0';
		}
		else if (format[curry] == '*')
		{
			curry++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curry - 1;

	return (width);
}
