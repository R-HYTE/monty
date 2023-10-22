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
	char *string = (char *)malloc(256);
	FILE *file;
	size_t size = 0;
	/*ssize_t char_read = 1;*/
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	pub.file = file;

	while (fgets(string, size, file) != NULL)
	{
		size_t length = strlen(string);

		if (string[length - 1] == '\n')
		{
			/* Remove the newline character at the end of the line. */
			string[length - 1] = '\0';
		}

		pub.string = string;
		line_number++;
		execute(string, &head, line_number, file);
	}

	free_stack(head);
	fclose(file);
	return (0);
}
