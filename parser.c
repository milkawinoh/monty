#include "monty.h"
/**
 * parser - Parses and executes Monty bytecode from a file.
 * @file_line: Buffer for reading lines from the file.
 * @len_fileOptcodes: Length of the file_line buffer.
 * @fileptr: Pointer to the Monty bytecode file.
 * @line_number: Current line number being processed.
 *
 * This function reads lines from the Monty bytecode file, tokenizes them,
 * and executes the corresponding opcode functions.
 */
static stack_t *stack;
void parser(char *file_line, size_t len_fileOptcodes,
FILE *fileptr, unsigned int line_number)
{
	ssize_t bytes_read;
	char *tokenized_optcode;
	int optcode_value;

	while ((bytes_read = getline(&file_line, &len_fileOptcodes,
	fileptr) != -1))
	{
		line_number++;
		if ((bytes_read == -1 || strlen(file_line)) == 0)
		{
			continue;
		}
		tokenized_optcode = strtok(file_line, "\t\n$ ");
		if (strcmp(tokenized_optcode, "push") == 0)
		{
			tokenized_optcode = strtok(NULL, "\t\n$ ");
			optcode_value = atoi(tokenized_optcode);
			push(&stack, optcode_value);
			continue;
		}
		else if (strcmp(tokenized_optcode, "pall") == 0)
		{
			pall(stack);
			continue;
		}
		else if (strcmp(tokenized_optcode, "pint") == 0)
		{
			pint(&stack, line_number);
		}
		else if (strcmp(tokenized_optcode, "pop") == 0)
		{
			pop(&stack, line_number);
		}
		else if (strcmp(tokenized_optcode, "swap") == 0)
		{
			swap(&stack, line_number);
		}
		else if (strcmp(tokenized_optcode, "add") == 0)
		{
			add(&stack, line_number);
		}
		else if (strcmp(tokenized_optcode, "nop") == 0)
		{
			nop(&stack, line_number);
		}
		else if (strcmp(tokenized_optcode, "sub") == 0)
		{
			sub(&stack, line_number);
		}
		else if (strcmp(tokenized_optcode, "div") == 0)
		{
			div_stack(&stack, line_number);
		}
		else if (strcmp(tokenized_optcode, "mul") == 0)
		{
		   mul(&stack, line_number);
		}
		else if (strcmp(tokenized_optcode, "mod") == 0)
		{
			mod_stack(&stack, line_number);
		}
		else if (strcmp(tokenized_optcode, "#") == 0)
		{
			nop(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n",
			line_number, tokenized_optcode);
			free(file_line);
			fclose(fileptr);
			exit(EXIT_FAILURE);
		}
	}
	free_stack(stack);
}

