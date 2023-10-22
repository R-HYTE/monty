#include "monty.h"

/**
 * _push - Adds a node to a stack
 * @stack: pointer to the pointer to the stack
 * @line_number: Current line number in the file
 * Return: void
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int value, pos = 0;
	int flag = 0;

	if (pub.arg)
	{
		/* Is it a valid "integer" by checking digit by digit */
		if (pub.arg[0] == '-')
			pos++;
		for (; pub.arg[pos] != '\0'; pos++)
		{
			if (pub.arg[pos] < '0' || pub.arg[pos] > '9')
				flag = 1; /*Flag if not a valid "digit"*/
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(pub.file);
			free(pub.string);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(pub.file);
		free(pub.string);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	value = atoi(pub.arg);
	if (pub.ads_flag == 0)
		add_to_stack(stack, value);
	else
		_enqueue(stack, value);
}
