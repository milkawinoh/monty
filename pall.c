#include "monty.h"

/**
 * pall - Prints all elements of the stack.
 * @stack: A pointer to a pointer to the top of the stack.
 *
 * Description: This function prints all the integer values in the stack,
 * starting from the top of the stack. Each value is printed on a new line.
 * If the stack is empty, the function exits with failure status.
 */


void pall(stack_t *stack)
{
	if (stack == NULL)
	{
		return;
	}

	while (stack != NULL)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}

}
