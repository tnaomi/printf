#include "main.h"
/**
 * _parameters - function resetting the buffer
 * @parameters: the structure of the parameters
 * @n: pointer to the argument
 * Return: void
 */
void _parameters(parameter *parameters, va_list arg_list)
{
        params->flag_plus = 0;
        params->flag_minus = 0;
        params->flag_zero = 0;
        params->flag_hashtag = 0;
        params->flag_space = 0;

        (void)arg_list;
}
