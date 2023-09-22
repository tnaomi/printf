#include "main.h"

/**
 * get_flags - Function calculating active flags
 * @format: string format
 * @i: input parameter.
 * Return: Flags
 * Description: - + 0 # ' '
 * '1 2 4 8  16'
 */
int get_flags(const char *format, int *i)
{
	int n, curry;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curry = *i + 1; format[curry] != '\0'; curry++)
	{
		for (n = 0; FLAGS_CH[n] != '\0'; n++)
			if (format[curry] == FLAGS_CH[n])
			{
				flags |= FLAGS_ARR[n];
				break;
			}

		if (FLAGS_CH[n] == 0)
			break;
	}

	*i = curry - 1;

	return (flags);
}
