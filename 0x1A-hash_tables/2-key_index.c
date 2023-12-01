#include "hash_tables.h"

/**
 * key_index - gives the index of a key in hash table
 * @key: key to be given
 * @size: size of the hash table array
 * Return:  the index at which the key/value pair
 * should be stored in the array of the hash table
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int x, new_idx;

	if (size <= 0)
		return (0);

	x = hash_djb2(key);
	new_idx = x % size;

	return (new_idx);
}
