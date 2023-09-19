#include "../main.h"
#include <stdio.h>

/**
*main - test function
*Return: 0
*/
int main(void)
{
	int len, len2;
    /*unsigned int ui;*/

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2); 
    /*ui = (unsigned int)INT_MAX + 1024;*/
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    /*_printf("Unsigned:[%u]\n", ui);*/
    /*printf("Unsigned:[%u]\n", ui);*/
    len = _printf("Percent:[%%]\n");
    len = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Binary: %b\n", 9);
    printf("Binary: %b\n", 9);
	return (len);
    
}
