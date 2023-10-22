#include "monty.h"

/**
 * free_stack - Frees a doubly linked list
 * @head: pointer to the list
 * Return: void
 */
void free_stack(stack_t *head)
{
	stack_t *tmp;

	tmp = head;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
