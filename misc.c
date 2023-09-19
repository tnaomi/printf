#include "main.h"

/**
 * _strlen - prints length of a string
 * @str: input string
 * Return: length
*/
int _strlen(char *str)
{
	unsigned int len = 0, indx = 0;

	if (*str)
	{
		for (; str[indx] != '\0'; indx++)
			len++;
	}
	return (len);
}

/**
 * _putchar - print single character
 * @c: character
 * @size: buffer size or length
 * Return: character
*/

int _putchar(char c, unsigned int size)
{
	return (write(1, &c, size));
}

/**
 * print_string - print a string
 * @str: Input string
 * Return: integer
*/
int print_string(va_list arg_list, unsigned int len)
{
	char *str = va_arg(arg_list, char *);

	if (str == NULL)
		str = "(NULL)";
	len = _strlen(str);
	while (*str != '\0')
	{
		_putchar(*str, 1);
		len++;
		str++;
	}
	return (len);
}
