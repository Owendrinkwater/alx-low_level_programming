#include "lists.h"
/**
 * add_nodeint - adds anew node at the begining of a listint_t list
 * @head: pointer to the pointer to the first node of the list
 * @n: integer value to store in the new node
 *
 * Return: address of new element
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->n = n;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
