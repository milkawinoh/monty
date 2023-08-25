#include "monty.h"
/**
 * pop - Removes the top element from the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the Monty file being executed.
 *
 * Return: Pointer to the new top of the stack after removal.
 */

stack_t *pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack);

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}
	else
	{

		*stack = NULL;
		free(temp);
	}
	return (*stack);

}
