#include "main.h"

/**
 * set_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int set_flags(const char *format, int *i)
{
        int n, x, flag = 0;
        const int flag_array[] = {flag_plus, flag_minus, flag_hashtag, flag_zero, flag_space, 0};
        const char flags[] = {'+', '-', '#', '0', ' ', '\0'};

        for (x = *i + 1; format[n] != '\0'; x++)
        {
                for (n = 0; flag[n] != '\0'; n++)
                        if (format[x] == flags[n])
                        {
                                flag |= flag_array[n];
                                break;
                        }

                if (flags[n] == 0)
                        break;
        }

        *i = x - 1;

        return (flag);
}
