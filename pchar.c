#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @stack: stack
 * @line_number: number of the line
 *
 * Return: Nothing
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	int ascii_value = (*stack)->n;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!isascii(ascii_value))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar(ascii_value);
	putchar('\n');
}

