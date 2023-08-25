#include "monty.h"

/**
 * push - Pushes a value onto the stack.
 * @stack: A pointer to the top of the stack.
 * @value: The value to push onto the stack
 * Return: None
 *
 * Description: This function adds a new node containing the given value
 * to the top of the stack. It updates the stack pointer accordingly.
 */
stack_t *push(stack_t **stack, int value)
{
	stack_t *newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newnode->n = value;
	newnode->next = *stack;
	newnode->prev = NULL;

	if (*stack != NULL)
	{
		(*stack)->prev = newnode;
	}

	*stack = newnode;
	return (*stack);
}

