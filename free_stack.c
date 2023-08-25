#include "monty.h"
/**
 * free_stack - Frees all nodes in a stack.
 * @stack: Pointer to the top of the stack.
 *
 * Description: Frees all nodes in the stack and releases memory.
 */
void free_stack(stack_t *stack)
{
	stack_t *temp = NULL;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);

	}
}
