#include "main.h"

/**
 * binary - convert integer to binary
 * @num: Input number
 * @len: length of number 'string'
 * Return: len
*/
int binary(unsigned int num, unsigned int len)
{
	int indx = 0, binary_num[32] = {0};/*Initialised with binary 0*/

	if (num == 0)/*For a zero number*/
	{
		_putchar('0', 1);
		len++;
		return (len);
	}
	for (indx = 0; num > 0; indx++, num /= 2)
		binary_num[indx] = num % 2;	

	for (; indx > 0; indx--, len++)
		_putchar('0' + binary_num[indx], 1);
	
	return (len);
}
