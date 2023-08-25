#include "monty.h"
/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the Monty file being executed.
 *
 * Return: Pointer to the new top of the stack after swapping.
 */

stack_t *swap(stack_t **stack, int line_number)
{
	int temp_value;
	stack_t *temp = (*stack);

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp_value = temp->n;
		temp->n = temp->next->n;
		temp->next->n = temp_value;
	}
	return (*stack);
}
