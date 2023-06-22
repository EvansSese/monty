#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: stack
 * @line_number: number of the line
 *
 * Return: Nothing
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL && current->n != 0 && isascii(current->n))
	{
		putchar(current->n);
		current = current->next;
	}
	putchar('\n');
	(void)line_number;
}
