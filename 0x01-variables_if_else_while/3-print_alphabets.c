#include <stdio.h>
/**
 * main - print alphabet in both lower and upper case
 *
 * Return: 0
 */
int main(void)
{
	char ch;

	for (ch = 'a'; ch <= 'z'; ch++)
		pustchar(ch);
	for (ch = 'A'; ch <= 'Z'; ch++)
                putchar(ch);
	putchar('\n');
	return (0);
}

