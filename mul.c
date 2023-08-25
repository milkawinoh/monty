#include "monty.h"

/**
 * mul - multiplies the second top element of
 * the stack with the top element of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the Monty file being executed.
 *
 * Return: Pointer to the new top of the stack after addition.
 */

stack_t *mul(stack_t **stack, int line_number)
{
	int mul;
	stack_t *temp = (*stack);

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't MUL, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{

		mul = temp->n * temp->next->n;
		temp->next->n = mul;
		*stack = temp->next;
		temp->next->prev = NULL;
		free(temp);

	}
	return (*stack);
}

