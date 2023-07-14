#include <stdio.h>
/**
 * main - print alphabet in reverse order
 *
 * Return: 0
 */
int main(void)
{
	char ch = 'z';

	while (ch >= 'a')
	{
		putchar(ch);
		ch--;
	}
	putchar('\n');
	return (0);
}

