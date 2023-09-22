#include "main.h"

/**
 * get_size - Function calculates the argument size to cast.
 * @format: Formatted string.
 * @i: Argument list to print.
 *
 * Return: Size.
 */
int get_size(const char *format, int *i)
{
	int curry = *i + 1;
	int size = 0;

	if (format[curry] == 'l')
		size = STR_LONG;
	else if (format[curry] == 'h')
		size = STR_SHORT;

	if (size == 0)
		*i = curry - 1;
	else
		*i = curry;

	return (size);
}
