#include "main.h"
/**
* swap_int - swap values of two int variables
* @a: this variable
* @b: second variable
* Return: nothing
*/
void swap_int(int *a, int *b)
{
	int m;

	m = *a;

	*a = *b;
	*b = m;
}

