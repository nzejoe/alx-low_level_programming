#include <stdio.h>
/**
 * main - prints sizes of data type allocation
 *
 * Return: 0 (Return nothing but zero (0)
*/
int main(void){
	char a;
	int b;
	long int c;
	long long int d;
	float e;
	printf("Size of a char: %lu byte(s\n)", (unasigned long)sizeof(a));
	printf("Size of a int: %lu byte(s)\n", (unasigned long)sizeof(b));
	printf("Size of a long int: %lu byte(s)\n", (unasigned long)sizeof(c));
	printf("Size of a long long int: %lu byte(s)\n", sizeof(d));
	printf("Size of a float: %lu byte(s)", (unasigned long)sizeof(f));
	return 0;
}
