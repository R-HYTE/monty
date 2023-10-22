#include "monty.h"

/**
 * execute - executes a command based on line content in the file being read
 * @stack: pointer to the pointer to the stack
 * @line_number: current line number in the file being read
 * @file: file containing commands to read
 * @string: line from the file read
 * Return: 0 (Success), 1 (Failure)
 */
int execute(char *string, stack_t **stack, unsigned int line_number, FILE *file)
{
	unsigned int i = 0;
	char *op;
	instruction_t opst[] = {
		{"push", _push}, {"pall", _pall},
		{"pint", _pint}, {"pop", _pop},
		{"swap", _swap}, {"add", _add},
		{"nop", _nop}, {"sub", _sub},
		{"div", _div}, {"mul", _mul},
		{"mod", _mod}, {"pchar", _pchar},
		{"pstr", _pstr}, {"rotl", _rotl},
		{"rotr", _rotr}, {"stack", _stack},
		{"queue", _queue}, {"NULL", NULL},
	};

	op = strtok(string, " \t\n");
	if (op && op[0] == '#')
		return (0);

	pub.arg = strtok(NULL, " \t\n");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
		fclose(file);
		free(string);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
