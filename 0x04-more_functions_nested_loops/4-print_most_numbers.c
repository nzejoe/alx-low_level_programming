#include "main.h"

/**
 * print_numbers - checks for checks for a digit (0 through 9)
 * and print number if it is not 2 and 4.
 *
 * Return: Always 0.
 */
void print_most_numbers(void)
{
	int c;

	for (c = 48; c < 58; c++)
	{
		if (c != 2 && c != 4)
			_putchar(c);
	}
	_putchar('\n');
}

