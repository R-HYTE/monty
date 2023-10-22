#include "monty.h"

/**
 * _pint -  prints the value at the top of the stack
 * @stack: pointer to the pointer to the list
 * @line_number: current line number in the file being read
 * Return: Void
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(pub.file);
		free(pub.string);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
