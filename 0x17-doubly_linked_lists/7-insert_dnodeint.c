#include "lists.h"

/**
 * insert_node - insert node at given index
 * @temp: ptr to nth position node in doubly linked list
 * @n: node data
 * Return: address of inserted node
 */

dlistint_t *insert_node(dlistint_t *temp, int n)
{
	dlistint_t *new_node;

	new_node = malloc(sizeof(struct dlistint_s));
	if (!new_node)
		return (NULL);
	new_node->n = n;

	new_node->next = temp;
	new_node->prev = temp->prev;
	temp->prev->next = new_node;
	temp->prev = new_node;

	return (new_node);
}

/**
 * insert_dnodeint_at_index - create and insert node at nth index
 * @h: pointer to head of list
 * @idx: index
 * @n: node data
 * Return: address of inserted node, or NULL if failed
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *tmp;

	/* insert at beginning if empty or existing linked list */
	if (idx == 0)
		return (add_dnodeint(h, n));
	if (!h)
		return (NULL);

	/* insert in the middle of list */
	tmp = *h;
	while ((idx != 0) && (tmp->next))
	{
		idx -= 1;
		tmp = tmp->next;
		if (idx == 0)
			return (insert_node(tmp, n));
	}

	/* insert at the end of list if idx is one after last node */
	if (idx == 1)
		return (add_dnodeint_end(h, n));
	return (NULL);
}

