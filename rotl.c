#include "monty.h"

/**
 * _rotl - Rotates the stack to the left
 * @stack: pointer to the pointer to the stack
 * @line_number: Current line in the file being read
 * Return: Void
 */
void _rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *curr = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	curr = *stack;

	while (curr->next != NULL)
	{
		curr = curr->next;
	}

	/* Adjust the pointers for left rotation:*/
	/* 1. Make the second element the new top of the stack.*/
	/* 2. Update the previous and next pointer.*/
	curr->next = *stack;
	(*stack)->prev = curr;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	curr->next->next = NULL;
}
