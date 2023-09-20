#include "main.h"

/* PRINT CHARACTER */

/**
 * char_print - Function printing a character
 * @type: argument list
 * @buffer: An array handling printing
 * @flags: variable calculating flags that are active
 * @width: Width
 * @precision: specifies precision
 * @size: specifies size
 * Return: size of characters to print
 */
int char_print(va_list type, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(type, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/* PRINT A STRING */
/**
 * string_print - Function printing a string
 * @type: argument list
 * @buffer: An array handling printing
 * @flags:  variable calculating flags that are active
 * @width: variable to get width.
 * @precision: specifies precision
 * @size: specifies size
 * Return: size of characters to print
 */
int string_print(va_list type, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, len = 0;
	char *str = va_arg(type, char *);

	UNUSED(buffer);
	UNUSED(width);
	UNUSED(flags);
	UNUSED(size);
	UNUSED(precision);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}

	return (write(1, str, len));
}
/* PRINTING A PERCENT SIGN */
/**
 * percent_print - Function printing a string
 * @type: argument list
 * @buffer: An array handling printing
 * @flags:  variable calculating flags that are active
 * @width: variable to get width.
 * @precision: specifies precision
 * @size: specifies size
 * Return: size of characters to print
 */
int percent_print(va_list type, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(type);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/* PRINTING AN INTEGER */
/**
 * int_print - Prints an int
 * @type: argument list
 * @buffer: An array handling printing
 * @flags:  variable calculating flags that are active
 * @width: variable to get width.
 * @precision: specifies precision
 * @size: specifies size
 * Return: size of characters to print
 */
int int_print(va_list type, char buffer[],
	int flags, int width, int precision, int size)
{
	int n = BUFF_SIZE - 2;
	int is_negative = 0;
	long int x = va_arg(type, long int);
	unsigned long int number;

	x = convert_size_number(x, size);

	if (x == 0)
		buffer[n--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	number = (unsigned long int)x;

	if (x < 0)
	{
		number = (unsigned long int)((-1) * x);
		is_negative = 1;
	}

	while (number > 0)
	{
		buffer[n--] = (number % 10) + '0';
		number /= 10;
	}

	n++;

	return (write_number(is_negative, n, buffer, flags, width, precision, size));
}

/* PRINTING A BINARY */
/**
 * binary_print - Function Printing an unsigned number
 * @type: argument list
 * @buffer: An array handling printing
 * @flags:  variable calculating flags that are active
 * @width: variable to get width.
 * @precision: specifies precision
 * @size: specifies size
 * Return: size of characters to print
 */
int binary_print(va_list type, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int i, j, k, sum;
	unsigned int arr[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	j = va_arg(type, unsigned int);
	k = 2147483648; /* (2 ^ 31) */
	arr[0] = j / k;
	for (i = 1; i < 32; i++)
	{
		k /= 2;
		arr[i] = (j / k) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += arr[i];
		if (sum || i == 31)
		{
			char c = '0' + arr[i];

			write(1, &c, 1);
			count++;
		}
	}
	return (count);
}
