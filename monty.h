#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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

void pall(stack_t *stack);
stack_t *push(stack_t **stack, int value);
stack_t *pop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, int line_number);
void parser(char *file_line, size_t len_fileOptcodes, FILE *fileptr, unsigned int line_number);
stack_t *swap(stack_t **stack, int line_number);
stack_t *add(stack_t **stack, int line_number);
stack_t *nop(stack_t **stack, int line_number);
void free_stack(stack_t *stack);
stack_t *sub(stack_t **stack, int line_number);
stack_t *div_stack(stack_t **stack, int line_number);
stack_t *mul(stack_t **stack, int line_number);
stack_t *mod_stack(stack_t **stack, int line_number);
#endif

