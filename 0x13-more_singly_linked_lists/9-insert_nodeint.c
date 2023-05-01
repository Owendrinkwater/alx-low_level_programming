#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position.
 * @head: a pointer to the head of the listint_t list.
 * @idx: the index of the list where the new node should be added.
 * @n: the integer to be stored in the new node
 *
 * Return: if the function fails - NULL.
 *		otherwise - the address of the new node.
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *temp = *head;
	unsigned int node_idx = 0;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	while (temp)
	{
		if (node_idx == idx - 1)
		{
			new_node->next = temp->next;
			temp->next = new_node;
			return (new_node);
		}

		temp = temp->next;
		node_idx++;
	}

	free(new_node);
	return (NULL);
}
