#include "main.h"

/**
 * _putchar - print single character
 * @c: character
 * Return: character
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}
