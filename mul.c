#include "monty.h"

/**
 * _mul - Multiply the top two elements of a stack.
 * @stack: A pointer to a pointer to the top of the stack.
 * @line_number: Current line number of the file being being read
 * Return: Void
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	/*Navigate the stack*/
	stack_t *curr;
	int len = 0, result;

	curr = *stack;
	while (curr)
	{
		/*Find the length of the stack*/
		curr = curr->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(pub.file);
		free(pub.string);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	curr = *stack;
	result = curr->next->n * curr->n;
	curr->next->n = result;
	*stack = curr->next;
	free(curr);
}