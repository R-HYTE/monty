#include "monty.h"

/**
 * add_to_stack - Adds a node to the stack
 * @stack: pointer to the pointer to the head of the stack
 * @n: Value being stored in the node
 * Return: Void
 */
void add_to_stack(stack_t **stack, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}
