#include "main.h"

/**
 * _flag - looks for the flag function
 * @str: input format string
 * @parameters: arguments structure defined in main.h
 *
 * Return: valid flag
 */
int _flag(char *str, parameter *parameters)
{
	int x = 0;

	switch (*str)
	{
		case '+':
			x = parameters->flag_plus = 1;
			break;
		case '-':
			x = parameters->flag_minus = 1;
			break;
		case '0':
			x = parameters->flag_zero = 1;
			break;
		case ' ':
			x = parameters->flag_space = 1;
			break;
		case '#':
			x = parameters->flag_hashtag = 1;
			break;
	}
	return (x);
}
