#include "monty.h"

/**
 * pall - Prints all the values on the stack
 * @stack: Stack
 * @line_number: line number
 *
 * Return: Nothing
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	(void)line_number;
}
