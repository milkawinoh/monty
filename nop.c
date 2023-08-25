#include "monty.h"

/**
 * nop - No operation, does nothing.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the Monty file being executed.
 *
 * Return: Pointer to the top of the stack (unchanged).
 */

stack_t *nop(stack_t **stack, int line_number)
{
	(void)stack;
	(void)line_number;
	return (*stack);

}
