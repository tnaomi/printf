#include "main.h"

/**
 * printf_str - print string
 * @str: input string
 * Return: 0
*/

int printf_str(va_list str)
{
	char *s;
	unsigned int indx = 0, len;

	s = va_arg(str, char *);

	if (s == NULL)
	{
		s = "(null)";
		len = _strlen(s);
		for (; indx < len; indx++)
			_putchar(s[indx]);
		return (len);
	}
	else
	{
		for (; indx < len; indx++)
			_putchar(s[indx]);
		return (len);
	}
}
