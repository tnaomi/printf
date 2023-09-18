#include "main.h"

/**
 * _strlen - prints length of a string
 * @str: input string
 * Return: length
*/
int _strlen(char *str)
{
	unsigned len = 0, indx = 0;
	if (*str)
	{
		for (; str[indx] != '\0';indx++)
			len++;
	}
	return (len);
}
