#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: stack
 * @line_number: number of the line
 *
 * Return: Nothing
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
		if (*stack != NULL)
			(*stack)->prev = NULL;
	free(temp);
}
