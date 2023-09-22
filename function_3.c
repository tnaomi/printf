#include "main.h"

/* PRINTING A POINTER */
/**
 * pointer_print - Prints the value of a pointer variable
 * @type: argument list
 * @buff: An array handling printing
 * @flag: variable calculating flags that are active
 * @width: Width
 * @prec: specifies precision
 * @size: specifies size
 * Return: size of characters to print
 */
int pointer_print(va_list type, char buff[],
	int flag, int width, int prec, int size)
{
	char extra_c = 0, padd = ' ';
	int i = BUFF_SIZE - 2, len = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(type, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buff[BUFF_SIZE - 1] = '\0';
	UNUSED(prec);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buff[i--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		len++;
	}

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		padd = '0';
	if (flag & F_PLUS)
		extra_c = '+', len++;
	else if (flag & F_SPACE)
		extra_c = ' ', len++;

	i++;

	return (write_pointer(buff, i, len,
		width, flag, padd, extra_c, padd_start));
}

/* PRINTING A NON PRINTABLE */
/**
 * non_printable_print - Prints ascii codes in hexa of non printable chars
 * @type: argument list
 * @buff: An array handling printing
 * @flag: variable calculating flags that are active
 * @width: Width
 * @prec: specifies precision
 * @size: specifies size
 * Return: size of characters to print
 */
int non_printable_print(va_list type, char buff[],
	int flag, int width, int prec, int size)
{
	int n = 0, offset = 0;
	char *str = va_arg(type, char *);

	UNUSED(flag);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[n] != '\0')
	{
		if (is_printable(str[n]))
			buff[n + offset] = str[n];
		else
			offset += append_hexa_code(str[n], buff, n + offset);

		n++;
	}

	buff[n + offset] = '\0';

	return (write(1, buff, n + offset));
}

/* PRINTING IN REVERSE */
/**
 * reverse_print - Printing a string in reverse.
 * @type: argument list
 * @buff: An array handling printing
 * @flag: variable calculating flags that are active
 * @width: Width
 * @prec: specifies precision
 * @size: specifies size
 * Return: size of characters to print
 */

int reverse_print(va_list type, char buff[],
	int flag, int width, int prec, int size)
{
	char *str;
	int x, count = 0;

	UNUSED(buff);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(type, char *);

	if (str == NULL)
	{
		UNUSED(prec);

		str = ")Null(";
	}
	for (x = 0; str[x]; x++)
		;

	for (i = x - 1; x >= 0; x--)
	{
		char z = str[x];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/* PRINTing A STRING IN ROT13 */
/**
 * rot13string_print - Print a string in rot13.
 * @type: argument list
 * @buff: An array handling printing
 * @flag: variable calculating flags that are active
 * @width: Width
 * @prec: specifies precision
 * @size: specifies size
 * Return: size of characters to print
 */
int rot13string_print(va_list type, char buff[],
	int flag, int width, int prec, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(type, char *);
	UNUSED(buff);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; input[j]; j++)
		{
			if (input[j] == str[i])
			{
				x = output[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!input[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
