#include "lists.h"
/**
 * add_nodeint_end - adds new node at end of listint_t list
 * @head: a pointer to a pointer to the head of the listint_t list
 * @n: the integer to be added to the new node
 *
 * Return: if memory allocation fails or head is NULL, returns null
 * Otherwise, retruns the address of new node
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new, *node;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	node = *head;

	while (node->next != NULL)
		node = node->next;

	node->next = new;

	return (new);
}
