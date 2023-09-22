#include "main.h"

/* HANDLE WRITE */
/**
 * handle_write_char - Prints a string
 * @c: chararacter types.
 * @buff: Print handling Buffer array.
 * @flag: active flags calculator.
 * @width: get width.
 * @prec: specifies precision.
 * @size: specifies size.
 *
 * Return: characters printed total.
 */
int handle_write_char(char c, char buff[],
		int flag, int width, int prec, int size)
{
	int n = 0;
	char space = ' ';

	UNUSED(prec);
	UNUSED(size);

	if (flag & FLAG_ZERO)
		space = '0';

	buff[n++] = c;
	buff[n] = '\0';

	if (width > 1)
	{
		buff[BUFF_SIZE - 1] = '\0';
		for (n = 0; n < width - 1; n++)
			buff[BUFF_SIZE - n - 2] = space;

		if (flag & FLAG_MINUS)
			return (write(1, &buff[0], 1) +
					write(1, &buff[BUFF_SIZE - n - 1], width - 1));
		else
			return (write(1, &buff[BUFF_SIZE - n - 1], width - 1) +
					write(1, &buff[0], 1));
	}

	return (write(1, &buff[0], 1));
}

/* WRITING A NUMBER */
/**
 * write_number - Function prints a string
 * @is_negative: arguments list.
 * @ind: character types.
 * @buff: Print handling Buffer array.
 * @flag: active flags calculator.
 * @width: get width.
 * @prec: specifies precision.
 * @size: specifies size.
 *
 * Return: characters printed total.
 */
int write_number(int is_negative, int ind, char buff[],
	int flag, int width, int prec, int size)
{
	int len = BUFF_SIZE - ind - 1;
	char space = ' ', extra_character = 0;

	UNUSED(size);

	if ((flag & FLAG_ZERO) && !(flag & FLAG_MINUS))
		space = '0';
	if (is_negative)
		extra_character = '-';
	else if (flag & FLAG_PLUS)
		extra_character = '+';
	else if (flag & FLAG_SPACE)
		extra_character = ' ';

	return (write_num(ind, buff, flag, width, prec,
		len, space, extra_character));
}

/**
 * write_num - Function writes a number using a bufffer
 * @ind: start number index on the buffer
 * @buff: input buffer.
 * @flags: Flags.
 * @width: width.
 * @prec: Specify precision.
 * @len: Digit length.
 * @padd: character padding.
 * @extra_c: Extra character input.
 *
 * Return: Number of printed chars.
 */
int write_num(int ind, char buff[],
	int flags, int width, int prec,
	int len, char padd, char extra_c)
{
	int n, padding_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0')
		buff[ind] = padd = ' ';
	if (prec > 0 && prec < len)
		padd = ' ';
	while (prec > len)
		buff[--ind] = '0', len++;
	if (extra_c != 0)
		len++;
	if (width > len)
	{
		for (n = 1; n < width - len + 1; n++)
			buff[n] = padd;
		buff[n] = '\0';
		if (flags & FLAG_MINUS && padd == ' ')
		{
			if (extra_c)
				buff[--ind] = extra_c;
			return (write(1, &buff[ind], len) + write(1, &buff[1], n - 1));
		}
		else if (!(flags & FLAG_MINUS) && padd == ' ')
		{
			if (extra_c)
				buff[--ind] = extra_c;
			return (write(1, &buff[1], n - 1) + write(1, &buff[ind], len));
		}
		else if (!(flags & FLAG_MINUS) && padd == '0')
		{
			if (extra_c)
				buff[--padding_start] = extra_c;
			return (write(1, &buff[padd_start], n - padding_start) +
				write(1, &buff[ind], len - (1 - padding_start)));
		}
	}
	if (extra_c)
		buff[--ind] = extra_c;
	return (write(1, &buff[ind], len));
}

/**
 * write_unsgnd - Functin writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Start number index in buffer
 * @buff: Print handling Buffer array.
 * @flag: active flags calculator.
 * @width: get width.
 * @prec: specifies precision.
 * @size: specifies size.
 *
 * Return: Number of written chars.
 */
int write_unsgnd(int is_negative, int ind,
	char buff[],
	int flag, int width, int prec, int size)
{
	int len = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (prec == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0')
		return (0);

	if (prec > 0 && prec < len)
		padd = ' ';

	while (prec > len)
	{
		buff[--ind] = '0';
		len++;
	}

	if ((flag & FLAG_ZERO) && !(flag & FLAG_MINUS))
		padd = '0';

	if (width > len)
	{
		for (i = 0; i < width - len; i++)
			buff[i] = padd;

		buff[i] = '\0';

		if (flags & FLAG_MINUS)
		{
			return (write(1, &buff[ind], len) + write(1, &buff[0], i));
		}
		else
		{
			return (write(1, &buff[0], i) + write(1, &buff[ind], len));
		}
	}

	return (write(1, &buff[ind], len));
}

/**
 * write_pointer - Write a memory address
 * @ind: Start number index in buffer
 * @buff: Print handling Buffer array.
 * @len : length
 * @flag: active flags calculator.
 * @width: get width.
 * @padd: padding character.
 * @extra_c: Represents extra characters.
 * @padd_start: padding index start-point.
 *
 * Return: character total.
 */
int write_pointer(char buff[], int ind, int len,
	int width, int flag, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > len)
	{
		for (i = 3; i < width - len + 3; i++)
			buff[i] = padd;
		buff[i] = '\0';
		if (flag & FLAG_MINUS && padd == ' ')
		{
			buff[--ind] = 'x';
			buff[--ind] = '0';
			if (extra_c)
				buff[--ind] = extra_c;
			return (write(1, &buff[ind], len) + write(1, &buff[3], i - 3));
		}
		else if (!(flag & FLAG_MINUS) && padd == ' ')
		{
			buff[--ind] = 'x';
			buff[--ind] = '0';
			if (extra_c)
				buff[--ind] = extra_c;
			return (write(1, &buff[3], i - 3) + write(1, &buff[ind], len));
		}
		else if (!(flags & FLAG_MINUS) && padd == '0')
		{
			if (extra_c)
				buff[--padd_start] = extra_c;
			buff[1] = '0';
			buff[2] = 'x';
			return (write(1, &buff[padd_start], i - padd_start) +
				write(1, &buff[ind], len - (1 - padd_start) - 2));
		}
	}
	buff[--ind] = 'x';
	buff[--ind] = '0';
	if (extra_c)
		buff[--ind] = extra_c;
	return (write(1, &buff[ind], BUFF_SIZE - ind - 1));
}
