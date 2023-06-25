#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: stack
 * @line_number: number of the line
 *
 * Return: Nothing
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;
	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		top = *stack;
		second = (*stack)->next;
		while (top->next != NULL)
			top = top->next;
		top->next = *stack;
		(*stack)->prev = top;
		(*stack)->next = NULL;
		*stack = second;
		second->prev = NULL;
	}
}
