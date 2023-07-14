#include <stdio.h>
/**
 * main - print base 10 numbers from 0
 *
 * Return: 0
 */
int main(void)
{
	int n = 0;

	while (n < 10)
	{
		putchar(n);
		n++;
	}
	putchar('\n');
	return (0);
}

