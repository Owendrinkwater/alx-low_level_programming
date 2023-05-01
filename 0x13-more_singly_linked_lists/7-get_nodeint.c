#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linkes list.
 * @head: pointer to the head of the list.
 * @index: index of the node to be returned.
 *
 * Return: pointer to the nth node of the list.
 *	NULL if the node does not exist.
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *current = head;
	unsigned int i;

	for (i = 0; current != NULL && i < index; i++)
		current = current->next;

	return (current);
}
