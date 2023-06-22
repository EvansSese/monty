#include "monty.h"

/**
 * push - Adds element on top of stack
 * @stack: Stack
 * @line_number: line number
 *
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
<<<<<<< HEAD
	new_node->n = line_number;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

=======

	new_node->n = line_number;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;
>>>>>>> dcc1e100b40f06a2304078c52c7a944f9edd0d9a
	*stack = new_node;
}
