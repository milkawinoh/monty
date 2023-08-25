#include "monty.h"

/**
 * mod_stack - divides the second top element
 *  of the stack by the top element of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the Monty file being executed.
 *
 * Return: Pointer to the new top of the stack after addition.
 */

stack_t *mod_stack(stack_t **stack, int line_number)
{
	int mod;
	stack_t *temp = (*stack);

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
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
			mod = temp->next->n % temp->n;
			temp->next->n = mod;
			*stack = temp->next;
			temp->next->prev = NULL;
			free(temp);
		}
	}
	return (*stack);
}

