#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 * @stack: stack
 * @line_number: number of the line
 *
 * Return: Nothing
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last, *second_last;
	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		last = *stack;
		second_last = *stack;
		while (last->next != NULL)
		{
			second_last = last;
			last = last->next;
		}
		last->next = *stack;
		(*stack)->prev = last;
		second_last->next = NULL;
		last->prev = NULL;
		*stack = last;
	}
}
