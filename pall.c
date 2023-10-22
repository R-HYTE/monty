#include "monty.h"

/**
 * _pall - prints the stack
 * @stack: pointer to the pointer to the stack
 * @line_number: current line number in the file being read
 * Return: Void
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;
	(void)line_number;

	curr = *stack;
	if (curr == NULL)
		return;
	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
