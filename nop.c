#include "monty.h"

/**
 * _nop - opcode nop doesn’t do anything
 * @stack: pointer to the pointer to the head
 * @line_number: current line number in the file being read
 * Return: Void
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}
