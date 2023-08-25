#include "monty.h"
/**
 * main - Entry point for the Monty interpreter.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 */

int main(int argc, char **argv)
{
	FILE *fileptr;

	char *file_line = NULL;
	size_t len_fileOptcodes = 0;


	int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fileptr = fopen(argv[1], "r");
	if (fileptr == NULL)
	{
		fprintf(stderr, "Error: Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	parser(file_line, len_fileOptcodes, fileptr, line_number);


	free(file_line);
	fclose(fileptr);
	return (0);
}

