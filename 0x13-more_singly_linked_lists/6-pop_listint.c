#include "lists.h"

/**
 * pop_listint - deletes the head of a listint_t linked list.
 * @head: a pointer to a pointer to the first node of the list.
 *
 * Return: the value of the head node's data (n).
 */

int pop_listint(listint_t **head)
{
	listint_t *temp;
	int n;

	if (head == NULL || *head == NULL)
		return (0);

	temp = *head;
	*head = (*head)->next;
	n = temp->n;
	free(temp);

	return (n);
}
