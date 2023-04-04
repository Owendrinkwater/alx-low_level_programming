#include "lists.h"
/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list
 * @head: pointer to the head of the linked list
 * @index: index of the node to be returned
 *
 * Return: if the node exists, return a pointer to the nth node,
 *		otherwise returns NULL.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *current = head;
	unsigned int i = 0;

	while (current != NULL && i < index)
	{
		current = current->next;
		i++;
	}

	return (current);
}
