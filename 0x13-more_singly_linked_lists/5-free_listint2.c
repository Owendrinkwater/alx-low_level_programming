#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - frees a linked list of integers and sets head to NULL.
 * @head: double pointer to head of the linked list.
 */

void free_listint2(listint_t **head)
{
	listint_t *tmp;

	if (head == NULL)
		return;

	while (*head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}
