#include "monty.h"

/**
 * div_stack - divides the second top element
 *  of the stack by the top element of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the Monty file being executed.
 *
 * Return: Pointer to the new top of the stack after addition.
 */

stack_t *div_stack(stack_t **stack, int line_number)
{
	int div;
	stack_t *temp = (*stack);

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (temp->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		else
		{
			div = temp->next->n / temp->n;
			temp->next->n = div;
			*stack = temp->next;
			temp->next->prev = NULL;
			free(temp);
		}
	}
	return (*stack);
}

