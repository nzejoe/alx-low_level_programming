#include "lists.h"
/**
 * get_dnodeint_at_index - get a node at a specific index
 * @head: a node of a list
 * @index: given index of node
 * Return: the nth node of a list, NULL if it doesn't exist
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *temp;
	unsigned int x;

	x = 0;

	temp = head;

	while (temp != NULL && x < index)
	{
		temp = temp->next;
		x++;
	}
	if (temp == NULL)
	{
		return (NULL);
	}

	return (temp);
}

