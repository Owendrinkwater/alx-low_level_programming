#include "lists.h"

/**
 * listint_len - returns the number of elements in a listint_t list.
 *
 * @h: a pointer to the head of the listint_t list.
 *
 * Return: the number of elements in the listint_t list.
 */

size_t listint_len(const listint_h *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}
