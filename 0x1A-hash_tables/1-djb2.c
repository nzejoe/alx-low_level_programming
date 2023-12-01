#include "hash_tables.h"

/**
 * hash_djb2 - implement djb2 algorithm (one of best string hash functions)
 * source code copied from:
 * https://gist.github.com/papamuziko/7bb52dfbb859fdffc4bd0f95b76f71e8
 * Credit: Dan Bernstein
 * @str: value
 * Return: The new hash value.
 */

unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long hash = 5381;
	int c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return (hash);
}
