#include "main.h"

/**
 * _printf - Prints according to format specifiers
 * @format: specifier (task 0: c, s, %)
 * Return: Success
*/

int _printf(const char *format, ...)
{
	p_args conds[] = {
		{"%s", printf_str},
		{"%c", printf_char},
		{"%%", printf_own}
	};

	unsigned int indx, len = 0, indx2;

	va_list specs;

	va_start(specs, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Block:
	for (indx = 0; format[indx] != '\0'; indx++)
	{
		indx2 = 3; /*No of conditions*/
		for (; indx2 > 0; indx2--)
		{
			if (conds[indx2].spec[0] == format[indx] &&
			conds[indx2].spec[1] == format[indx + 1])
			{
				len += conds[indx2].f(specs);
				indx += 2;
				goto Block;
			}
		}
		_putchar(format[indx]);
		len++;
	}
	va_end(specs);
	return (len);
}
