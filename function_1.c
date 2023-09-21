#include "main.h"

/* PRINTING AN UNSIGNED NUMBER */
/**
 * unsigned_print - Function prints an unsigned number
 * @type: argument list
 * @buff: An array handling printing
 * @flag: variable calculating flags that are active
 * @width: Width
 * @prec: specifies precision
 * @size: specifies size
 * Return: size of characters to print
 */
int unsigned_print(va_list type, char buff[],
	int flag, int width, int prec, int size);
{
	int x = BUFF_SIZE - 2;
	unsigned long int n = va_arg(type, unsigned long int);

	n = convert_size_unsgnd(n, size);

	if (n == 0)
		buff[x--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (n > 0)
	{
		buff[x--] = (n % 10) + '0';
		n /= 10;
	}

	x++;

	return (write_unsgnd(0, x, buff, flag, width, prec, size));
}

/* PRINTING AN UNSIGNED NUMBER IN OCTAL */
/**
 * octal_print - Function prints an unsigned number in octal 
 * @type: argument list
 * @buff: An array handling printing
 * @flag: variable calculating flags that are active
 * @width: Width
 * @prec: specifies precision
 * @size: specifies size
 * Return: size of characters to print
 */
int octal_print(va_list type, char buff[],
	int flag, int width, int precision, int size)
{

	int x = BUFF_SIZE - 2;
	unsigned long int n = va_arg(type, unsigned long int);
	unsigned long int init_number = n;

	UNUSED(width);

	n = convert_size_unsgnd(n, size);

	if (n == 0)
		buff[x--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (n > 0)
	{
		buff[x--] = (n % 8) + '0';
		n /= 8;
	}

	if (flags & F_HASH && init_number != 0)
		buff[x--] = '0';

	i++;

	return (write_unsgnd(0, x, buff, flag, width, prec, size));
}

/* PRINTING AN UNSIGNED NUMBER IN HEXADECIMAL */
/**
 * hexadecimal_print - Function prints an unsigned number in hexadecimal
 * @type: argument list
 * @buff: An array handling printing
 * @flag: variable calculating flags that are active
 * @width: Width
 * @prec: specifies precision
 * @size: specifies size
 * Return: size of characters to print
 */
int hexadecimal_print(va_list type, char buff[],
	int flag, int width, int prec, int size)
{
	return (hexa_print(type, "0123456789abcdef", buff,
		flag, 'x', width, prec, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * hexa_upper_print - Function prints in upper hexadecimal
 * @type: argument list
 * @buff: An array handling printing
 * @flag: variable calculating flags that are active
 * @width: Width
 * @prec: specifies precision
 * @size: specifies size
 * Return: size of characters to print
 */
int hexa_upper_print(va_list type, char buff[],
	int flag, int width, int prec, int size)
{
	return (hexa_print(type, "0123456789ABCDEF", buff,
		flag, 'X', width, prec, size));
}

/* PRINTING HEXADECIMAL NUMBER IN LOWERCASE OR UPPERCASE */
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @type: arguments List
 * @map_to: value array mapping the number to
 * @buff: Buffer array handling print
 * @flag:  Calculates active flags
 * @flag_char: active flags calculator
 * @width: width
 * @prec: specifies precision
 * @size: specifies size
 * Return: size of characters to print
 */
int print_hexa(va_list type, char map_to[], char buff[],
	int flag, char flag_char, int width, int prec, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int n = va_arg(type, unsigned long int);
	unsigned long int init_number = n;

	UNUSED(width);

	n = convert_size_unsgnd(n, size);

	if (n == 0)
		buff[x--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (n > 0)
	{
		buff[x--] = map_to[n % 16];
		n /= 16;
	}

	if (flag & F_HASH && init_number != 0)
	{
		buff[x--] = flag_char;
		buff[x--] = '0';
	}

	x++;

	return (write_unsgnd(0, x, buff, flag, width, prec, size));
}
