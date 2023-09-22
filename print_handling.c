#include "main.h"
/**
 * print_handling - Function prints a type based argument.
 * @fmt: Formatted string.
 * @list: Argument list to print.
 * @ind: integer argument.
 * @buff: print Buffer array.
 * @flag: active flags calculations
 * @width: get width.
 * @prec: specifies precision
 * @size: specifies size
 * Return: 1 or 2
 */
int print_handling(const char *fmt, int *ind, va_list list, char buff[],
	int flag, int width, int prec, int size)
{
	int i, length = 0, printed_characters = -1;
	fmt_t fmt_types[] = {
		{'c', char_print}, {'s', string_print}, {'%', percent_print},
		{'i', int_print}, {'d', int_print}, {'b', binary_print},
		{'u', unsigned_print}, {'o', octal_print}, {'x', hexadecimal_print},
		{'X', hexa_upper_print}, {'p', pointer_print}, {'S', non_printable_print},
		{'r', reverse_print}, {'R', rot13string_print}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buff, flag, width, prec, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		length += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			length += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		length += write(1, &fmt[*ind], 1);
		return (length);
	}
	return (printed_characters);
}
