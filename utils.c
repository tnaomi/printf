#include "main.h"

/**
 * is_printable - Function evaluates if a character is printable
 * @c: Character under evaluation.
 *
 * Return: 1 if character is printable else 0
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Function appends ascii in hexadecimal code to buffer.
 * @buff: character array.
 * @n: start append index.
 * @ascii_code: ASCII CODE.
 * Return: return value - 3
 */
int append_hexa_code(char ascii_code, char buff[], int n)
{
	char map[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buff[n++] = '\\';
	buff[n++] = 'x';

	buff[n++] = map[ascii_code / 16];
	buff[n] = map[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Function verifies if a character is a digit
 * @c: Character to evaluated
 *
 * Return: 1 if character is digit else 0.
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Function casting a number to specified size
 * @num: Number to be casted.
 * @size: cast type.
 *
 * Return: num
 */
long int convert_size_number(long int num, int size)
{
	if (size == STR_LONG)
		return (num);
	else if (size == STR_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Function casting a number to specified size
 * @num: Number to be casted.
 * @size: cast type.
 *
 * Return: num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == STR_LONG)
		return (num);
	else if (size == STR_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
