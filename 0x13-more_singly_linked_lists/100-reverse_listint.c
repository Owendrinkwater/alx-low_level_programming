#include "lists.h"

/**
 * reverse_listint - reverses a linked list of integers
 * @head: pointer to the first node of the list
 * Return: pointer to the first node of the reversed list
 */

listint_t *reverse_listint(listtint_t **head)
{
	listint_t *prev = NULL, *next;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = next;
	}

	*head = prev;
	return (*head);
}
