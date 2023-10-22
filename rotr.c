#include "monty.h"

/**
 * _rotr - Rotates the stack to the right
 * @stack: Pointer to the pointer to the stack
 * @line_number: Current line number in the file being read (unused)
 */
void _rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *last;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	/* Find the last element in the stack. */
	last = *stack;

	while (last->next != NULL)
	{
		last = last->next;
	}

	/* Adjust the pointers for right rotation: */
	/* 1. Make the last element the new top of the stack. */
	/* 2. Update the previous and next pointers. */
	last->prev->next = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	last->prev = NULL;

	/* Update the top of the stack to the last element. */
	*stack = last;
}
