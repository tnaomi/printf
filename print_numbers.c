#include "main.h"

/**
 * print_integer - print an integer
 * @arg_list: Input string
 * @len: length of number 'string'
 * Return: len
*/
int print_integer(va_list arg_list, unsigned int len)
{
	int num = va_arg(arg_list, int);
	int numbers = 0;
	int temp = num;
	int digit, pwr_10, indx;

	if (num < 0)/*For a negative number*/
	{
		len += _putchar('-', 1);
		num = -num;
		temp = num;
	}
	do
	{
		numbers++;
		temp /= 10;/*Prints the remainder*/
	} while (temp != 0);
	
	while (numbers > 0)
	{
		pwr_10 = 1;
		for (indx = 1; indx < numbers; indx++)
			pwr_10 *= 10;
		digit = num / pwr_10;
		len += _putchar(digit + '0', 1);
		num -= digit * pwr_10;
		numbers--;
	}
		
	return (len);
}
