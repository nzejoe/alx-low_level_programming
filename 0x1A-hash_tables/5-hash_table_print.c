#include "hash_tables.h"

/**
 * hash_table_print - function to print all elements of a hash table.
 * @ht: The hash table to be printed.
*/

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i = 0;
	hash_node_t *current;
	int first = 1;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		current = ht->array[i];
		while (current != NULL)
		{
			if (first)
				first = 0;
			else
				printf(", ");
			printf("'%s': '%s'", current->key, current->value);
			current = current->next;
		}
	}
	printf("}\n");
}
