#include "monty.h"

/**
 * _swap - interchanges the values of the top 2 elements
 * @stack: pointer to the pointer to the staack
 * @line_number: Current line number in the file being read
 * Return: Void
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;
	int len = 0, value;

	curr = *stack;
	while (curr)
	{
		curr = curr->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(pub.file);
		free(pub.string);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	curr = *stack;
	value = curr->n;
	curr->n = curr->next->n;
	curr->next->n = value;
}
