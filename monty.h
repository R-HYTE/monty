#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct pub_s - pool of variables that cut across source files
 * @string: pointer to a string
 * @file: pointer to a FILE structure used for i/o operations
 * @arg: pointer to a string
 * @ADS_flag: integer representing flag change between stack and queue
 * Description: pubicize data
 */
typedef struct pub_s
{
	char *string;
	FILE *file;
	char *arg;
	int ads_flag;
}  pub_t;
extern pub_t pub; /*declaration of public pool of variables*/

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size); */
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void _push(stack_t **stack, unsigned int number);
void _pall(stack_t **stack, unsigned int number);
void _pint(stack_t **stack, unsigned int number);
int execute(char *string, stack_t **stack, unsigned int line_number, FILE *file);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);

/*Mathematical functions*/
void _mod(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);

void _nop(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number);
void _rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number);

/*Adding to stack or queue*/
void add_to_stack(stack_t **stack, int n);
void _enqueue(stack_t **queue, int n);

/*Setting a flag to determine in stack or queue*/
void _queue(stack_t **stack, unsigned int line_number);
void _stack(stack_t **stack, unsigned int line_number);

/*Free a stack*/
void free_stack(stack_t *stack);

#endif