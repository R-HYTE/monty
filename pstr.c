#include "monty.h"

/**
 * _pstr - Prints the string starting at the top of the stack
 * @stack: pointer to the pointer to the head of the stack
 * @line_number: current line number in the file being read
 * Return: Void
*/
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;
	(void)line_number;

	curr = *stack;
	while (curr)
	{
		if (curr->n > 127 || curr->n <= 0)
		{
			break;
		}
		printf("%c", curr->n);
		curr = curr->next;
	}
	printf("\n");
}
