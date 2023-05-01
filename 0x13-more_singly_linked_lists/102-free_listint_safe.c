#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list.
 * @h: a pointer to the head of the listint_t list.
 *
 * Return: the size of the list that was free'd.
 */

size_t free_listint_safe(listint_t **h)
{
	size_t size = 0;
	listint_t *current, *next;

	if (h == NULL || *h == NULL)
		return (0);

	current = *h;
	while (current != NULL)
	{
		size++;
		next = current->next;
		free(current);
		if ((void *)next >= (void *)current)
		{
			*h = NULL;
			return (size);
		}
		current = next;
	}
	*h = NULL;
	return (size);
}
