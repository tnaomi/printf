#include "../main.h"
#include <stdio.h>

/**
*main - test function
*Return: 0
*/
int main(void)
{
	int len;


    len = _printf("Let's try to printf a simple sentence.\n");
    len = printf("Let's try to printf a simple sentence.\n");
    
    

    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    
    len = _printf("Percent:[%%]\n");
    len = printf("Percent:[%%]\n");
    
	return (len);
    
}
