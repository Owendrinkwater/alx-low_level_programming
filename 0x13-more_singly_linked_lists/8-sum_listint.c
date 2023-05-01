#include "lists.h"

/**
 * sum_listint - compute the sum of all the data (n) of listint_t linked list.
 * @head: a pointer to the head of the list.
 *
 * Return: the sum of all the data (n) of the list.
 */

int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *current = head;

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}
