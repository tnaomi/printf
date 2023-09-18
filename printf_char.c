#include "main.h"

/**
 * printf_char - Prints a signle character
 * @c: character
 * Return: character
*/
int printf_char(va_list c)
{
	char d;

	d = va_arg(c, int);
	_putchar(d);
	return (1);
}
