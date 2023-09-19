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

/**
 * _putchar - print single character
 * @c: character
 * @size: buffer size or length
 * Return: character
*/

int _putchar(char c, unsigned int size)
{
    return(write(1, &c, size));
}

/**
 * print_string - print a string
 * @str: Input string
 * Return - integer
*/
int print_string(char *str)
{
    unsigned int indx = 0, len;

    if (str == NULL)
        str = "(NULL)";
    len = _strlen(str);
    if (*str &&  len > 0)
    {
        for (; indx < len; indx++)
            _putchar(str[indx], 1);
    }
    return (len);
}
