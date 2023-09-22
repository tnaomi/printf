#include "main.h"

/**
 * address - print address with p specifier
 * @arg_list: Input string
 * @len: length of character string
 * Return: len
*/
int address(va_list arg_list, unsigned int len)
{
                void *ptr = va_arg(arg_list, void *);
                /*Assign unsigned long since hex number is large*/
                unsigned long random = (unsigned long) ptr;
                unsigned long temp = random;
                int digits = 0, indx, digit;
                char total_hex[TOTAL_HEX] = "0123456789abcdef";
                char hex[TOTAL_HEX];

                for (; temp != 0; digits++)
                        temp /= 16;

                len += _putchar('0', 1);
                len += _putchar('x', 1);

                if (random == 0)
                        len += _putchar('0', 1);

                else
                {
                        for (indx = digits - 1; indx >= 0; indx--)
                        {
                                digit = random % 16;
                                hex[indx] = total_hex[digit];
                                random /= 16;
                        }
                        for (indx = 0; indx < digits; indx++)
                                len += _putchar(hex[indx], 1);
                }
                return (len);

}
