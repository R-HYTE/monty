#include "monty.h"

/**
 * _pop - frees the node at the top of the stack
 * @stack: pointer to a pointer to the stack
 * @line_number: current line number in the file being read
 * Return: Void
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(pub.file);
		free(pub.string);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	curr = *stack;
	*stack = curr->next;
	free(curr);
}
