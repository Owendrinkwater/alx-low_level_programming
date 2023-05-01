#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to the head of the list
 *
 * Return: the number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *p = head, *q = head;

	while (p)
	{
		printf("[%p] %d\n", (void *)p, p->n);
		count++;
		p = p->next;

		if (p >= q)
		{
			printf("-> [%p] %d\n", (void *)p, p->n);
			break;
		}

		q = q->next ? q->next->next : q->next;
	}

	return (count);
}
