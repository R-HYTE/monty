#include "monty.h"

pub_t pub = {NULL, NULL, NULL, 0};

/**
 * main - The entry point of the stack-based script interpreter.
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 (Success)
 */
int main(int argc, char *argv[])
{
	stack_t *head = NULL;
	char *string;
	FILE *file;
	size_t size = 0;
	ssize_t char_read = 1;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	pub.file = file;
	while (char_read > 0)
	{
		string = NULL;
		char_read = getline(&string, &size, file);
		pub.string = string;
		line_number++;
		if (char_read > 0)
			execute(string, &head, line_number, file);
		free(string);
	}

	free_stack(head);
	fclose(file);
	return (0);
}
