#include "main.h"

void print_buff(char buffer[], int *buff);

/**
 * _printf - custom Printf function
 * @format: input format string.
 * Return: characters.
 */
int _printf(const char *format, ...)
{
	int i, print_chars = 0, print = 0;
	int flags, width, precision, size, buff = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff++] = format[i];
			if (buff == BUFF_SIZE)
				print_buffer(buffer, &buff);
			/* write(1, &format[i], 1);*/
			print_chars++;
		}
		else
		{
			print_buff(buffer, &buff);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (print == -1)
				return (-1);
			print_chars += print;
		}
	}

	print_buff(buffer, &buff);

	va_end(list);

	return (print_chars);
}

/**
 * print_buffer - function prints buffer content if it exists
 * @buffer: character array.
 * @buff: length.
 */
void print_buff(char buffer[], int *buff)
{
	if (*buff > 0)
		write(1, &buffer[0], *buff);

	*buff = 0;
}
