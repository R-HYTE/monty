#include "monty.h"

/**
 * _pchar - Prints the char at the top of the stack
 * @stack: pointer to the pointer to the list
 * @line_number: Current line number in the file being read
 * Return: Void
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;

	curr = *stack;
	/* When stack is empty*/
	if (curr == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(pub.file);
		free(pub.string);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	/*Outside ASCII range*/
	if (curr->n > 127 || curr->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(pub.file);
		free(pub.string);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", curr->n);
}
