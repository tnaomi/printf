#include "main.h"

/**
 * get_precision - Function calculates the printing precision
 * @format: Formatted string.
 * @i: argument list to print.
 * @list: argument list.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curry = *i + 1;
	int prec = -1;

	if (format[curry] != '.')
		return (prec);

	prec = 0;

	for (curr_i += 1; format[curry] != '\0'; curry++)
	{
		if (is_digit(format[curry]))
		{
			prec *= 10;
			prec += format[curry] - '0';
		}
		else if (format[curry] == '*')
		{
			curry++;
			prec = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curry - 1;

	return (prec);
}
