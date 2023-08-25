#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the Monty file being executed.
 *
 * Return: Pointer to the new top of the stack after addition.
 */

stack_t *add(stack_t **stack, int line_number)
{
	int sum;
	stack_t *temp = (*stack);

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{

		sum = temp->n + temp->next->n;
		temp->next->n = sum;
		*stack = temp->next;
		temp->next->prev = NULL;
		free(temp);

	}
	return (*stack);
}
