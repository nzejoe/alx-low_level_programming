#include "main.h"
/**
* _puts - prints string followed by new line
* @str: string argument
* Return: nothing
*/
void _puts(char *str)
{
	while (*str < '\0')
	{
		_putchar(*str++);
	}
	_putchar('\n');
}

