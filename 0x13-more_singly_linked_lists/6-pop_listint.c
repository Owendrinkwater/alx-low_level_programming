#include "lists.h"
/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: apointer to a pointer to the first node of the listint_t list
 *
 * Return - the data inside the elements that was deleted,
 * or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int n;

	if (head == NULL || *head == NULL)
		return (0);

	temp = *head;
	n = temp->n;
	*head = (*head)->next;
	free(temp);

	return (n);
}
