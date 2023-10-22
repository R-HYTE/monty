#include "monty.h"

/**
 * _enqueue - Enqueues (adds) an element to the queue.
 * @queue: pointer to the pointer to the head of the queue
 * @n: Integer value to be enqueued
 * Return: Void
 */
void _enqueue(stack_t **queue, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	/*Check for memory allocation error*/
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (*queue == NULL)
	{
		new_node->prev = NULL;
		*queue = new_node; /* Set the head of the queue to the new node */
	}
	else
	{
		stack_t *current = *queue;

		while (current->next != NULL)
			current = current->next;

		current->next = new_node;
		new_node->prev = current;
	}
}
